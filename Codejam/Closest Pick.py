t = int(input())
for test in range(1,t+1):
    print(f"Case #{test}: ", end="")
    n, k = map(int, input().split())
    tickets = sorted(list(map(int, input().split())))
    # choose start and end
    ans = 0
    for i in range(len(tickets) - 1):
        ans = max(ans, tickets[i+1] - tickets[i] - 1)
    diffs = [tickets[0]-1, k-tickets[-1]]
    for i in range(len(tickets) - 1):
        diffs.append((tickets[i+1] - tickets[i]) // 2)

    diffs = sorted(diffs)
    # print(diffs)
    ans = max(ans, diffs[-1] + diffs[-2])
    print(ans / k)
