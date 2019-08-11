n, k = map(int, input().split())
k-=1
s = input()
ans = s[:k] + s[k].lower() + s[k+1:]
print(ans)