def solution(ps):
    ans = 0
    cur = 1
    M = int(1e9+7)
    # print(M)
    for p in ps:
        if correct(p):
            ans += cur
        cur = (cur * 2) % M
    return ans % M
def gcd(a,b): 
    if(b==0):
        return a 
    else: 
        return gcd(b,a%b)
def correct(p):
    a, b, c, d = p
    # Check trivial cases
    g = gcd(a, b)
    if c*d % (a*b) != 0:
        return False
    if c % g != 0 or d % g != 0:
        return False
    # Divide everything through by the common divisor
    a //= g
    b //= g
    c //= g
    d //= g
    # Check if we can trivially cover
    if (c % a == 0 and d % b == 0) or (c % b == 0 and d % a == 0):
        return True
    # Here we need one of c and d to be divisible by a*b, and the other be of form x*a+y*b
    if c % (a*b) != 0 and d % (a*b) != 0:
        return False
    if c % (a*b) != 0:
        c, d = d, c
    # try to make up d = x*a + y*b
    y = 0
    if a > b:
        a,b=b,a
    while y*b < d and (d - y * b) % a != 0:
        y += 1
    return y*b < d
    
print(correct((6, 4, 5, 6)))