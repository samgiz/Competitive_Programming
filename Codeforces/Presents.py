n = int(input())
g = list(map(int, input().split()))

ans = [0 for i in range(n)]
for i in range(n):
    ans[g[i]-1] = i+1
print(*ans)