n = int(input())
tt = n
p = list(map(lambda x: int(x)/100, input().split(' ')))

k = [1 for i in range(n)]

def prod():
	t=1
	for i in range(len(p)):
		t*=(1-(1-p[i])**k[i])
	return t

ex = n
for i in p:
	ex*=i

last = 1

while last*n > 1e-30:
	mi = -1
	mv = 0
	for j in range(tt):
		tmp = (1-p[j])**k[j]*p[j]/(1-(1-p[j])**k[j])
		if tmp>mv:
			mv = tmp
			mi = j

	last = prod()*mv
	k[mi] += 1
	n += 1
	ex += n*last

print(ex)