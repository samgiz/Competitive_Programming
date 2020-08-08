from heapq import *
import sys
sys.setrecursionlimit(1000000)
def initialize_heaps(cur, cost, heaps, E):
    if not E[cur]:
        return -cost
    for i, cst in E[cur]:
        heaps[cur].append((initialize_heaps(i, cst, heaps, E), i, cst))
    heapify(heaps[cur])
    return heaps[cur][0][0] - cost
def do_a_thing(cur, cost, heaps):
    # print(cur, cost)
    if not heaps[cur] or heaps[cur][0] == 0:
        return 0
    nc, nxt, ncost = heappop(heaps[cur])
    ans = do_a_thing(nxt, ncost, heaps)
    heappush(heaps[cur], (ans, nxt, ncost))
    return max(nc, heaps[cur][0][0]-cost)


def solution(ts, w):
    # Trivial case
    if w >= len(ts):
        return 0
    E = [[] for i in range(len(ts))]
    # heaps stores (-cost_of_subtree, root_of_subtree)
    heaps = [[] for i in range(len(ts))]
    for i in range(1, len(ts)):
        p, c = ts[i]
        E[p].append((i, c))
    # E[i] contains the children of i
    initialize_heaps(0, ts[0][1], heaps, E)
    # print(heaps)
    ans = 0
    for i in range(w):
        ans = -do_a_thing(0, ts[0][1], heaps)
        # print(heaps)
        # print(ans)
    return ans

print(solution([(-1, 685), (0, 560), (1, 193), (1, 724), (1, 755), (4, 600), (0, 601), (4, 315), (1, 487), (7, 88)], 2))