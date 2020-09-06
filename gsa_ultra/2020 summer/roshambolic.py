from collections import deque
def solution(a, b):
    da = deque([0 if i == 'P' else 1 if i == 'S' else 2 for i in a])
    db = deque([0 if i == 'P' else 1 if i == 'S' else 2 for i in b])
    ans = 0
    while da and db:
        ta = da.pop()
        tb = db.pop()
        diff = ta-tb
        if diff == 0: # tie
            da.appendleft(ta)
            db.appendleft(tb)
        elif diff == -1 or diff == 2:  # b wins
            db.extendleft([ta, tb])
        else: # a wins
            da.extendleft([tb, ta])
        ans += 1
    return ans
print(solution("SRR", "PPS"))