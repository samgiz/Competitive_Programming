# from collections import deque
# skip_amount = 10
# class Node:
#     def __init__(self, size, tp):
#         self.size = size
#         self.prev = None
#         self.next = None
#         self.next_skip = None
#         self.skip_max = self.size if tp == -1 else 0
#         self.type = tp
# def delete_node(node):
#     if node.next:
#         node.next.prev = node.prev
#     if node.prev:
#         node.prev.next = node.next
#     n = node.prev
#     ct = 0
#     while n and ct < skip_amount:
#         ct += 1
#         if n.next_skip and n.next_skip.type == -1:
#             n.skip_max = max(n.skip_max, n.next_skip.size)
#         if n.next_skip:
#             n.next_skip = n.next_skip.next
#         n = n.prev

# def update_node(node):
#     n = node
#     ct = 0
#     m = 0
#     while n and ct < skip_amount:
#         if n.type == -1:
#             m = max(m, n.size)
#         n = n.next
#         ct += 1
#     node.next_skip = n
#     node.skip_max = m

# def add_node_before(node, before):
#     before_size = before.size
#     # Update the size of the empty space we found
#     before.size -= node.size
#     # set up the neighbouring relationships
#     node.next = before
#     node.prev = before.prev
#     if before.prev:
#         before.prev.next = node
#     before.prev = node

#     ct = 0
#     n = before
#     while n and ct <= skip_amount:
#         update_node(n)
#         n = n.prev
#     # d = deque()
#     # n = before
#     # ct = 0
#     # while n and ct < skip_amount - 1:
#     #     ct += 1
#     #     if n.type == -1:
#     #         d.append(n.size)
#     #     else:
#     #         d.append(0)
#     #     n = n.next
#     # node.next_skip = n
#     # if n:
#     #     ct += 1
#     #     if n.type == -1:
#     #         d.append(n.size)
#     #     else:
#     #         d.append(0)
#     #     n = n.next
#     # if before.skip_max == before.size:
#     #     before.skip_max = max(d)
#     # node.next_skip = n
#     # ct = 0
#     # n = node
#     # while n and ct < skip_amount:
#     #     ct += 1
#     #     d.pop()
#     #     if n.type == -1:
#     #         d.append_left(n.size)
#     #     else:
#     #         d.append_left(0)
    
#     # # Update the skip to positions
#     # for i in range(ct):
# def update_max(node):
#     ct = 0
#     m = 0
#     n = node
#     while n and ct < skip_amount:
#         m = max(m, n.size)
#         n.skip_max = max(n.skip_max, m)
#         ct += 1
#         n = n.prev
# def solution(n, rs):
#     pos = {}
#     start = Node(n, -1) # initial empty space
#     cnt = 0
#     for t, val in rs:
#         # n = start
#         # while n:
#         #     print((n.size, n.type, n.skip_max), end=" ")
#         #     n = n.next
#         # print(t, val, start)
#         # print()
#         if t == 'I':
#             new_node = Node(val, cnt)
#             pos[cnt] = new_node
#             cnt += 1
            
#             # find where this is going to be inserted
#             n = start
#             # change the way we find this to use the skips
#             while n.skip_max < val:
#                 # print(n.skip_max, val)
#                 n = n.next_skip
#             while n.type != -1 or n.size < val:
#                 n = n.next
            
#             # insert the occupied space before the node we found
#             # TODO: need to do stuff here to update the skip sizes / where nodes actually skip to

#             # Update start node if we are inserting at the start
#             if n == start:
#                 start = new_node
#             # insert the node
#             add_node_before(new_node, n)

#             # new_node.next = n
#             # new_node.prev = n.prev

#             # if not n.prev:
#             #     start = new_node
#             # if n.prev:
#             #     n.prev.next = new_node
#             # n.prev = new_node

