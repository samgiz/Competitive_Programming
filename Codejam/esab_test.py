import subprocess
import random
import sys

process = subprocess.Popen(['./a'], 
           stdout=subprocess.PIPE, 
           stdin=subprocess.PIPE,
           stderr=subprocess.STDOUT,
           bufsize=0)



b = 100
query_num = 150
code = []
for i in range(b):
    code.append(round(random.random()))

def reverse():
    global code
    code = [1-i for i in code]

def switcheroo():
    global code
    option = int(random.random()*4)
    if option == 1:
        code = code[::-1]
    if option == 2:
        reverse()
    if option == 3:
        reverse()
        code = code[::-1]
def check_guess(guess):
    global code
    cur = ""
    for i in code:
        cur += str(i)
    return guess == cur

print(f"STARTING NEW TEST #1")
t = 1
process.stdin.write(bytearray(f"{t} {b}\n", 'utf8'))
for i in range(query_num+1):
    if i % 10 == 0:
        switcheroo()
    print("getting query")
    q = process.stdout.readline()[:-1].decode()
    print(f"query: {q}")
    if len(q) == b:
        if check_guess(q):
            print(f"GUESS WAS CORRECT\nQUERY #{i}")
            process.kill()
            sys.exit()
        else:
            print(f"GUESS WAS INCORRECT, QUERY #{i}")
            print(f"query: {q}")
            val = "".join(list(map(str, code)))
            print(f"actual value: {val}")
            process.kill()
            sys.exit()
    q = int(q)
    if q < 1 or q > b:
        print("INVALID QUERY VALUE")
        print(q)
        process.kill()
        sys.exit()
    print(f"provided output: {code[q-1]}")
    process.stdin.write(bytearray(f"{code[q-1]}\n", 'utf8'))

print("DID NOT FINISH IN THE RIGHT NUMBER OF QUERIES")
process.kill()

