from functools import reduce

# def solution(a, m):
#     a.sort(reverse=True)
#     a.append(0)
#     ans = 0
#     pows = [0 for i in range(5001)]
#     pows[0] = 2
#     for i in range(5000):
#         pows[i+1] = (pows[i]*pows[i])%m
#     for i in range(len(a)-1):
#         cur = 0
#         ans += 1
#         x = (a[i] - a[i+1]) % (m-1)
#         while x > 0:
#             if (x & 1) != 0:
#                 ans = (ans * pows[cur]) % m
#             cur += 1
#             x >>= 1
#     return ans
# def solution(a, m):
#     # print(len(bin(m)))
#     for i in range(len(a)):
#         a[i]%=(m-1)
#     a.sort(reverse=True)
#     a.append(0)
#     ans = 0
#     pows = [0 for i in range(2203)]
#     pows[0] = 2
#     for i in range(2202):
#         pows[i+1] = (pows[i]*pows[i])%m
#     diffs = [(a[i] - a[i+1], i) for i in range(len(a)-1)]
#     diffs.sort()
#     vals = [0 for i in diffs]
#     cur = 1
#     prev = 0
#     # print(a)
#     # print(diffs)
#     for i in diffs:
#         # print(diffs)
#         v, ind = i
#         diff_diff = v - prev
#         x = bin(diff_diff)[2:]
#         l = len(x)
#         # print(l)
#         for i in range(l):
#             if (x[l-i-1]) == '1':
#                 cur = (cur * pows[i]) % m
#         vals[ind] = cur 
#         prev = v
#     for i in vals:
#         # print(i)
#         ans = (ans + 1) * i % m
#     return ans
# print(solution([i**1000 for i in range(5000)], 702079226394599267735191841413128874795247805490517054276340557155948943570099062636753289411154623672004867308640920603807694718006489892779925062138618515629872757368947667539951593306987479811638187121088483515360221935971126625400671012753343761397211280160501540278806457364464956441544244610516403573071554299443696418311471338159713528505050660205171647730521360774909493612839872795981479630114537859390310673838221447860778239988727101763027517463616482160397971523167080327549594766566010372471784045891758833973532140862388344166251701537850595095780193783149508070051871170910983223951139145060424748526226517327333826692719))
# def solution(a, m):
#     for i in range(len(a)):
#         a[i]%=(m-1)
#     a.sort(reverse=True)
#     a.append(0)
#     ans = 0
#     pows = [0 for i in range(5001)]
#     pows[0] = 2
#     for i in range(5000):
#         pows[i+1] = (pows[i]*pows[i])%m
#     bins = [bin(a[i] - a[i+1])[2:] for i in range(len(a) - 1)]
#     for x in bins:
#         ans += 1
#         l = len(x)
#         for i in range(l):
#             if x[l-i-1] == '1':
#                 ans = (ans * pows[i]) % m
#     return ans



# def solution(a, m):
#     for i in range(len(a)):
#         a[i]%=(m-1)
#     a.sort(reverse=True)
#     a.append(0)
#     ans = 0
#     pows = [0 for i in range(5001)]
#     pows[0] = 2
#     for i in range(5000):
#         pows[i+1] = (pows[i]*pows[i])%m
#     bins = [bin(i)[2:] for i in a]
#     M = max([len(i) for i in bins])
#     bins = ['0'*(M-len(i))+i for i in bins]
#     ans = 0
#     for i in range(M):
#         ct = 0
#         for j in bins:
#             if j[M-1-i] == '1':
#                 ct += 1
#         ans = (ans + ct * pows[i]) % m
#     # for x in bins:
#     #     ans += 1
#     #     l = len(x)
#     #     for i in range(l):
#     #         if x[l-i-1] == '1':
#     #             ans = (ans * pows[i]) % m
#     return ans

