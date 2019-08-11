import math

h, l = map(float, input().split())
hyp = math.sqrt(h*h+l*l)
alpha = math.atan(l/h)
x = hyp/math.sin(2*alpha)*math.sin(alpha)
print(x-h)