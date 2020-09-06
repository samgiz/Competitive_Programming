from collections import Counter

# A lot of the code in the solution was taken out into functions, but since I was desparately trying to speed it up, I put it all together
# And it worked
def solution(N, snakes, ladders):
    # Create the mapping of snake and ladder starts to ends
    M = {i:j for i,j in snakes + ladders}
    snake_ends = [i[1] for i in snakes]
    ladder_ends = [i[1] for i in ladders]
    # This stores certain counters that we are keeping track of
    ans = {i:Counter() for i in snake_ends + ladder_ends}
    # Initialize counters for snake ends at j to equal 1*v_j
    for i,j in snakes:
        ans[j][j] = 1
    # Theses need to be went over when removing a certain snake end in counters
    encountered_ladder_ends = []
    snake_starts = [i[0] for i in snakes]
    ladder_starts = [i[0] for i in ladders]
    # Non-noraml squares, on which we need to stop, in reverse order
    specials = sorted(snake_starts + ladder_ends + snake_ends + ladder_starts, reverse = True)
    specials.append(0)
    # Make these sets for quick lookup
    snake_ends = set(snake_ends)
    ladder_ends = set(ladder_ends)

    # mm represents the maximum gap we need to exponentiate over, so we don't precompute unnecessary bits
    mm = N-1 - specials[0]
    for i in range(len(specials)-1):
        mm = max(mm, specials[i] - specials[i+1])
    # kk is the max bit of mm
    kk = 0
    while (1<<kk) <= mm:
        kk += 1
    
    # dp stores the exponentiation matrices for 2**i up to k
    dp = [0 for i in range(kk)]
    # cache stores any subresult matrices that we have already calculated
    cache = {}
    # The base matrix, when the gap is 1
    matrix = [[1/6, 1/6, 1/6, 1/6, 1/6, 1/6, 1],
              [  1,   0,   0,   0,   0,   0, 0],
              [  0,   1,   0,   0,   0,   0, 0],
              [  0,   0,   1,   0,   0,   0, 0],
              [  0,   0,   0,   1,   0,   0, 0],
              [  0,   0,   0,   0,   1,   0, 0],
              [  0,   0,   0,   0,   0,   0, 1]]
    # Initialize dp
    dp[0] = matrix
    cache[1] = matrix
    for i in range(1, len(dp)):
        matrix = [[sum([matrix[ii][k] * matrix[k][j] for k in range(7)]) for j in range(7)] for ii in range(7)]
        dp[i] = matrix
        # Remember in cache
        cache[1<<i] = matrix
    # Denotes the index of the last element that we have calculated
    prev = N-1
    # Denotes the last 6 variables that we have computed, plus a unit Counter at the end
    vec = [Counter() for i in range(7)]
    # Initialize unit counter
    vec[6][-1] = 1
    one_counter = [vec[6]]
    # Iterate over positions we need to stop at
    for cur in specials:
        # Get gap and update prev
        diff = prev - cur
        prev = cur
        m = 0 # Matrix we are calculating
        if diff in cache: # Check if we already have the matrix precomputed
            m = cache[diff]
        else: # Find the longest prefix of the matrix that we have computed, and compute the rest
            cum = 0
            for i in range(kk):
                if ((1 << i) & diff) > 0:
                    cum += (1 << i)
                    if cum in cache:
                        m = cache[cum]
                    else:
                        m = [[sum([m[ii][k] * dp[i][k][j] for k in range(7)]) for j in range(7)] for ii in range(7)]
                        cache[cum] = m
        # Perform matrix * vector multiplication
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
        # Update the vector
        vec = new_vec
        if cur in M:
            # We stopped at a start, so just replace this variable with appropriate end
            vec[0] = ans[M[cur]]
        elif cur in ladder_ends:
            # Store the value for future reference
            ans[cur] = vec[0]
            if len(ans[cur].keys()) > 1:
                encountered_ladder_ends.append(cur)
        elif cur in snake_ends:
            # remove cur coefficients from any counters
            counter = vec[0]
            # Update the cur variable
            d = 1 - counter[cur]
            del counter[cur]
            for k in counter.keys():
                counter[k] /= d
            # Update the remaining vector elements
            for j in range(1, 6):
                if vec[j][cur] > 0:
                    am = vec[j][cur]
                    del vec[j][cur]
                    for k in counter.keys():
                        vec[j][k] += counter[k]*am
            to_delete = 0
            # Go over ladder ends that have unresolved variables
            for ii in range(len(encountered_ladder_ends)):
                m = encountered_ladder_ends[ii]
                if ans[m][cur] > 0:
                    am = ans[m][cur]
                    del ans[m][cur]
                    for k in counter.keys():
                        ans[m][k] += counter[k]*am
                    if len(ans[m].keys()) == 1: # This variable is resolved, can remove from list
                        to_delete = ii+1
            # Update the ladder ends that still have unresolved variables
            encountered_ladder_ends = encountered_ladder_ends[to_delete:]
    return int(vec[0][-1]) # Return the answer

# Generator + test below
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