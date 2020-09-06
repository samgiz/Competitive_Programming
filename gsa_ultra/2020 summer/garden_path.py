# Generates the tilings of size 1
def generate(flag, width, start = 0):
    # Add the current tiling to the possible tilings
    ans = [flag]
    for i in range(start, width-1):
        if (3 << i) & flag == 0:
            # Add a vertical domino, represented as 3<<i
            ans += generate(flag + (3<<i), width, i + 2)
    return ans

def solution(width, length, plants):
    # The modulus to take the answer of
    M = int(1e9+7)
    # Sort elements by length coordinate
    plants.sort(key=lambda x:x[1])
    # Append a wall of plants at the end so the algorithm works properly
    for i in range(width):
        plants.append((i, length))
    # amount of plants
    n = len(plants)

    # calculate the maximum gap that we need to exponentiate over
    mp = plants[0][1] + 1
    for i in range(n-1):
        mp = max(mp, plants[i+1][1] - plants[i][1])

    # kk is the number of maximum number of bits that we need to exponentiate over
    kk = 1
    while (1<<kk) < mp:
        kk += 1
    # dp[i][j][k] stores the number of ways to cover a 'rectangle' of size 2**i, and start and end configurations j and k
    
    # Amount of possible states for a side to be in
    ms = (1<<width)

    dp = [[[0 for i in range(ms)] for j in range(ms)] for l in range(kk)]
    # TODO: initialize the first level appropriately
    for i in range(ms): # lhs
        for j in generate(i, width): # rhs, all vertical dominoes only on the right side
            dp[0][i][j] = 1 # for each configuration found, denote that it exists

    # Calculate the answer for the remaining levels with a lot of intermediate caching
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
                if dp_l1_i_j != 0:
                    for k in range(ms):
                        dp_li[k] = (dp_li[k] + dp_l1_i_j * dp_l1_nj[k]) % M

    # For each jaggedness, store the number of ways we have reached it so far
    ans = {}
    ans[ms-1] = 1

    # Denote the last position of the plants
    prev = -1

    # Denotes the index of the next plant to consider
    cnt = 0

    # Go through all plants
    while cnt < n:
        # Find plants that are at the same position, and store their representation in flag
        ct = cnt
        flag = 0
        # The gap between flowers that we are attacing to the previously calculated path
        gap = plants[ct][1] - prev
        prev = plants[ct][1]
        while ct < n and plants[ct][1] == plants[cnt][1]:
            flag |= (1<<plants[ct][0])
            ct += 1
        cnt = ct

        # Get the gap bits
        bits = [i for i in range(kk) if (1 << i) & gap > 0]

        # Binary exponentiate
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
        
        # Last iteration is special since we cannot overlap with the flag
        # Get all positions that don't overlap with flag
        last_positions = [i for i in range(ms) if i & flag == 0]
        new_ans = {}
        dp_lb = dp[bits[-1]]
        for j in ans:
            ans_j = ans[j]
            nj = (ms-1) & (~j)
            dp_lb_nj = dp_lb[nj]
            for k in last_positions:
                if dp_lb_nj[k] > 0:
                    # Make sure to include the flowers into the jaggedness
                    new_ans[k + flag] = (new_ans.get(k + flag, 0) + ans_j * dp_lb_nj[k]) % M
        ans = new_ans
        print(ans)
    # return calculated answer. Remember that we added a wall of flowers at the end
    return ans[ms-1]


print(solution(5, 10, [(0, 4), (0, 7)]))