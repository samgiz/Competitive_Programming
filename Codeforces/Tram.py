n = int(input())
a = []
for i in range(n):
	tp = list(map(int, input().split(' ')))
	a.append(tp[1]-tp[0])
s = 0
msum = 0
for i in a:
	s+=i
	msum = max(msum, s)
print(msum)