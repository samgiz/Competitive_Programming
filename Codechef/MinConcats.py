import sys
a = input()
b = input()

if not set(a) <= set(b):
    print(-1)
    sys.exit()

# Next[c][i] tores the next closest (wrapping around) index j, s.t. b[j]=='a'+c
Next = [[0 for i in range(len(b))] for j in range(26)]

# Generate Next array
for k in range(26):
    c = chr(ord('A')+k)
    f = -1
    # find any element in b with value c
    for i in range(len(b)):
        if b[i]==c:
            f = i
    
    # no letters c in b
    if f==-1:
        continue
    
    # generate Next for letter c
    for i in range(len(b)):
        cur = (f-i-1+len(b))%len(b)
        if b[(cur+1)%len(b)]==c:
            Next[k][cur]=(cur+1)%len(b)
        else:
            Next[k][cur]=Next[k][(cur+1)%len(b)]

ans = 0
cur = len(b)-1
# for each letter c in a, greedily choose the closest letter to the last
# chosen letter in b, that equals c
for c in a:
    next = Next[ord(c)-ord('A')][cur]
    if next<=cur:
        ans+=1
    cur=next
print(ans) 