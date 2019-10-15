s = input()
l = list(filter(lambda x: x[0] == s[0] or x[1] == s[1], input().split()))
print("YES" if len(l) > 0 else "NO")