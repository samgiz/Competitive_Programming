t = int(input())
for _ in range(t):
    print("Case #" + str(_+1) + ": ", end="")
    n = int(input())
    begins = []
    ends = []
    ans = []
    for i in range(n):
        s = input().split('*')
        for i in range(1, len(s)-1):
            ans.append(s[i])
        begins.append(s[0])
        ends.append(s[-1])
    beginn = ""
    f = True
    for i in begins:
        if i.startswith(beginn):
            beginn = i
        elif beginn.startswith(i):
            continue
        else:
            f = False
            break
    endd = ""
    for i in ends:
        if i.endswith(endd):
            endd = i
        elif endd.endswith(i):
            continue
        else:
            f = False
            break
    ans = "".join([beginn, *ans, endd])
    if f:
        print(ans)
    else:
        print('*')

        