#             # Delete empty node if we have taken up the whole space
#             if n.size == 0:
#                 delete_node(n)
#         if t == 'O':
#             n = pos[val]
#             n.type = -1
#             if n.prev and n.prev.type == -1:
#                 if not n.prev.prev:
#                     start = n
#                 n.size += n.prev.size
#                 delete_node(n.prev)
#             if n.next and n.next.type == -1:
#                 if not n.prev:
#                     start = n.next
#                 n.next.size += n.size
#                 nxt = n.next
#                 delete_node(n)
#                 n = nxt
#             update_max(n)
#     cur_pos = 0
#     n = start
#     ans = 0
#     while n:
#         if n.type != -1:
#             # print(cur_pos, n.type)
#             ans += cur_pos * n.type
#         cur_pos += n.size
#         n = n.next
#     return ans
# print(solution(10, [('I', 3), ('I', 3), ('O', 0), ('I', 4), ('I', 2), ('O', 2), ('I', 2)]))
# print(solution(1000, [('I', 282), ('I', 317), ('O', 0), ('I', 375), ('I', 272), ('I', 7), ('O', 2), ('I', 251)]))

# print(solution(1000, [('I', 282), ('I', 317), ('O', 0), ('I', 375), ('I', 272), ('I', 7), ('O', 2), ('I', 251)]))








class NaiveNode:
    def __init__(self, size, tp):
        self.size = size
        self.prev = None
        self.next = None
        self.type = tp
def naive_solution(n, rs):
    pos = {}
    start = NaiveNode(n, -1) # initial empty space
    cnt = 0
    for t, val in rs:
        # n = start
        # while n:
        #     print(n.size, n.type)
        #     n = n.next
        # print()
        if t == 'I':
            new_node = NaiveNode(val, cnt)
            pos[cnt] = new_node
            cnt += 1
            
            # find where this is going to be inserted
            n = start
            while n and (n.type != -1 or n.size < val):
                n = n.next
            if not n: # For the generator to know when a test is bad
                return None
            # insert the occupied space before the node we found
            new_node.next = n
            new_node.prev = n.prev
            if not n.prev:
                start = new_node
            if n.prev:
                n.prev.next = new_node
            n.prev = new_node
            # Update the size of the empty space and delete it if necessary
            n.size -= val
            if n.size == 0:
                n.prev.next = n.next
                if n.next:
                    n.next.prev = n.prev
        if t == 'O':
            n = pos[val]
            n.type = -1
            if n.prev and n.prev.type == -1:
                n.prev.next = n.next
                if n.next:
                    n.next.prev = n.prev
                n.prev.size += n.size
                n = n.prev
            if n.next and n.next.type == -1:
                n.next.prev = n.prev
                if n.prev:
                    n.prev.next = n.next
                else:
                    start = n.next
                n.next.size += n.size
    cur_pos = 0
    n = start
    ans = 0
    while n:
        if n.type != -1:
            # print(cur_pos, n.type)
            ans += cur_pos * n.type
        cur_pos += n.size
        n = n.next
    return ans
# # print(solution(10, [('I', 3), ('I', 3), ('O', 0), ('I', 4), ('I', 2), ('O', 2), ('I', 2)]))


# pos[i] stores the node occupied by the ith group of people
pos = {}
root = None
# import sys

