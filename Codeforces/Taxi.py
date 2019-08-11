n = input()
a = map(int, input().split(' '))
ct = [0 for i in range(5)]
for i in a:
	ct[i]+=1

ans = 0
ans += ct[4]
ct[1] = max(ct[1]-ct[3], 0)
ans += ct[3]
ans += ct[2] // 2
if ct[2] % 2 == 1:
	ans += 1
	ct[1] = max(ct[1]-2, 0)
ans += (ct[1]+3) // 4
print(ans)