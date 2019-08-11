from fractions import gcd
t = int(input())
for _ in range(t):
	n, l = map(int, input().split())
	A = list(map(int, input().split()))
	Ans_num = [0 for i in range(l+1)]
	k = 0
	for i in range(l-1):
		if A[i] != A[i+1]:
			Ans_num[i+1] = gcd(A[i], A[i+1])
			k = i+1
			break
	for i in range(k-1, -1, -1):
		Ans_num[i] = A[i]//Ans_num[i+1]
	for i in range(k+1, l+1):
		Ans_num[i] = A[i-1]//Ans_num[i-1]
	C = sorted(list(set(Ans_num)))
	D = {}
	for i in range(26):
		D[C[i]] = chr(ord('A')+i)
	E = ''.join(list(map(lambda x: D[x], Ans_num)))
	print("Case #{}: {}".format(_+1, E))