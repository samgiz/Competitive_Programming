n = int(input())
s = input()
z = len(list(filter(lambda x: x == 'z', s)))
n = len(list(filter(lambda x: x == 'n', s)))
print(*[1 for i in range(n)], *[0 for i in range(z)])