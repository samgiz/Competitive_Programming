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





# from collections import Counter
# def solution(N, snakes, ladders):
#     # snakes.sort(key=lambda x: x[1], reverse = True)
#     # ladders.sort(reverse=True)
#     M = [i for i in range(N+6)]
#     for i in range(6):
#         M[N+i] = N-1
#     for i,j in snakes:
#         M[i] = j
#     for i,j in ladders:
#         M[i] = j
#     ans = [Counter() for i in range(N)]
#     for i,j in snakes:
#         ans[j][j] = 1
#     snake_ends = set([i[1] for i in snakes])
#     ladder_ends = [i[1] for i in ladders]
#     for i in range(N-2, -1, -1):
#         if M[i] != i:
#             continue
#         counter = Counter()
#         for j in range(6):
#             counter += ans[M[i+j+1]]
#         for k in counter.keys():
#             counter[k] /= 6
#         counter[-1] += 1
#         if i in snake_ends:
#             d = 1 - counter[i]
#             del counter[i]
#             for k in counter.keys():
#                 counter[k] /= d
#             for j in range(5):
#                 m = M[i+1+j]
#                 if ans[m][i] > 0:
#                     am = ans[m][i]
#                     del ans[m][i]
#                     for k in counter.keys():
#                         ans[m][k] += counter[k]*am
#             for m in ladder_ends:
#                 if ans[m][i] > 0:
#                     am = ans[m][i]
#                     del ans[m][i]
#                     for k in counter.keys():
#                         ans[m][k] += counter[k]*am
#         ans[i] = counter
#     return int(ans[0][-1])

# def multmm(m1, m2):
#     return [[sum([m1[i][k] * m2[k][j] for k in range(7)]) for j in range(7)] for i in range(7)]
# def multmc(m, c, rows=6): # TODO
#     ans = [Counter() for i in range(rows)]
#     # ans[-1][-1] = 1
#     for i in range(rows):
#         for j in range(7):
#             if m[i][j] == 0:
#                 continue
#             if m[i][j] == 1:
#                 ans[i] += c[j]
#                 continue
#             # Muliply m[i][j] * c[j], add to ans[i]
#             for k in c[j].keys():
#                 ans[i][k] += m[i][j] * c[j][k]
#     return ans

