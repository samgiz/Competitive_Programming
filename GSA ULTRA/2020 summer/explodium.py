def solution(targets):
    # this seems like it can be done with a single sweep, starting with bombs centered at targets and combining them when they overlap
    targets.sort()
    bombs = []
    for i in targets:
        while bombs != [] and bombs[-1][0] + bombs[-1][1] >= i[0] - i[1]:
            bomb = bombs.pop()
            a = min(bomb[0] - bomb[1], i[0] - i[1])
            b = max(bomb[0] + bomb[1], i[0] + i[1])
            i = ((a+b)/2, (b-a)/2)

        bombs.append(i)
    ans = 0
    for i in bombs:
        ans += i[1]
    return int(ans)
print(solution([(0,2),(2,3),(8,3)]))