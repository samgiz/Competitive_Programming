n = input()
s = input()
last = 'Y'
ans = 0
for i in s:
	if i == last: ans+=1
	last = i
print(ans)