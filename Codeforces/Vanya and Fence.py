n, h = map(int, input().split())
ans = n
l = list(map(int, input().split()))
for k in l:
    if k > h:
        ans += 1
print(ans)