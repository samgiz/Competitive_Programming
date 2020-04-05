import os
def solve(input):
    n = input // 1000
    m = input % 1000
    ans = 1
    while n > 0:
        ans *= n
        ans %= m
        n -=2
    return ans


for i in range(1001, 1000000):
    output = int(os.popen(f'echo {i} | java "It\'s showtime"').read())
    if i % 1000 == 0:
        continue
    if solve(i) != output:
        print(i)

    if i % 100 == 0:
        print(f"At i {i}")