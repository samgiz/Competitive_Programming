# from fractions import Fraction as frac
# from collections import Counter
# def solution(N, snakes, ladders):
#     snakes.sort(key=lambda x: x[1], reverse = True)
#     ladders.sort(reverse=True)
#     M = [i for i in range(N+6)]
#     for i in range(6):
#         M[N+i] = N-1
#     for i,j in snakes:
#         M[i] = j
#     for i,j in ladders:
#         M[i] = j
#     ans = [1 for i in range(N)]
#     ans[N-1] = 0
#     # Default multiplier is 1
#     mult = [1 for i in range(N)]
#     c = [Counter() for i in range(N)]
#     for i in range(N-1, -1, -1):
#         if M[i] != i:
#             continue
#         for j in range(6):
#             if M[i+j+1] < i:
#                 continue
#             ans[i] += ans[M[i+j+1]]
#         ans[i] /= 6
#         ans[i] *= mult[i]
#     print(float(ans[0]))
#     return int(ans[0])

# def mult(m1, m2):
#     for i in range(7):
#         for j in range(m2)

# def prep(dp):
#     matrix = [[1/6, 1/6, 1/6, 1/6, 1/6, 1/6, 1],
#               [  1,   0,   0,   0,   0,   0, 0],
#               [  0,   1,   0,   0,   0,   0, 0],
#               [  0,   0,   1,   0,   0,   0, 0],
#               [  0,   0,   0,   1,   0,   0, 0],
#               [  0,   0,   0,   0,   1,   0, 0],
#               [  0,   0,   0,   0,   0,   0, 1]]
#     dp[0] = matrix
#     for i in range(20):
#         matrix = times(matrix, matrix)

from collections import Counter
def solution(N, snakes, ladders):
    # snakes.sort(key=lambda x: x[1], reverse = True)
    # ladders.sort(reverse=True)
    M = [i for i in range(N+6)]
    for i in range(6):
        M[N+i] = N-1
    for i,j in snakes:
        M[i] = j
    for i,j in ladders:
        M[i] = j
    ans = [Counter() for i in range(N)]
    for i,j in snakes:
        ans[j][j] = 1
    snake_ends = set([i[1] for i in snakes])
    ladder_ends = [i[1] for i in ladders]
    for i in range(N-2, -1, -1):
        if M[i] != i:
            continue
        counter = Counter()
        for j in range(6):
            counter += ans[M[i+j+1]]
        for k in counter.keys():
            counter[k] /= 6
        counter[-1] += 1
        if i in snake_ends:
            d = 1 - counter[i]
            del counter[i]
            for k in counter.keys():
                counter[k] /= d
            for j in range(5):
                m = M[i+1+j]
                if ans[m][i] > 0:
                    am = ans[m][i]
                    del ans[m][i]
                    for k in counter.keys():
                        ans[m][k] += counter[k]*am
            for m in ladder_ends:
                if ans[m][i] > 0:
                    am = ans[m][i]
                    del ans[m][i]
                    for k in counter.keys():
                        ans[m][k] += counter[k]*am
        ans[i] = counter
    return int(ans[0][-1])

print(solution(200, [(101, 1), (102, 2), (103, 3), (104, 4), (105, 5), (107, 7), (108, 8), (109, 9), (110, 10), (111, 11), (113, 13), (114, 14), (115, 15), (116, 16), (117, 17), (119, 19), (120, 20), (121, 21), (122, 22), (123, 23), (125, 25), (126, 26), (127, 27), (128, 28), (129, 29)], [(99, 100)]))