# def solution(a, m):
#     blocks = {}
#     block_size = 8
#     for i in range(len(a)):
#         a[i]%=(m-1)
#     a.sort(reverse=True)
#     a.append(0)
#     ans = 0
#     pows = [0 for i in range(5001)]
#     pows[0] = 2
#     for i in range(5000):
#         pows[i+1] = (pows[i]*pows[i])%m
#     bins = [bin(a[i] - a[i+1])[2:] for i in range(len(a) - 1)]
#     l = max([len(i) for i in bins])
#     bins = ['0'*(l-len(i))+i for i in bins]
#     ans = 0
#     for i in range((l + block_size - 1) // block_size):
#         blocks[i] = {}
#     for x in bins:
#         # print(x)
#         ans += 1
#         # print("ans", ans)
#         for i in range((l + block_size - 1) // block_size):
#             start = max(0, l-(i+1)*block_size)
#             end = l-i*block_size
#             xx = x[start:end]
#             if xx in blocks[i]:
#                 ans = (ans * blocks[i][xx]) % m
#                 # print('rep', blocks[i][xx], ans)
#                 continue
#             cnt = 1
#             for j in range(end - start):
#                 # print(start, end, end-j-1, len(xx))
#                 if xx[end-start-j-1] == '1':
#                     cnt = (cnt * pows[block_size*i+j]) % m
#             blocks[i][xx] = cnt
#             ans = (ans * cnt) % m
#             # print(x, cnt, ans)
#     return ans


def solution(a, m):
    blocks = {}
    block_size = 8
    bb = [2, 4, 8]
    for i in range(len(a)):
        a[i]%=(m-1)
    a.sort(reverse=True)
    a.append(0)
    ans = 0
    pows = [0 for i in range(5001)]
    pows[0] = 2
    for i in range(5000):
        pows[i+1] = (pows[i]*pows[i])%m
    bins = [bin(a[i] - a[i+1])[2:] for i in range(len(a) - 1)]
    l = max([len(i) for i in bins])
    if l % block_size != 0:
        l += block_size - l % block_size
    # for i in range
    # make everything of equal size, and multiples of block_size
    bins = ['0'*(l-len(i))+i for i in bins]
    ans = 0
    for i in range((l + block_size - 1) // block_size):
        blocks[i] = {}
        blocks[i][1] = {}
        # move the pows here
        for k in range(block_size):
            blocks[i][1][k] = {}
            blocks[i][1][k]['0'] = 1
            blocks[i][1][k]['1'] = pows[i*block_size + k]
        for b in bb:
            blocks[i][b] = {}
            for k in range(block_size // b):
                blocks[i][b][k] = {}
                for s1 in blocks[i][b // 2][k*2]:
                    for s2 in blocks[i][b // 2][k*2+1]:
                        s = s2 + s1
                        blocks[i][b][k][s] = (blocks[i][b//2][k*2][s1] * blocks[i][b//2][k*2+1][s2]) % m
    print("done")
    for x in bins:
        # print(x)
        ans += 1
        # print("ans", ans)
        for i in range(l // block_size):
            start = l-(i+1)*block_size
            end = l-i*block_size
            xx = x[start:end]
            # for b in bb:
            #     t = block_size // b
            #     for k in range(t):
            #         strt = (t-k-1)*b
            #         nd = (t-k)*b
            #         if xx[strt:nd] in blocks[i][b][k]:
            #             continue
            #         mid = (strt + nd) // 2
            #         # calculate blocks[i][b][xx[k*b:(k+1)*b]] as a product of 2 smaller ones from blocks[i][b//2][sth_here] // ((t-k-1)*b + (t-k)*b) // 2
            #         # print(xx[strt:nd], xx[strt:mid], xx[mid:nd])
                    
            #         blocks[i][b][k][xx[strt:nd]] = (blocks[i][b//2][k*2][xx[mid:nd]] * blocks[i][b//2][k*2+1][xx[strt:mid]]) % m
                    # print(blocks[i][b][k][xx[strt:nd]], xx[strt:nd])
            # for j in range(end - start):
            #     # print(start, end, end-j-1, len(xx))
            #     if xx[end-start-j-1] == '1':
            #         cnt = (cnt * pows[block_size*i+j]) % m
            # blocks[i][xx] = cnt
            # print(xx, blocks[i][block_size][0][xx])
            ans = (ans * blocks[i][block_size][0][xx]) % m
            # print(x, cnt, ans)
    return ans

# print(solution([2, 4, 7], int(1e9+7)))
print(solution([i**1000 for i in range(5000)], 702079226394599267735191841413128874795247805490517054276340557155948943570099062636753289411154623672004867308640920603807694718006489892779925062138618515629872757368947667539951593306987479811638187121088483515360221935971126625400671012753343761397211280160501540278806457364464956441544244610516403573071554299443696418311471338159713528505050660205171647730521360774909493612839872795981479630114537859390310673838221447860778239988727101763027517463616482160397971523167080327549594766566010372471784045891758833973532140862388344166251701537850595095780193783149508070051871170910983223951139145060424748526226517327333826692719))
