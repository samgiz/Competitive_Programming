import sys
t = int(input())

def evaluate(s):
    ans = 0
    for i in range(len(s) - 1):
        if s[i] == 'C' and s[i+1] == 'J':
            ans += x
        if s[i] == 'J' and s[i+1] == 'C':
            ans += y
    return ans

def possibles(length):
    return ['C' * length, 
            'J' * length, 
            'C' * (length-1) + 'J', 
            'J' * (length-1) + 'C',
            'CJ' * (length//2) + ('C' if length % 2 == 1 else ''),
            'JC' * (length//2) + ('J' if length % 2 == 1 else '')]

def best0(length):
    ans = 1e9
    for i in possibles(length):
        ans = min(ans, evaluate(i))
    return ans

def best1(length, character):
    ans = 1e9
    for i in possibles(length):
        ans = min(ans, evaluate(i + character))
    return ans 

def best2(length, character1, character2):
    ans = 1e9
    for i in possibles(length):
        ans = min(ans, evaluate(character1 + i + character2))
    return ans 

for i in range(t):
    print(f"Case #{i+1}: ", end="")
    x, y, s = input().split()
    x = int(x)
    y = int(y)
    if not ('C' in s or 'J' in s):
        print(best0(len(s)))
        continue
    start = 0
    ans = 0
    while s[start] == '?':
        start += 1
    ans += best1(start, s[start])
    end = len(s) - 1
    while s[end] == '?':
        end -= 1
    ans += best1(len(s) - end + 1, s[end])
    s = s[start:end+1]
    last = s[0]
    cur = 0
    for i in s[1:]:
        if i == '?':
            cur += 1
        else:
            ans += best2(cur, last, i)
            cur = 0
            last = i
    print(ans)
