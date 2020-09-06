def solution(ps):
    # Just a large value to use instead of infinity
    LARGE = int(1e9)
    # The answers so far. Map current index -> speed -> least time taken to be at this index at this speed
    dp = {}
    # Initialize with the first level
    for i in ps[0]:
        dp[i] = {5: 5}
    # Go over the remaining levels
    for i in range(1, len(ps)):
        # Sort the platform heights, so we can use a sliding window
        p = sorted(j for j in ps[i])
        new_dp = {}
        dp_vals = sorted(dp.keys())
        # Where to start the sliding window
        start = 0
        # Iterate over new pillar sizes
        for j in p:
            # Increase sliding windows size if necessary
            while start != len(dp_vals) and dp_vals[start] < j - 5:
                start += 1
            if start == len(dp_vals):
                break
            new_dp_j = {}
            cur = start
            # Iterate over sliding window of pillars from which we can jump to j
            while cur < len(dp_vals) and dp_vals[cur] <= j + 5:
                # do some local caching
                el = dp_vals[cur]
                d = dp[el]
                # Calculate the new dp values
                for speed in d:
                    cost = d[speed]
                    if el < j:
                        m = min(10, speed + 1)
                        new_dp_j[m] = min(new_dp_j.get(m, LARGE), cost + m)
                    elif el > j:
                        m = max(1, speed - 1)
                        new_dp_j[m] = min(new_dp_j.get(m, LARGE), cost + m)
                    else:
                        new_dp_j[speed] = min(new_dp_j.get(speed, LARGE), cost + speed)
                cur += 1
            # prune out sctrictly worse speed values at the same location
            m = LARGE
            for k, v in sorted(new_dp_j.items()):
                if v >= m:
                    del new_dp_j[k]
                m = min(m, v)
            new_dp[j] = new_dp_j
        dp = new_dp
    # get the answer
    ans = min([dp[i][j] for i in dp for j in dp[i]])
    return ans
# print(solution([(1, 4), (3, 8)]))
print(solution([(16, 18, 14), (19, 18, 17), (20, 17, 21), (20, 10, 19), (7, 4, 14), (11, 3, 4), (8, 5, 15, 4), (3, 4, 2, 6), (10, 8, 12), (10, 17, 2, 0, 11, 16)]))