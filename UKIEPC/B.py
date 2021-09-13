n = int(input())

ans = []
while n != 0:
    for i in range(18):
        if 10**i == n:
            ans.append(10**i-1)
            ans.append(1)
            n = 0
            break
    if n == 0:
        break
    s = str(n)
    first_half = s[:(len(s)+1)//2]
    second_half = first_half[:(len(s))//2][::-1]
    if int(first_half + second_half) > n:
        first_half = str(int(first_half) - 1)
        second_half = first_half[:(len(s))//2][::-1]
    n -= int(first_half + second_half)
    ans.append(int(first_half + second_half))

print(len(ans))
for i in ans:
    print(i)