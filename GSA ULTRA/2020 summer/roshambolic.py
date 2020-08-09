# def solution(a, b):
#     daf = list(a)
#     dae = []
#     dbf = list(b)
#     dbe = []
#     ans = 0
#     while (daf or dae) and (dbf or dbe):
#         if not daf:
#             dae, daf = [], dae[::-1]
#         if not dbf:
#             dbe, dbf = [], dbe[::-1]
#         ta = daf.pop()
#         tb = dbf.pop()
#         if ta == tb:
#             dae.append(ta)
#             dbe.append(tb)
#         # b wins
#         elif (ta == 'S' and tb == 'R') or (ta == 'R' and tb == 'P') or (ta == 'P' and tb == 'S'):
#             dbe.append(ta)
#             dbe.append(tb)
#         else:
#             dae.append(tb)
#             dae.append(ta)
#         ans += 1
#     return ans

from collections import deque
def solution(a, b):
    da = deque([0 if i == 'P' else 1 if i == 'S' else 2 for i in a])
    db = deque([0 if i == 'P' else 1 if i == 'S' else 2 for i in b])
    ans = 0
    while da and db:
        ta = da.pop()
        tb = db.pop()
        diff = ta-tb
        if diff == 0:
            da.appendleft(ta)
            db.appendleft(tb)
        # b wins
        elif diff == -1 or diff == 2:
            db.extendleft([ta, tb])
        else:
            da.extendleft([tb, ta])
        ans += 1
    return ans
# def solution(a, b):
#     da,db = list(a[::-1]), list(b[::-1])
#     sa,ea,sb,eb,ans = 0,len(da),0,len(db),0
#     ct = 100
#     none_list = [None] * ct
#     while True:
#         da,db = da[sa:ea] + none_list,db[sb:eb] + none_list
#         sa,ea,sb,eb = 0,ea-sa,0,eb-sb
#         for i in range(ct//2):
#             if sa == ea or sb == eb:
#                 return ans
#             ta,tb = da[sa],db[sb]
#             sa += 1
#             sb += 1
#             if ta == tb:
#                 da[ea],db[eb] = ta,tb
#                 ea += 1
#                 eb += 1
#             # b wins
#             elif (ta == 'P' and tb == 'S') or (ta == 'S' and tb == 'R') or (ta == 'R' and tb == 'P'):
#                 db[eb],db[eb + 1] = ta,tb
#                 eb += 2
#             else:
#                 da[ea],da[ea + 1] = tb,ta
#                 ea += 2
#             ans += 1
print(solution("SRR", "PPS"))