from math import *

beta = atan(sqrt(2.0))
eps = 1e-15

def area(alpha):
	kk = cos(alpha)
	tk = cos(alpha/2)-sqrt(3)/2*cos(alpha+beta)
	return kk+tk

t = int(input())
for test in range(1, t+1):
	print("Case #%d:" % test)
	S = float(input())
	if S<=1.414213:
		a = 0
		b = pi/4
		while b-a>eps:
			mid = (a+b)/2
			if sin(mid)+cos(mid)<S:
				a = mid
			else:
				b = mid
		print("{0} {1} {2}".format(0.5, 0, 0))
		print("{0} {1} {2}".format(0, sin(a)/2, cos(a)/2))
		print("{0} {1} {2}".format(0, sin(a+pi/2)/2, cos(a+pi/2)/2))
	else:

		a = 0
		b = pi/4
		while b-a>eps:
			mid = (a+b)/2
			if area(mid)<S:
				a = mid
			else:
				b = mid
		k = -sin(a)
		# print(a)
		print("{0} {1} {2}".format(cos(a)/2, 0, sin(a)/2))
		print("{0} {1} {2}".format(k, sqrt(2)/4, sqrt(1/8-k*k)))
		print("{0} {1} {2}".format(k, -sqrt(2)/4, sqrt(1/8-k*k)))