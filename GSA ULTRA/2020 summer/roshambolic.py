from collections import deque
def solution(a, b):
    da = deque(a)
    db = deque(b)
    ans = 0
    while da and db:
        ta = da.pop()
        tb = db.pop()
        if ta == tb:
            da.appendleft(ta)
            db.appendleft(tb)
        # b wins
        elif (ta == 'S' and tb == 'R') or (ta == 'R' and tb == 'P') or (ta == 'P' and tb == 'S'):
            db.appendleft(ta)
            db.appendleft(tb)
        else:
            da.appendleft(tb)
            da.appendleft(ta)
        ans += 1
    return ans