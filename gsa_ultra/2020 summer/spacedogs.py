from heapq import *
# The remaining unmerged spacedogs
remaining = {}
# The priority queue that orders spacedogs by their weight
h = []
class SpaceDog: # Note: equality of spacedogs is implemented in terms of their location
    i = 0
    def __init__(self, mass, location):
        global remaining
        global h
        # Initialize mass and location
        self.mass = mass
        self.location = location
        # Assign a unique index to the spacedog
        self.ind = SpaceDog.i
        SpaceDog.i += 1
        # Push the dog into heap and remaining elements
        remaining[self.ind] = self
        # Push the dog into the priority queue
        heappush(h, (self.mass, self.ind, self))
    # Used in answer
    def sum_location(self):
        return sum(self.location)
    # Merge self with spacedog2, creating a new spacedog, adding it to queue and tree, and removing from `remaining`
    def eat(self, spacedog2):
        global h
        # print(self.location, spacedog2.location)
        # print("spacedog", [(self.location[i] + spacedog2.location[i])//2 for i in range(len(self.location))])
        new_dog = SpaceDog(self.mass + spacedog2.mass, [(self.location[i] + spacedog2.location[i])//2 for i in range(len(self.location))])
        del remaining[self.ind]
        del remaining[spacedog2.ind]
        return new_dog
    # Calculate distance between 2 spacedogs
    def distance(self, spacedog2):
        return sum([(self.location[i] - spacedog2.location[i])**2 for i in range(len(self.location))])
    # This is a quick and dirty fix to me referring to spacedogs and the location that they represent interchangably :)
    def __getitem__(self, key):
        return self.location[key]
    def __len__(self):
        return len(self.location)
    def __eq__(self, other):
        return self.location == other.location

# The class that implements the kdtree
class Node:
    def __init__(self, values, axis=0):
        self.axis = axis
        if len(values) == 1: # this is a leaf node, just store its value
            self.right = None
            self.left = None
            self.value = values[0]
        elif len(values) == 2 and values[0] == values[1]: # this is a leaf node, after merging the 2 values
            # Note that these are guaranteed to be merged eventually
            self.value = values[0].eat(values[1])
        else: # this is not a leaf node, split the tree into 2
            self.split(values)

    # Split the values into the left and right subtrees
    def split(self, values):
        k = len(values[0])
        n = len(values)
        mid = (n-1) // 2
        # Not a leaf node, so no need for a value
        self.value = None
        while True: # This loop is for convenience to find the correct axis
            # Sort values according to the required axis
            values.sort(key=lambda x: x[self.axis])
            # If the values are equal for that axis, try a different axis
            if values[0][self.axis] == values[-1][self.axis]:
                self.axis = (self.axis + 1) % k
                continue
            # find a pivot value that would separate elements into strictly distinct groups
            piv = mid
            while piv < n-1 and values[piv][self.axis] == values[piv + 1][self.axis]:
                piv += 1
            if piv == n-1:
                piv = mid - 1
                while values[piv][self.axis] == values[piv+1][self.axis]:
                    piv -= 1 # This should never arrive below 0, as we know not all values are the same
            # print("pivot", [i.location for i in values], piv, mid, self.axis)
            # separate into up to (and including) piv, and from piv+1
            left_values = values[:piv+1]
            right_values = values[piv+1:]

            # Calculate new bound to be inbetween the 2 elements
            # Make sure that it is strictly between any 2 points, current or future
            new_bound = (values[piv+1][self.axis] + values[piv][self.axis]) / 2
            if new_bound - int(new_bound) < 0.2: # the bound is an integer; make it not an integer
                new_bound -= 0.5
            self.bound = new_bound

            # set up branches
            self.left = Node(left_values, (self.axis+1)%k)
            self.right = Node(right_values, (self.axis+1)%k)

            # Break out of loop / return
            return

    # Calculate distance from a point to the bounding box
    # All distances are squared
    def dist_to_point(self, point, box):
        k = len(point)
        ans = 0
        for i in range(k):
            if box[i] < point[i] < box[i+k]: # coordinate is inside box
                continue
            ans += min(abs(box[i]-point[i]), abs(box[i+k]-point[i]))**2
        return ans


    # Add a value to tree, in place
    def add(self, value, box):
        k = len(value)
        low = box[self.axis]
        high = box[self.axis + k]
        if self.value:
            if self.value == value:
                # print("merging not start")
                self.value = self.value.eat(value)
            else:
                self.split([self.value, value])
        elif self.bound > value[self.axis]:
            # Reduce the upper bound
            box[self.axis + k] = self.bound
            self.left.add(value, box)
            box[self.axis + k] = high
        else:
            box[self.axis] = self.bound
            self.right.add(value, box)
            box[self.axis] = low
    
    # Remove value from tree
    # Mostly in place, but the new tree is returned, should be newly saved
    def remove(self, value, box):
        k = len(value)
        low = box[self.axis]
        high = box[self.axis + k]
        if self.value: # this is the value to remove
            return None
        elif self.bound > value[self.axis]: # We need to search on the left
            box[self.axis + k] = self.bound
            self.left = self.left.remove(value, box)
            box[self.axis + k] = high
            if not self.left: # If the immediate child was removed, no need for this node anymore
                return self.right
        else: # We need to search on the left
            box[self.axis] = self.bound
            self.right = self.right.remove(value, box)
            box[self.axis] = low
            if not self.right: # If the immediate child was removed, no need for this node anymore
                return self.left
        return self
    
    # find nearest neighbour for a particular point
    def find_nearest(self, point, best_d, best_point, box):
        k = len(point)
        low = box[self.axis]
        high = box[self.axis + k]
        if self.value: # leaf node
            d = point.distance(self.value) # Distance between 2 spacedogs
            if d > best_d - 0.1 or d == 0:
                return best_point, best_d
            else:
                return self.value, d
        if self.dist_to_point(point, box) > best_d - 0.1: # no way of finding a better point in this box
            return best_point, best_d
        if self.bound > point[self.axis]: # first check left, as closer points are located there
            box[self.axis + k] = self.bound
            p, d = self.left.find_nearest(point, best_d, best_point, box)
            box[self.axis + k] = high
            if d < best_d:
                best_d = d
                best_point = p
            box[self.axis] = self.bound
            p, d = self.right.find_nearest(point, best_d, best_point, box)
            box[self.axis] = low
            if d < best_d:
                best_d = d
                best_point = p
        # same as above, just reveresed order of children
        else: # first check right, as closer points are located there
            box[self.axis] = self.bound
            p, d = self.right.find_nearest(point, best_d, best_point, box)
            box[self.axis] = low
            if d < best_d:
                best_d = d
                best_point = p
            box[self.axis + k] = self.bound
            p, d = self.left.find_nearest(point, best_d, best_point, box)
            box[self.axis + k] = high
            if d < best_d:
                best_d = d
                best_point = p
        return best_point, best_d
    # For debugging, prints out the whole subtree
    def print(self):
        if self.value:
            return str(self.value.location) + ' ' + str(self.value.mass)
        return '(' + self.left.print() + ', ' + self.right.print() + ")"

def solution(masses, locations):
    global remaining
    global h
    h = []
    remaining = {}
    locations = [list(i) for i in locations]
    dogs = [SpaceDog(masses[i], locations[i]) for i in range(len(masses))]
    k = len(locations[0])
    initial_box = [1e9 for i in range(k)] + [-1e9 for i in range(k)]
    # Define the initial box
    # This could honestly be done in a simpler way
    for i in locations:
        for j in range(k):
            initial_box[j] = min(initial_box[j], i[j]-0.5)
            initial_box[j+k] = max(initial_box[j+k], i[j]+0.5)
    # Initialize the kd-tree
    kd_tree = Node(dogs)
    # Create the priority queue
    heapify(h)
    # Merge spacedogs until only one is remaining
    while len(remaining) > 1:

        # Find smallest dog
        top = heappop(h)[2]
        if top.ind not in remaining: # Check whether this dog has eaten before, becoming a different dog
            continue

        # Find its closest neighbour
        p, d = kd_tree.find_nearest(top, 1e100, None, initial_box)
        # Merge the dogs
        new_dog = p.eat(top)

        # Do updates
        kd_tree = kd_tree.remove(top, initial_box)
        kd_tree = kd_tree.remove(p, initial_box)
        if kd_tree:
            kd_tree.add(new_dog, initial_box)
        else:
            kd_tree = Node([new_dog])
    # Return the required result for the one remaining element in the heap
    # The answer will always be the largest element in the heap
    return h[-1][2].sum_location()

# Used for debugging purposes
def solution_naive(masses, locations):
    # implement k-d tree
    # or just do a quadratic algorithm, that should work as well
    global remaining
    global h
    h = []
    remaining = {}
    locations = [list(i) for i in locations]
    dogs = [SpaceDog(masses[i], locations[i]) for i in range(len(masses))]
    k = len(locations[0])
    heapify(h)
    while len(remaining) > 1:
        # Find smallest dog
        # print("heap", h)
        top = heappop(h)[2]
        if top.ind not in remaining: # Check whether this dog has eaten before, becoming a different dog
            continue

        # Find its closest neighbour
        p, d = None, 1e9
        bad_example = False
        for i in remaining:
            if i == top.ind:
                continue
            td = top.distance(remaining[i])
            if abs(td-d) < 0.1:
                bad_example = True
            elif td < d:
                d = td
                p = remaining[i]
                bad_example = False
        if bad_example:
            return None
        # print("eating", p.location, top.location)
        new_dog = p.eat(top)
        # print("just eaten", p.location, top.location, new_dog.location)
        # print(p.ind, top.ind, new_dog.ind)
        # print(new_dog.ind)
        
    # Return the required result for the one remaining element in the heap
    # The answer will always be the largest element in the heap
    return h[-1][2].sum_location()


# Tests and the test generator go below

# print(solution([2, 5, 4], [(1, 4), (3, 1), (2, 6)]))

# print(solution([1, 1, 2, 4, 8, 128, 64, 32, 16], [(1,), (1,), (2,), (4,), (8,), (16,), (32,), (64,), (128,)]))
# print(solution([2, 2, 3, 3, 8, 128, 64, 32, 16], [(1, 2), (1, 2), (3, 3), (4, 3), (6, 4), (16, 2), (32, 3), (64, 2), (128, 1)]))
# print(solution([1, 2, 4, 8, 16, 32, 64, 128], [(1, 1), (2, 2), (4, 2), (8, 2), (16, 2), (32, 2), (64, 2), (128, 1)]))
# print(solution([32, 64, 1, 8, 2, 16, 256, 512, 128, 4], [[3, 6], [7, 1], [1, 1], [3, 10], [7, 3], [9, 5], [6, 6], [3, 3], [7, 3], [6, 9]]))
# print(solution([128, 512, 8, 4, 16, 256, 32, 64, 1, 2], [[7, 5], [2, 9], [4, 8], [1, 9], [8, 3], [1, 3], [6, 6], [4, 2], [10, 9], [7, 6]]))
# print(solution([1, 4, 2, 16, 8], [[4333, 7092], [1397, 95], [7758, 5460], [7121, 5328], [9202, 2383]]))
# print(solution_naive([1, 4, 2, 16, 8], [[4333, 7092], [1397, 95], [7758, 5460], [7121, 5328], [9202, 2383]]))
# # [1397, 95] 4, [5727, 6210] 17), ([9202, 2383] 8, [7758, 5460] 2
# print(solution([4, 17, 8, 2], [[1397, 95], [5727, 6210], [9202, 2383], [7758, 5460]]))
# print(solution([16, 8, 1, 2, 4], [[5, 4], [1, 5], [2, 4], [4, 1], [2, 3]]))
# print(solution_naive([16, 8, 1, 2, 4], [[5, 4], [1, 5], [2, 4], [4, 1], [2, 3]]))
# print(solution([4, 32, 8, 2, 1, 16], [[15, 12], [10, 16], [6, 5], [15, 4], [10, 1], [8, 20]]))
# print(solution_naive([4, 32, 8, 2, 1, 16], [[15, 12], [10, 16], [6, 5], [15, 4], [10, 1], [8, 20]]))
# print(solution([16, 8, 2, 1, 4, 32], [[3, 3], [1, 3], [6, 10], [5, 9], [7, 6], [4, 9]]))
# print(solution_naive([16, 8, 2, 1, 4, 32], [[3, 3], [1, 3], [6, 10], [5, 9], [7, 6], [4, 9]]))
import random
def generator():
    k = 2
    n = 20
    top_int = 100
    while True:
        locations = []
        masses = [(1<<i) for i in range(n)]
        random.shuffle(masses)
        for i in range(n):
            locations.append([random.randint(1, top_int) for i in range(k)])
        print("naive solution on locations", locations, ", masses", masses, ":")
        s1 = solution_naive(masses, locations)
        if s1 == None:
            print("Bad example")
            continue
        print(solution_naive(masses, locations))
        print("solution(", masses, ', ', locations, ')', sep='')
        s2 = solution(masses, locations)
        print(s2)
        if(s1 != s2):
            print("differing results")
            return
generator()