from collections import Counter
def solution(N, snakes, ladders):
    # snakes.sort(key=lambda x: x[1], reverse = True)
    # ladders.sort(reverse=True)
    M = {i:j for i,j in snakes + ladders}
    snake_ends = [i[1] for i in snakes]
    ladder_ends = [i[1] for i in ladders]
    ans = {i:Counter() for i in snake_ends + ladder_ends}
    for i,j in snakes:
        ans[j][j] = 1
    encountered_ladder_ends = []
    snake_starts = [i[0] for i in snakes]
    ladder_starts = [i[0] for i in ladders]
    specials = sorted(snake_starts + ladder_ends + snake_ends + ladder_starts, reverse = True)
    specials.append(0)
    snake_ends = set(snake_ends)
    ladder_ends = set(ladder_ends)

    mm = N-1 - specials[0]
    for i in range(len(specials)-1):
        mm = max(mm, specials[i] - specials[i+1])
    kk = 0
    while (1<<kk) <= mm:
        kk += 1
    # for i in range(N-2, -1, -1):
    #     if M[i] != i:
    #         continue
    #     counter = Counter()
    #     for j in range(6):
    #         counter += ans[M[i+j+1]]
    #     for k in counter.keys():
    #         counter[k] /= 6
    #     counter[-1] += 1
    #     if i in snake_ends:
    #         d = 1 - counter[i]
    #         del counter[i]
    #         for k in counter.keys():
    #             counter[k] /= d
    #         for j in range(5):
    #             m = M[i+1+j]
    #             if ans[m][i] > 0:
    #                 am = ans[m][i]
    #                 del ans[m][i]
    #                 for k in counter.keys():
    #                     ans[m][k] += counter[k]*am
    #         for m in ladder_ends:
    #             if ans[m][i] > 0:
    #                 am = ans[m][i]
    #                 del ans[m][i]
    #                 for k in counter.keys():
    #                     ans[m][k] += counter[k]*am
    #     ans[i] = counter
    dp = [0 for i in range(kk)]
    cache = {}
    matrix = [[1/6, 1/6, 1/6, 1/6, 1/6, 1/6, 1],
              [  1,   0,   0,   0,   0,   0, 0],
              [  0,   1,   0,   0,   0,   0, 0],
              [  0,   0,   1,   0,   0,   0, 0],
              [  0,   0,   0,   1,   0,   0, 0],
              [  0,   0,   0,   0,   1,   0, 0],
              [  0,   0,   0,   0,   0,   0, 1]]
    dp[0] = matrix
    cache[1] = matrix
    for i in range(1, len(dp)):
        matrix = [[sum([matrix[ii][k] * matrix[k][j] for k in range(7)]) for j in range(7)] for ii in range(7)]
        dp[i] = matrix
        cache[1<<i] = matrix
    prev = N-1
    vec = [Counter() for i in range(7)]
    vec[6][-1] = 1
    one_counter = [vec[6]]
    for cur in specials:
        diff = prev - cur
        prev = cur
        m = 0
        if diff in cache:
            m = cache[diff]
        else:
            cum = 0
            for i in range(kk):
                if ((1 << i) & diff) > 0:
                    cum += (1 << i)
                    if cum in cache:
                        m = cache[cum]
                    else:
                        m = [[sum([m[ii][k] * dp[i][k][j] for k in range(7)]) for j in range(7)] for ii in range(7)]
                        cache[cum] = m
        new_vec = [Counter() for i in range(6)] + one_counter
        for i in range(6):
            new_vec_i = new_vec[i]
            m_i = m[i]
            for j in range(7):
                m_i_j = m[i][j]
                if m_i_j == 0:
                    continue
                elif m_i_j == 1:
                    new_vec_i += vec[j]
                    continue
                vec_j = vec[j]
                # Muliply m[i][j] * c[j], add to ans[i]
                for k in vec[j].keys():
                    new_vec_i[k] += m_i_j * vec_j[k]
        vec = new_vec
        # print(diff)
        # for ii in m:
        #     print(ii)
        # for ii in vec:
        #     print(ii)
        if cur in M:
            # This is a start, so just replace this with the end
            vec[0] = ans[M[cur]]
        elif cur in ladder_ends:
            # Simply store the value
            ans[cur] = vec[0]
            if len(ans[cur].keys()) > 1:
                encountered_ladder_ends.append(cur)
        elif cur in snake_ends:
            counter = vec[0]
            d = 1 - counter[cur]
            del counter[cur]
            for k in counter.keys():
                counter[k] /= d
            for j in range(1, 6):
                if vec[j][cur] > 0:
                    am = vec[j][cur]
                    del vec[j][cur]
                    for k in counter.keys():
                        vec[j][k] += counter[k]*am
            to_delete = 0
            for ii in range(len(encountered_ladder_ends)):
                m = encountered_ladder_ends[ii]
                if ans[m][cur] > 0:
                    am = ans[m][cur]
                    del ans[m][cur]
                    for k in counter.keys():
                        ans[m][k] += counter[k]*am
                    if len(ans[m].keys()) == 1:
                        to_delete = ii+1
            encountered_ladder_ends = encountered_ladder_ends[to_delete:]
    return int(vec[0][-1])

# print(solution(200, [(101, 1), (102, 2), (103, 3), (104, 4), (105, 5), (107, 7), (108, 8), (109, 9), (110, 10), (111, 11), (113, 13), (114, 14), (115, 15), (116, 16), (117, 17), (119, 19), (120, 20), (121, 21), (122, 22), (123, 23), (125, 25), (126, 26), (127, 27), (128, 28), (129, 29)], [(99, 100)]))
def generator():
    import random
    snakes = []
    ladders = []
    N = 100000
    random.seed(1003)
    used = set()
    for i in range(100):
        while True:
            a = random.randint(1, N-3)
            b = random.randint(a+1, N-2)
            if a in used or b in used:
                continue
            break
        used.add(a)
        used.add(b)
        ladders.append((a, b))
    for i in range(100):
        while True:
            a = random.randint(2, N-2)
            b = random.randint(1, a-1)
            if a in used or b in used:
                continue
            break
        used.add(a)
        used.add(b)
        snakes.append((a, b))
    print(solution(N, snakes, ladders))

generator()