def generate(flag, width, start = 0):
    ans = [flag]
    for i in range(start, width-1):
        if (3 << i) & flag == 0:
            ans += generate(flag + (3<<i), width, i + 2)
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
    mp = plants[0][1] + 1
    for i in range(n-1):
        mp = max(mp, plants[i+1][1] - plants[i][1])
    # Amount of possible states for a side to be in
    ms = (1<<width)
    # dp[i][j][k] stores the number of ways to cover a 'rectangle' of size 2**i, and start and end configurations j and k
    kk = 1
    while (1<<kk) < mp:
        kk += 1
    kk += 1
    dp = [[[0 for i in range(ms)] for j in range(ms)] for l in range(kk)]
    for i in range(ms): # lhs
        for j in generate(i, width): # rhs, all possible additions of dominoes only on the right side
            dp[0][i][j] += 1 # for each configuration found, increase by 1
    # Calculate the answer for the remaining levels
    for l in range(1, kk):
        dp_l = dp[l]
        dp_l1 = dp[l-1]
        for i in range(ms):
            dp_li = dp_l[i]
            dp_l1_i = dp_l1[i]
            for j in range(ms):
                nj = (ms-1) & (~j)
                dp_l1_nj = dp_l1[nj]
                dp_l1_i_j = dp_l1_i[j]
                # print(nj)
                if dp_l1_i_j != 0:
                    for k in range(ms):
                        dp_li[k] = (dp_li[k] + dp_l1_i_j * dp_l1_nj[k]) % M
    ans = {}
    ans[ms-1] = 1
    prev = -1
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
        bits = [i for i in range(kk+1) if (1 << i) & m > 0]
        for i in bits[:-1]: # The last bit should be treated in a special way for efficiency
            new_ans = {}
            dp_i = dp[i]
            for j in ans:
                ans_j = ans[j]
                nj = (ms-1) & (~j)
                dp_i_nj = dp_i[nj]
                for k in range(ms):
                    if dp_i_nj[k] > 0:
                        new_ans[k] = (new_ans.get(k, 0) + ans_j * dp_i_nj[k]) % M
            ans = new_ans
        last_positions = [i for i in range(ms) if i & flag == 0]
        new_ans = {}
        dp_lb = dp[bits[-1]]
        for j in ans:
            ans_j = ans[j]
            nj = (ms-1) & (~j)
            dp_lb_nj = dp_lb[nj]
            for k in last_positions:
                if dp_lb_nj[k] > 0:
                    new_ans[k + flag] = (new_ans.get(k + flag, 0) + ans_j * dp_lb_nj[k]) % M
        ans = new_ans
    return ans[ms-1]


N, M, K = map(int, input().split())
holes = []
for i in range(K):
    a, b = map(int, input().split())
    holes.append([b, a])
print(solution(M, N, holes))