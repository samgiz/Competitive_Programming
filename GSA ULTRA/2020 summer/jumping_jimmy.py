def solution(a, qs):
    # dp[i][j] represents max in interval [j, j + 1<<i)
    # dp[i][j] = max(dp[i-1][j], dp[i-1][j+1<<(i-1)])
    k = 18
    dp = [[0 for j in a] for i in range(k)]
    n = len(a)
    dp[0] = a
    for i in range(1, k):
        for j in range(n):
            if j+(1<<(i-1)) < n:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+(1<<(i-1))])
            else:
                dp[i][j] = dp[i-1][j]
    ans = 0
    for q in qs:
        a, b = q
        cur = 0
        for i in range(k-1, -1, -1):
            if (1<<i) <= b-a:
                cur = max(cur, dp[i][a])
                a += (1<<i)
        ans += cur
        print(cur)
    return ans
print(solution([3, 6, 6, 1, 9, 8, 4, 7, 1, 1], [(1, 7), (5, 7), (0, 1)]))