import random
random.seed(12)
tests = []

def add_test():
    tests.append([[N, M], holes])
def gen_holes(K):
    global holes
    holes = []
    s = set()
    for i in range(K):
        rn = random.randint(0, N-1)
        rm = random.randint(0, M-1)
        while (rn, rm) in s:
            rn = random.randint(0, N-1)
            rm = random.randint(0, M-1)
        s.add((rn, rm))
        holes.append([rn, rm])
def add_rand_test():
    pass

N, M = 10, 5
holes = [[4, 0], [7, 0]]
add_test()

N, M = 3, 3
holes = [[1, 1]]
add_test()

N, M = 2, 2
holes = []
add_test()

N, M = 100, 6
holes = []
add_test()


N, M = 100, 6
holes = [[5, 0], [6, 1], [7, 2], [8, 3], [9, 4], [10, 5]]
add_test()
N, M = 100, 6
holes = [[6, 0], [7, 1], [8, 2], [9, 3], [10, 4], [11, 5]]
add_test()

N, M = 1000000000, 7
holes = [[100, 0], [101, 1], [102, 0]]
add_test()

N, M = 1000000000, 7
holes = [[0, 0]]
add_test()

N, M = 1, 4
holes = []
add_test()

N, M = 1, 4
holes = [[0, 1]]
add_test()

N, M = 1000000000, 1
gen_holes(10)
add_test()
N, M = 1000000000, 2
gen_holes(10)
add_test()
for i in range(10):
    N, M = 9999999, 2
    gen_holes(1000)
    add_test()
for i in range(10):
    N, M = 1000000000, 7
    gen_holes(1000)
    add_test()
for i in range(1, 8):
    N, M = 1000000000 - i, i
    gen_holes(950)
    add_test()

for i in range(len(tests)):
    test = tests[i]
    with open(f'file{i}.in', 'w') as f:
        print(*test[0], len(test[1]), file=f)
        for i in test[1]:
            # print(test[1])
            print(*i, file=f)