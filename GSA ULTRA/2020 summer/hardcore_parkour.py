def solution(ps):
    LARGE = int(1e9)
    dp = {}
    for i in ps[0]:
        dp[i] = {5: 5}
    for i in range(1, len(ps)):
        p = sorted(j for j in ps[i])
        new_dp = {}
        dp_vals = sorted(dp.keys())
        start = 0
        for j in p:
            while start != len(dp_vals) and dp_vals[start] < j - 5:
                start += 1
            if start == len(dp_vals):
                break
            new_dp_j = {}
            cur = start
            while cur < len(dp_vals) and dp_vals[cur] <= j + 5:
                el = dp_vals[cur]
                d = dp[el]
                for speed in d:
                    cost = d[speed]
                    if abs(el - j) <= 5:
                        if el < j:
                            m = min(10, speed + 1)
                            new_dp_j[m] = min(new_dp_j.get(m, LARGE), cost + m)
                        elif el > j:
                            m = max(1, speed - 1)
                            new_dp_j[m] = min(new_dp_j.get(m, LARGE), cost + m)
                        else:
                            new_dp_j[speed] = min(new_dp_j.get(speed, LARGE), cost + speed)
                cur += 1
            # idea: prune out sctrictly worse speed values at the same location here
            m = LARGE
            for k, v in sorted(new_dp_j.items()):
                # print(i, j, k, v)
                if v >= m:
                    # print('deleting')
                    del new_dp_j[k]
                m = min(m, v)
            new_dp[j] = new_dp_j
        dp = new_dp
    # print(dp)
    ans = min([dp[i][j] for i in dp for j in dp[i]])
    return ans
# print(solution([(1, 4), (3, 8)]))
print(solution([(16, 18, 14), (19, 18, 17), (20, 17, 21), (20, 10, 19), (7, 4, 14), (11, 3, 4), (8, 5, 15, 4), (3, 4, 2, 6), (10, 8, 12), (10, 17, 2, 0, 11, 16)]))