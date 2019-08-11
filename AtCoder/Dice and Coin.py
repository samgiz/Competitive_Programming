n, k = map(int, input().split())

def prob(i):
	score = i 
	pr = 1/n
	while score < k:
		score *= 2
		pr/=2
	return pr

ans = 0
for i in range(1, n+1):
	ans += prob(i)
print(ans)