# Every node should have 0 children or 2 children
class Node:
    def __init__(self, size, tp=-1):
        self.size = size # size of cell in leaf node, max of sizes in intermediate node
        # self.pos = position # position of the space. Only relevant for leaf nodes
        self.prev = None # previous node in linked list
        self.next = None # next node in linked list
        self.par = None # parent in tree
        self.lc = None # left child in tree
        self.rc = None # right child in tree
        self.type = tp # -1 denotes empty or intermediate node, >= 0 denotes id of occupying family
        self.height = 0 # height used for AVL rotations

    # Update the max size based on the maximums of children
    def update(self):
        # Update height
        if not self.lc:
            self.height = 0
            return
        else:
            self.height = 1 + max(self.lc.height, self.rc.height)

        # Update size
        # Reset size and get maximum size from children
        sz = 0
        if self.lc.type == -1:
            sz = max(sz, self.lc.size)
        if self.rc.type == -1:
            sz = max(sz, self.rc.size)
        self.size = sz

    # Insert new node into tree
    def fill(self, size, i):
        global pos
        n = self
        while n.lc:
            if n.lc.size >= size and n.lc.type == -1:
                n = n.lc
            else:
                n = n.rc
        
        # global root
        if n.size == size: # Just use this node, as it exactly fits the required size
            n.type = i
            pos[i] = n # Keep track for when we're vacating
            # print("added !!!!!!!", self.pos, self.pos + self.size, self.type)
        else: # split node into 2, with the left being the occupied part
            # Set up the left and right subtrees
            n.lc = Node(size, i)
            n.rc = Node(n.size - size)

            pos[i] = n.lc # Keep track for when we'll be vacating
            
            n.lc.par = n
            n.lc.prev = n.prev
            n.lc.next = n.rc
            
            n.rc.par = n
            n.rc.prev = n.lc
            n.rc.next = n.next

            if n.prev:
                n.prev.next = n.lc
            if n.next:
                n.next.prev = n.rc
        # Rebalance the tree
        n.rebalance()
        
    
    def vacate(self):
        self.type = -1
        self_next = self.next
        self_prev = self.prev
        if self_next and self_next.type == -1:
            self.size += self_next.size
            self_next.size = 0
            if self_next.next:
                self_next.next.prev = self
            self.next = self_next.next
        if self_prev and self_prev.type == -1:
            self.size += self_prev.size
            self_prev.size = 0
            if self_prev.prev:
                self_prev.prev.next = self         
            self.prev = self_prev.prevy
            self_prev.delete()
            
            # print_list()
        if self_next and self_next.type == -1:
            self_next.delete()
        n = self.par
        # print("call updates from vacate")
        while n:
            n.update()
            n = n.par
    def delete(self):
        self.par.size = self.par.lc.size + self.par.rc.size
        if self.par.lc == self:
            # Update the type
            self.par.type = self.par.rc.type
            # update list structure
            self.par.prev = self.par.rc.prev
            if self.par.prev and not self.par.rc.lc: # make sure that the parent copied from a leaf
                self.par.prev.next = self.par
            self.par.next = self.par.rc.next
            if self.par.next and not self.par.rc.lc: # make sure that the parent copied from a leaf
                self.par.next.prev = self.par
            # remove children
            if self.par.rc.lc:
                self.par.rc.lc.par = self.par
            if self.par.rc.rc:
                self.par.rc.rc.par = self.par
            self.par.lc = self.par.rc.lc
            self.par.rc = self.par.rc.rc
            
        else: # mirror the if statement
            # print("right child")
            self.par.type = self.par.lc.type
            self.par.prev = self.par.lc.prev

            # update list structure
            self.par.prev = self.par.lc.prev
            if self.par.prev and not self.par.lc.lc: # make sure that the parent copied from a leaf
                self.par.prev.next = self.par
            self.par.next = self.par.lc.next
            if self.par.next and not self.par.lc.lc: # make sure that the parent copied from a leaf
                self.par.next.prev = self.par

            # set up new children
            if self.par.lc.lc:
                self.par.lc.lc.par = self.par
            if self.par.lc.rc:
                self.par.lc.rc.par = self.par
            self.par.rc = self.par.lc.rc
            self.par.lc = self.par.lc.lc
        # Update the pos dictionary if necessary
        if self.par.type != -1:
            global pos
            pos[self.par.type] = self.par
        # rebalance from parent
        # print("going to rebalance parent")
        # print_list()
        self.par.rebalance()
    def rebalance(self):
        n = self
        while n:
            n.update()
            if n.lc and abs(n.lc.height - n.rc.height) > 1: # needs rotating
                if n.lc.height > n.rc.height: # right rotate
                    if n.lc.lc.height < n.lc.rc.height:
                        n.lc.lrotate()                    
                    n.rrotate()
                else: # left rotate
                    if n.rc.rc.height < n.rc.lc.height:
                        n.rc.rrotate()
                    n.lrotate()

            n = n.par

    def lrotate(self):
        global root
        # if not in_tree(self, root):
        #     print("self not in root lrotate", self.pos, self.size)
        #     sys.exit()
        # if self.par and not in_tree(self.par, root):
        #     print("parent not in root lrotate", self.pos, self.size)
        #     sys.exit()
        # global root
        # print(print_tree(root))
        # print("lrotate", self.pos, self.size, self.type)
        # print("parent is in root", in_tree(self.par, root))
        # if self.par:
        #     print(self.par.pos, self.par.size)
        y = self.rc
        self.rc = y.lc
        if y.lc:
            y.lc.par = self
        y.par = self.par
        if not self.par:
            global root
            root = y
        elif self == self.par.lc:
            self.par.lc = y
        else:
            self.par.rc = y
        y.lc = self
        self.par = y
        self.update()
        y.update()
        # print("lrotate end", self.pos, self.size, self.type, y.pos, y.size, y.type)
        # print(print_tree(root))
    def rrotate(self):
        # global root
        # if not in_tree(self, root):
        #     print("self not in root rrotate", self.pos, self.size)
        #     sys.exit()
        # if self.par and not in_tree(self.par, root):
        #     print("parent not in root rrotate", self.pos, self.size)
        #     sys.exit()
        # global root
        # print(print_tree(root))
        # print("rrotate", self.pos, self.size, self.type)
        # print("rrotate", self.pos, self.size, self.type)
        
        y = self.lc
        # print("rrotate lc", y.pos, y.size, y.type)
        self.lc = y.rc
        if y.rc:
            y.rc.par = self
        y.par = self.par
        if not self.par:
            global root
            root = y
        elif self == self.par.rc:
            self.par.rc = y
        else:
            self.par.lc = y
        y.rc = self
        self.par = y
        self.update()
        y.update()
        # print(print_tree(root))

