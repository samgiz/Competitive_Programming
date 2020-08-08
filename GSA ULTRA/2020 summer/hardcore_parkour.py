def solution(ps):
    LARGE = 1e10
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
            new_dp[j] = {}
            cur = start
            while cur < len(dp_vals) and dp_vals[cur] <= j + 5:
                el = dp_vals[cur]
                d = dp[el]
                for speed in d:
                    cost = d[speed]
                    if abs(el - j) <= 5:
                        if el < j:
                            new_dp[j][min(10, speed + 1)] = min(new_dp[j].get(min(10, speed + 1), LARGE), cost + min(10, speed + 1))
                        elif el > j:
                            new_dp[j][max(1, speed - 1)] = min(new_dp[j].get(max(1, speed - 1), LARGE), cost + max(1, speed - 1))
                        else:
                            new_dp[j][speed] = min(new_dp[j].get(speed, LARGE), cost + speed)
                cur += 1
            # idea: prune out sctrictly worse speed values at the same location here
        dp = new_dp
        # print(dp)
    ans = LARGE
    # print(dp)
    for i in dp:
        for j in dp[i]:
            # print(j, dp[i][j])
            ans = min(ans, dp[i][j])
    return ans
print(solution([(1, 2), (3, 8)]))