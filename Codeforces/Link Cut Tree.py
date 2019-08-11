l,r,k = list(map(int, input().split(' ')))
t = 1
a=0
Ans = []
while t<=r:
	if t>=l:
		a+=1
		Ans.append(t)
	t*=k
if a==0:
	print(-1)
else:
	print(" ".join(map(str, Ans)))