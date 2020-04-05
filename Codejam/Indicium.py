# n = 1
# a = [[0 for i in range(n)] for j in range(n)]
# # import random
# # import sys
# # sys.setrecursionlimit(2550)

# traces = set()

def generate1(n): #11111122
    # Initialize
    arr = [[0 for i in range(n)] for i in range(n)]
    # trace 1s and 2s next to them
    for i in range(n-2):
        arr[i][i] = 1
        arr[i][(i+1)%(n-2)] = 2

    # bottom right 2x2
    arr[-1][-1] = arr[-2][-2] = 2
    arr[-2][-1] = arr[-1][-2] = 1

    # top (n-2)xn
    for i in range(n-2):
        arr[i][-1] = n-i
        cur = (n-i)%n + 1
        if cur == 1:
            cur = 3
        for j in range(n-1):
            if arr[i][j] == 0:
                arr[i][j] = cur
                cur = cur%n + 1
                if cur == 1:
                    cur = 3

    # Last 2 rows
    # column 1
    arr[-2][0] = 3
    arr[-1][0] = 4
    # columns 2 to n-4
    for j in range(1, n-3, 2):
        arr[-2][j] = 4+j
        arr[-1][j] = 2+j
        if j != n-4:
            arr[-2][j+1] = 3+j
            arr[-1][j+1] = 5+j
    
    # column n-3
    if arr[-1][-4] == n:
        arr[-2][-3] = n
        arr[-1][-3] = n-1
    else:
        arr[-2][-3] = n-1
        arr[-1][-3] = n
    

    return arr

def generate2(n): #11111123
    # shift and shuffle the row 2, 1, 3, 4, ..., n
    arr = []
    row = list(range(1, n+1))
    row[0], row[1]=row[1], row[0]
    row = row[1:] + row[:1]
    for i in range(n):
        arr.append(row[n-i:] + row[:n-i])
    arr[-1], arr[-2]=arr[-2], arr[-1]
    return arr
def generate3(n): #11111111
    arr = []
    row = list(range(1, n+1))
    for i in range(n):
        arr.append(row[n-i:] + row[:n-i])
    return arr
def generate4(n): #nnnnnnnn
    arr = []
    row = list(range(1, n+1))
    row[0], row[-1]=row[-1], row[0]
    for i in range(n):
        arr.append(row[n-i:] + row[:n-i])
    return arr

def check_latin(a):
    n = len(a)
    ss = set(range(1, n+1))
    for i in range(n):
        if set(a[i]) != ss:
            return False
        if set([a[j][i] for j in range(n)]) != ss:
            return False
    return True
    

# def calculate_trace():
#     ans = 0
#     for i in range(n):
#         ans += a[i][i]
#     if ans not in traces:
#         for i in a:
#             print(i)
#         pass
        
#     traces.add(ans)
#     # print(sorted(list(traces)))
# def rec(i, j):
#     if j == n:
#         print(i)
#     # print(i, j)
#     if len(traces) != 0:
#         return
#     if i == j:
#         rec(i, j+1)
#     elif j==n and i == n-1:
#         calculate_trace()
#     elif j == n:
#         rec(i+1, 0)
#     else:
#         values = list(set(range(1, n+1)) - set([a[i][l] for l in range(j)]) - set([a[l][j] for l in range(i)]) - set([a[i][i], a[j][j]]))
#         random.shuffle(values)
#         for k in values:
#             a[i][j] = k
#             rec(i, j+1)

# for i in [26]:
#     n = i
#     a = [[0 for i in range(n)] for j in range(n)]
#     traces = set()
#     bs = [[24, 2]]
#     for b in bs:
#         traces = set()
#         cur = 0
#         current = 1
#         for k in b:
#             for _ in range(k):
#                 a[cur][cur] = current
#                 cur +=1
#             current +=1
#         rec(0, 0)
#         if len(list(traces)) > 0:
#             print(b, "possible")
#             print(traces)
#         else:
#             print(b, "impossible")

# for i in range(4, 50):
#     a = generate1(i)
#     b = generate2(i)
#     print("generate1", i, check_latin(a))
#     print("generate2", i, check_latin(b))

# for i in generate1(7):
#     print(i)


ans = [{} for i in range(4)]
ans[2][2] = [[1, 2],
             [2, 1]]
ans[2][4] = [[2, 1],
             [1, 2]]

ans[3][3] = [[1, 2, 3],
             [3, 1, 2],
             [2, 3, 1]]
ans[3][6] = [[2, 1, 3],
             [3, 2, 1],
             [1, 3, 2]]
ans[3][9] = [[3, 1, 2],
             [2, 3, 1],
             [1, 2, 3]]
# ans[0]=ans[1]=ans[2]=ans[3]={}
# for i in range(4, 51):
#     ans[i].append(generate1(i))
#     ans[i].append(generate2(i))

# print(generate3(5))

def solve(n, k):
    if n <=3:
        if not k in ans[n]:
            return "IMPOSSIBLE"
        else:
            return ans[n][k]
    if k == n+1 or k == n*n - 1:
        return "IMPOSSIBLE"
    if k == n*n:
        return generate4(n)
    if k == n:
        return generate3(n)
    a = n
    while a*(n-2) + 2 > k:
        a-=1
    b1 = (k - a*(n-2))//2
    c1 = k - a*(n-2) - b1
    b = min(b1, c1)
    c = max(b1, c1)
    if a == b or a == c:
        b -= 1
        c += 1
    if b == 0:
        a -= 1
        b = n-2
    print(a, b, c)
    # diagonal entries aaa...aaabc
    if b == c:
        # case 1
        arr = generate1(n)
        permutation = [0, a, b]

    else:
        # case 2
        arr = generate2(n)
        permutation = [0, a, b, c]
        # currently entries 111...11123
    for i in range(1, n+1):
        if i not in [a, b, c]:
            permutation.append(i)

    for i in range(n):
        for j in range(n):
            arr[i][j] = permutation[arr[i][j]]
    return arr

# t=0
t = int(input())

for kkk in range(1,t+1):
    n, k = map(int, input().split())
    print("Case #"+str(kkk)+": ", end="")
    arr = solve(n, k)
    if arr == "IMPOSSIBLE":
        print(arr)
        continue
    else:
        print("POSSIBLE")
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()

def trace(a):
    ans = 0
    for i in range(len(a)):
        ans+=a[i][i]
    return ans

# for n in range(4, 51):
#     for k in range(n, n*n+1):
#         ans = solve(n, k)
#         if k == n+1 or k == n*n-1:
#             print(n, k, ans == "IMPOSSIBLE")
#             if not ans == "IMPOSSIBLE":
#                 print(ans)
#                 input()
#         else:
#             print(n, k, check_latin(ans) and trace(ans) == k)
#             if not (check_latin(ans) and trace(ans) == k):
#                 for i in ans:
#                     print(*i)
#                 input()

# for n in range(2, 6):
#     for k in range(n, n*n+1):
#         print(n, k, solve(n, k))
#         if solve(n, k) != "IMPOSSIBLE":
#             print(check_latin(solve(n, k)) and trace(solve(n, k)) == k)