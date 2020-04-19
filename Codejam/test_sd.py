import subprocess
import random
import sys

r = 100
c = 100
a = [[0 for i in range(c)] for i in range(r)]
for i in range(r):
    for j in range(c):
        a[i][j] = int(random.random()*1e6)+1

print(1)
print(r, c)
for i in a:
    print(*i)
# python3 test_sd.py > file; ./a < file > file1; ./b < file > file2; diff file1 file2