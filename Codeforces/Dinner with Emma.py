n,m=map(int, input().split())
C = [list(map(int, input().split())) for i in range(n)]
print(max(map(min, C)))