# def in_tree(node, tree):
#     if tree == None:
#         return False
#     return node == tree or in_tree(node, tree.lc) or in_tree(node, tree.rc)

# def print_tree(node):
#     if not node:
#         return ""
#     return '(' + str(node.pos) + ', ' + str(node.size) + ', ' + str(node.type) + ', [' + print_tree(node.lc) + ', ' + print_tree(node.rc) + ']'
# def print_list():
#     nodes = [root]
#     previous = None
#     while len(nodes) > 0:
#         top = nodes.pop()
#         # print(top.pos, top.size, top.type)
#         if not top.lc:
#             prev = str((top.prev.pos, top.prev.size, top.prev.type)) if top.prev else None
#             nxt = str((top.next.pos, top.next.size, top.next.type)) if top.next else None
#             print(prev, (top.pos, top.size, top.type), nxt)
#             if previous != top.prev or (previous and previous.next != top):
#                 print("previous not correct")
#                 sys.exit()
#             previous = top
#         if top.lc:
#             nodes.append(top.rc)
#             nodes.append(top.lc)

def solution(n, rs):
    global pos
    global root
    root = Node(n) # initial root of tree and start of the linked list
    cnt = 0
    for t, val in rs:
        if t == 'I':
            root.fill(val, cnt)
            # print(root.size)
            cnt += 1
        if t == 'O':
            to_vacate = pos[val]
            to_vacate.vacate()
        # nodes = [root]
        # while len(nodes) > 0:
        #     top = nodes.pop()
        #     # print(top.pos, top.size, top.type)
        #     # if top.lc and top.lc.type == 4:
        #     #     print("left", top.lc, top)
        #     # if top.rc and top.rc.type == 4:
        #     #     print("right", top.rc, top)
        #     # if top.lc and not top.lc.lc:
        #     #     print(top.type, top.lc.pos, top.lc.pos + top.lc.size, top.lc.type, top.rc.pos, top.rc.pos + top.rc.size, top.rc.type)
        #     if not top.lc:
        #         print(top.pos, top.pos + top.size, top.type)
        #     if top.lc:
        #         nodes.append(top.rc)
        #         nodes.append(top.lc)
        # # print(root.height)
        # print(print_tree(root))
        # print("printing list")
        # print_list()
        # print("end iteration")
    # Get answer here
    nodes = [root]
    ans = 0
    pos = 0
    while len(nodes) > 0:
        top = nodes.pop()
        # print(top.pos, top.size, top.type)
        if top.type != -1:
            # print(top.pos, top.pos + top.size, top.type)
            # print(pos, top.type)
            ans += pos * top.type
        if not top.lc:
            pos += top.size
        if top.lc:
            nodes.append(top.rc)
            nodes.append(top.lc)
    return ans

