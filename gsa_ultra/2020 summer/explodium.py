def solution(targets):
    # Sort the targets, so we can consider them from left to right
    targets.sort()
    # A stack of bombs that we are using
    bombs = []
    for i in targets:
        # merge the current bomb with any overlapping bombs
        while bombs != [] and bombs[-1][0] + bombs[-1][1] >= i[0] - i[1]:
            bomb = bombs.pop()
            a = min(bomb[0] - bomb[1], i[0] - i[1])
            b = max(bomb[0] + bomb[1], i[0] + i[1])
            i = ((a+b)/2, (b-a)/2)
        # Add the current bomb
        bombs.append(i)
    # Sum up the bomb payloads
    ans = 0
    for i in bombs:
        ans += i[1]
    return int(ans)
print(solution([(0,2),(2,3),(8,3)]))