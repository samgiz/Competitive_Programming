t = int(input())
for test in range(t):
    print(f"Case #{test+1}: ", end="")
    n = int(input())
    nums = input().split()
    ans = 0
    for i in range(n - 1):
        a = nums[i]
        b = nums[i+1]

        if len(b) > len(a):
            continue
        c = a[:len(b)]
        if int(c) > int(b):
            # add zeros to the end
            b += '0' * (len(a) - len(b) + 1)
        elif int(c) < int(b):
            # also add zeros, but add one less
            b += '0' * (len(a) - len(b))
        else:
            # try just a+1, if that is larger than 
            if c == str(int(a) + 1)[:len(b)]:
                b = str(int(a) + 1)
            else:
                b += '0' * (len(a) - len(b) + 1)

        ans += len(b) - len(nums[i+1])
        nums[i+1] = b
    print(ans)