# print(solution(10, [('I', 3), ('I', 3), ('O', 0), ('I', 4), ('I', 2), ('O', 2), ('I', 2)]))
# print(solution(1000, [('I', 282), ('I', 317), ('O', 0), ('I', 375), ('I', 272), ('I', 7), ('O', 2), ('I', 251)]))
def generator():
    import random
    import sys
    n = 10000
    mint = 100
    q = 100
    while True:
        qs = []
        ct = 0
        to_replace = []
        for i in range(2*q):
            if i % 3 == 2:
                random.shuffle(to_replace)
                qs.append(('O', to_replace.pop()))
            else:
                to_replace.append(ct)
                ct += 1
                qs.append(('I', random.randint(1, mint)))
        for i in to_replace:
            qs.append(('O', i))
        print(n, qs)
        print("Naive solution: ")
        s1 = naive_solution(n, qs)
        if s1 == None:
            print("bad example")
            continue
        print("solution(", n, ", ", qs, ")", sep="")
        s2 = solution(n, qs)
        if s1 != s2:
            print("differing answers")
            sys.exit()
        




# generator()
# solution(10000, [('I', 49), ('I', 46), ('O', 0), ('I', 55), ('I', 34), ('O', 2), ('I', 51), ('I', 9), ('O', 4), ('I', 74), ('I', 32), ('O', 3), ('I', 11), ('I', 44), ('O', 5), ('I', 77), ('I', 3), ('O', 1), ('I', 61), ('I', 71), ('O', 8), ('I', 54), ('I', 99), ('O', 12), ('I', 81), ('I', 14), ('O', 17), ('I', 76), ('I', 98), ('O', 9), ('I', 38), ('I', 18), ('O', 7), ('I', 57), ('I', 48), ('O', 23), ('I', 5), ('I', 36), ('O', 22), ('I', 4), ('I', 51), ('O', 21), ('I', 1), ('I', 1), ('O', 14), ('I', 20), ('I', 37), ('O', 13), ('I', 10), ('I', 74), ('O', 20), ('I', 77), ('I', 49), ('O', 10), ('I', 79), ('I', 19), ('O', 16), ('I', 4), ('I', 75), ('O', 38), ('I', 27), ('I', 23), ('O', 40), ('I', 25), ('I', 50), ('O', 11), ('I', 2), ('I', 2), ('O', 27), ('I', 88), ('I', 75), ('O', 30), ('I', 92), ('I', 30), ('O', 36), ('I', 78), ('I', 24), ('O', 42), ('I', 85), ('I', 24), ('O', 39), ('I', 85), ('I', 11), ('O', 44), ('I', 99), ('I', 1), ('O', 34), ('I', 9), ('I', 34), ('O', 19), ('I', 94), ('I', 82), ('O', 48), ('I', 82), ('I', 32), ('O', 25), ('I', 90), ('I', 15), ('O', 51), ('I', 87), ('I', 6), ('O', 32), ('I', 59), ('I', 77), ('O', 29), ('I', 20), ('I', 93), ('O', 26), ('I', 51), ('I', 46), ('O', 65), ('I', 77), ('I', 74), ('O', 50), ('I', 67), ('I', 84), ('O', 69), ('I', 7), ('I', 43), ('O', 45), ('I', 28), ('I', 18), ('O', 76), ('I', 10), ('I', 82), ('O', 66), ('I', 48), ('I', 78), ('O', 81), ('I', 49), ('I', 85), ('O', 53), ('I', 84), ('I', 98), ('O', 64), ('I', 34), ('I', 61), ('O', 47), ('I', 75), ('I', 18), ('O', 75), ('I', 34), ('I', 50), ('O', 6), ('I', 39), ('I', 8), ('O', 33), ('I', 10), ('I', 100), ('O', 70), ('I', 94), ('I', 6), ('O', 79), ('I', 96), ('I', 43), ('O', 37), ('I', 11), ('I', 8), ('O', 55), ('I', 38), ('I', 77), ('O', 101), ('I', 48), ('I', 48), ('O', 24), ('I', 56), ('I', 25), ('O', 78), ('I', 82), ('I', 29), ('O', 113), ('I', 57), ('I', 72), ('O', 106), ('I', 40), ('I', 53), ('O', 67), ('I', 93), ('I', 89), ('O', 15), ('I', 92), ('I', 35), ('O', 58), ('I', 40), ('I', 31), ('O', 85), ('I', 45), ('I', 31), ('O', 49), ('I', 59), ('I', 28), ('O', 109), ('I', 28), ('I', 49), ('O', 117), ('I', 15), ('I', 47), ('O', 100), ('I', 40), ('I', 14)])
# solution(10000, [('I', 51), ('I', 50), ('O', 0), ('I', 13), ('I', 85), ('O', 1), ('I', 57), ('I', 16), ('O', 5), ('I', 78), ('I', 44), ('O', 3), ('I', 97), ('I', 75), ('O', 2), ('I', 80), ('I', 90), ('O', 6), ('I', 35), ('I', 76)])
# solution(100, [('I', 7), ('I', 1), ('O', 0), ('I', 9), ('I', 3), ('O', 2), ('I', 3), ('I', 5), ('O', 4), ('I', 8), ('I', 10), ('O', 1), ('I', 8), ('I', 5), ('O', 9), ('I', 5), ('I', 5), ('O', 6), ('I', 4), ('I', 7)])
# solution(100, [('I', 5), ('I', 10), ('O', 0), ('I', 7), ('I', 4), ('O', 1), ('I', 10), ('I', 1), ('O', 3), ('I', 5)])
# print(solution(100, [('I', 5), ('I', 8), ('O', 0), ('I', 2), ('I', 2), ('O', 1), ('I', 2)]))
# print(naive_solution(100, [('I', 5), ('I', 8), ('O', 0), ('I', 2), ('I', 2), ('O', 1), ('I', 2)]))
# print(solution(100, [('I', 9), ('I', 9), ('O', 1), ('I', 5), ('I', 1), ('O', 0), ('I', 4), ('I', 3), ('O', 5), ('I', 3)]))
# print(naive_solution(100, [('I', 9), ('I', 9), ('O', 1), ('I', 5), ('I', 1), ('O', 0), ('I', 4), ('I', 3), ('O', 5), ('I', 3)]))
# print(solution(100, [('I', 9), ('I', 2), ('O', 0), ('I', 8), ('I', 10), ('O', 1), ('I', 4), ('I', 7), ('O', 2), ('I', 6)]))
# print(naive_solution(100, [('I', 9), ('I', 2), ('O', 0), ('I', 8), ('I', 10), ('O', 1), ('I', 4), ('I', 7), ('O', 2), ('I', 6)]))
# print(solution(100, [('I', 8), ('I', 5), ('O', 0), ('I', 4), ('I', 1), ('O', 2), ('I', 10), ('I', 9), ('O', 5), ('I', 3), ('I', 3), ('O', 4), ('I', 3), ('I', 6), ('O', 8), ('I', 7), ('I', 6), ('O', 10), ('I', 6), ('I', 6)]))
# print(naive_solution(100, [('I', 8), ('I', 5), ('O', 0), ('I', 4), ('I', 1), ('O', 2), ('I', 10), ('I', 9), ('O', 5), ('I', 3), ('I', 3), ('O', 4), ('I', 3), ('I', 6), ('O', 8), ('I', 7), ('I', 6), ('O', 10), ('I', 6), ('I', 6)]))
# print(solution(100, [('I', 9), ('I', 1), ('O', 0), ('I', 2), ('I', 2), ('O', 2), ('I', 8), ('I', 7), ('O', 3), ('I', 5), ('I', 4), ('O', 7)]))
# print(naive_solution(100, [('I', 9), ('I', 1), ('O', 0), ('I', 2), ('I', 2), ('O', 2), ('I', 8), ('I', 7), ('O', 3), ('I', 5), ('I', 4), ('O', 7)]))
# print(solution(100, [('I', 7), ('I', 8), ('O', 0), ('I', 1), ('I', 4), ('O', 3), ('I', 8), ('I', 8), ('O', 2), ('I', 7), ('I', 3), ('O', 5)]))
# print(naive_solution(100, [('I', 7), ('I', 8), ('O', 0), ('I', 1), ('I', 4), ('O', 3), ('I', 8), ('I', 8), ('O', 2), ('I', 7), ('I', 3), ('O', 5)]))
# print(solution(100, [('I', 6), ('I', 7), ('O', 1), ('I', 1), ('I', 6), ('O', 0), ('I', 1), ('I', 10), ('O', 5), ('I', 6), ('I', 2), ('O', 2), ('I', 9), ('I', 10), ('O', 3), ('I', 9), ('I', 5), ('O', 7), ('I', 5), ('I', 2)]))
# print(naive_solution(100, [('I', 6), ('I', 7), ('O', 1), ('I', 1), ('I', 6), ('O', 0), ('I', 1), ('I', 10), ('O', 5), ('I', 6), ('I', 2), ('O', 2), ('I', 9), ('I', 10), ('O', 3), ('I', 9), ('I', 5), ('O', 7), ('I', 5), ('I', 2)]))
# print(solution(100, [('I', 3), ('I', 8), ('O', 1), ('I', 2), ('I', 6), ('O', 0), ('I', 7), ('I', 7), ('O', 2), ('I', 7), ('I', 9), ('O', 3), ('I', 2), ('I', 3)]))
# print(naive_solution(100, [('I', 3), ('I', 8), ('O', 1), ('I', 2), ('I', 6), ('O', 0), ('I', 7), ('I', 7), ('O', 2), ('I', 7), ('I', 9), ('O', 3), ('I', 2), ('I', 3)]))
# print(solution(100, [('I', 2), ('I', 4), ('O', 0), ('I', 5), ('I', 9), ('O', 3), ('I', 1), ('I', 1), ('O', 1), ('I', 9), ('I', 8), ('O', 2), ('I', 4), ('I', 9), ('O', 5), ('I', 7)]))
# print(naive_solution(100, [('I', 2), ('I', 4), ('O', 0), ('I', 5), ('I', 9), ('O', 3), ('I', 1), ('I', 1), ('O', 1), ('I', 9), ('I', 8), ('O', 2), ('I', 4), ('I', 9), ('O', 5), ('I', 7)]))
# print(solution(100, [('I', 3), ('I', 1), ('O', 1), ('I', 3), ('I', 9), ('O', 0), ('I', 2), ('I', 4), ('O', 5), ('I', 8), ('I', 8), ('O', 4), ('I', 3), ('I', 6), ('O', 9), ('I', 7), ('I', 4), ('O', 6), ('I', 5), ('I', 6), ('O', 13), ('I', 9), ('I', 1), ('O', 11), ('I', 8), ('I', 6), ('O', 15), ('I', 6), ('I', 5), ('O', 8), ('I', 7), ('I', 7), ('O', 7), ('I', 5), ('I', 9), ('O', 2), ('I', 1), ('I', 2), ('O', 23), ('I', 10)]))
# print(naive_solution(100, [('I', 3), ('I', 1), ('O', 1), ('I', 3), ('I', 9), ('O', 0), ('I', 2), ('I', 4), ('O', 5), ('I', 8), ('I', 8), ('O', 4), ('I', 3), ('I', 6), ('O', 9), ('I', 7), ('I', 4), ('O', 6), ('I', 5), ('I', 6), ('O', 13), ('I', 9), ('I', 1), ('O', 11), ('I', 8), ('I', 6), ('O', 15), ('I', 6), ('I', 5), ('O', 8), ('I', 7), ('I', 7), ('O', 7), ('I', 5), ('I', 9), ('O', 2), ('I', 1), ('I', 2), ('O', 23), ('I', 10)]))