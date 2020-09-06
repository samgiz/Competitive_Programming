from heapq import *
import sys
# The recursion depth can be up to around 100000
sys.setrecursionlimit(1000000)

# Initialize the heaps for each subtree when no wishes are granted so far
# The heap by default is a min heap, so we store -cost instead of cost to simulate a max heap on cost
def initialize_heaps(cur, cost, heaps, E):
    if not E[cur]:
        return -cost
    for i, cst in E[cur]:
        heaps[cur].append((initialize_heaps(i, cst, heaps, E), i, cst))
    heapify(heaps[cur])
    return heaps[cur][0][0] - cost

# Grant a single wish by giving it to the branch that currently takes the largest amount of time
def grant_a_wish(cur, cost, heaps):
    # The cost is already 0
    if not heaps[cur] or heaps[cur][0] == 0:
        return 0
    nc, nxt, ncost = heappop(heaps[cur])
    ans = grant_a_wish(nxt, ncost, heaps)
    heappush(heaps[cur], (ans, nxt, ncost))
    # We either apply the new wish to the root (in which case we pay just for the largest child subtree)
    # Or we apply the wish to the largest subtree, and still include the current root in the cost
    # Note that all values are negated to keep heaps min-heaps
    return max(nc, heaps[cur][0][0]-cost)


def solution(ts, w):
    # Trivial case
    if w >= len(ts):
        return 0
    # E[i] contains the children of i
    E = [[] for i in range(len(ts))]

    # heaps[i] stores (-cost_of_subtree_so_far, root_of_subtree, cost_of_root) for each child of i
    # It simulates a max priority queue for the time to complete the subtree of each child
    heaps = [[] for i in range(len(ts))]

    # Initialize the edges
    for i in range(1, len(ts)):
        p, c = ts[i]
        E[p].append((i, c))
    
    # Initialize the heaps
    initialize_heaps(0, ts[0][1], heaps, E)
    ans = 0
    # Grant wishes one by one, storing the time needed to complete all tasks after each grant
    for i in range(w):
        ans = -grant_a_wish(0, ts[0][1], heaps)
    return ans

print(solution([(-1, 685), (0, 560), (1, 193), (1, 724), (1, 755), (4, 600), (0, 601), (4, 315), (1, 487), (7, 88)], 2))