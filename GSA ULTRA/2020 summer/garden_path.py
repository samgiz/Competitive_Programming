def generate(flag, width, start = 0):
    ans = [flag]
    for i in range(start, width-1):
        if (3 << i) & flag == 0:
            ans += generate(flag | (3<<i), width, i + 2)
    return ans
def solution(width, length, plants):
    # The modulus to take the answer of
    M = int(1e9+7)
    # Sort elements by length coordinate
    plants.sort(key=lambda x:x[1])
    # Append a wall of plants at the end so the algorithm works properly (to be seen if actually needed)
    for i in range(width):
        plants.append((i, length))
    # amount of plants
    n = len(plants)
    # Amount of possible states for a side to be in
    ms = (1<<width)
    # dp[i][j][k] stores the number of ways to cover a 'rectangle' of size 2**i, and start and end configurations j and k
    dp = [[[0 for i in range(ms)] for j in range(ms)] for k in range(30)]
    # TODO: initialize the first level appropriately
    for i in range(ms): # lhs
        for j in generate(i, width): # rhs, all possible additions of dominoes only on the right side
            dp[0][i][j] += 1 # for each configuration found, increase by 1
    # Calculate the answer for the remaining levels
    for l in range(1, 30):
        for i in range(ms):
            for j in range(ms):
                nj = (ms-1) & (~j)
                # print(nj)
                if dp[l-1][i][j] != 0:
                    for k in range(ms):
                        dp[l][i][k] = (dp[l][i][k] + dp[l-1][i][j] * dp[l-1][nj][k]) % M
    # print(dp[1])
    ans = {}
    ans[ms-1] = 1
    # print(ans)
    prev = -1
    # all_positions = [i for i in range(ms)]
    cnt = 0
    while cnt < n:
        ct = cnt
        flag = 0
        m = plants[ct][1] - prev
        prev = plants[ct][1]
        while ct < n and plants[ct][1] == plants[cnt][1]:
            flag |= (1<<plants[ct][0])
            ct += 1
        cnt = ct
        bits = [i for i in range(30) if (1 << i) & m > 0]
        for i in bits[:-1]: # The last bit should be treated in a special way for efficiency
            new_ans = {}
            for j in ans:
                nj = (ms-1) & (~j)
                for k in range(ms):
                    if dp[i][nj][k] > 0:
                        # print('ha', ans[j], dp[i][j][k])
                        new_ans[k] = (new_ans.get(k, 0) + ans[j] * dp[i][nj][k]) % M
            ans = new_ans
            # print(ans)
        last_positions = [i for i in range(ms) if i & flag == 0]
        lb = bits[-1]
        new_ans = {}
        for j in ans:
            nj = (ms-1) & (~j)
            for k in last_positions:
                if dp[lb][nj][k] > 0:
                    new_ans[k | flag] = (new_ans.get(k | flag, 0) + ans[j] * dp[lb][nj][k]) % M
        ans = new_ans
    #     print(ans)
    # print(ans)
    return ans[ms-1]


print(solution(6, 10, [(0, 4), (0, 7)]))