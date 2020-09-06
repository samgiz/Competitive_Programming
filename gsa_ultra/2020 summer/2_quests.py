def solution(a, b):
    # Add dummy values at the start for convenience
    a.insert(0, 0)
    b.insert(0, 0)
    # Denote the lengths of the arrays
    n = len(a)
    m = len(b)
    # Prepopulate the answer array
    ans = [[[0 for k in range(2)] for i in range(m)] for j in range(n)]
    # Calculate the first row and first column of ans
    for i in range(n-1):
        ans[i+1][0][0] = ans[i][0][0] + abs(a[i+1] - a[i])
        ans[i+1][0][1] = ans[i+1][0][0] + b[1]
    for i in range(m-1):
        ans[0][i+1][1] = ans[0][i][1] + abs(b[i+1] - b[i])
        ans[0][i+1][0] = ans[0][i+1][1] + a[1]
    
    # Calculate the remaining ans values
    for i in range(n-1):
        for j in range(m-1):
            ans[i+1][j+1][0] = min(ans[i][j+1][0] + abs(a[i+1] - a[i]), ans[i][j+1][1] + abs(a[i+1] - b[j+1]))
            ans[i+1][j+1][1] = min(ans[i+1][j][0] + abs(a[i+1] - b[j+1]), ans[i+1][j][1] + abs(b[j+1] - b[j]))

    return min(ans[n-1][m-1][0], ans[n-1][m-1][1])

print(solution([5, 3, 10, 6], [9, 7, 12]))