n = int(input())
from collections import defaultdict
d = defaultdict(int)
d["polycarp"] = 1
ans = 0
for i in range(n):
	a,b,c=input().split(' ')
	a = a.lower()
	c = c.lower()
	d[a]=max(d[a], d[c]+1)
	ans = max(ans, d[a])
print(ans)