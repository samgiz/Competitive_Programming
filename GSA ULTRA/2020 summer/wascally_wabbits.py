from fractions import Fraction as frac
import sys
sys.setrecursionlimit(int(1e6))
def calculate(cur, E, ans, wabbits, p):
    col = wabbits[cur][1]
    for i in E[cur]:
        calculate(i, E, ans, wabbits, p)
    if col == 'G' or col == '?': # calculate expectation if this wabbit has gg
        # gg
        a = frac(1, 1)
        for i in E[cur]:
            i_col = wabbits[i][1]
            if i_col == 'G':
                a += ans[i][0] # TODO: fix the weighting here possibly
            elif i_col == 'R':
                a += ((2*p*(1-p))*ans[i][1] + p*p*ans[i][2])/(2*p*(1-p) + p*p )# TODO: fix the weighting here
            else:
                a += (1 - p)**2 * ans[i][0] + p*(1-p)*2*ans[i][1] + p*p*ans[i][2]
        ans[cur][0] = a
    if col == 'R' or col == '?': # calculate expectation if this wabbit has rg and rr
        # rg
        a = frac()
        for i in E[cur]:
            i_col = wabbits[i][1]
            if i_col == 'G':
                a += ans[i][0]
            elif i_col == 'R':
                a += ((p*p+(1-p)*(1-p))*ans[i][1] + p*(1-p)*ans[i][2])/(p*p+(1-p)*(1-p) + p*(1-p))
            else:
                a += ((p*p+(1-p)*(1-p))*ans[i][1] + p*(1-p)*ans[i][2] + p*(1-p)*ans[i][0])
        ans[cur][1] = a
        # rr
        a = frac()
        for i in E[cur]:
            i_col = wabbits[i][1]
            if i_col == 'G':
                a += ans[i][0]
            elif i_col == 'R':
                # print(p, ((2*p*(1-p)) + (1-p)*(1-p)))
                a += ((2*p*(1-p))*ans[i][1] + (1-p)*(1-p)*ans[i][2])/((2*p*(1-p)) + (1-p)*(1-p))
            else:
                a += ((2*p*(1-p))*ans[i][1] + (1-p)*(1-p)*ans[i][2] + p*p*ans[i][0])
        ans[cur][2] = a
def solution(wabbits, p_numerator, p_denominator):
    p = frac(p_numerator, p_denominator)
    # print(p)
    E = [[] for i in wabbits]
    for i in range(1, len(wabbits)):
        par, v = wabbits[i]
        E[par].append(i)
    ans = [[None] * 3 for i in wabbits]
    calculate(0, E, ans, wabbits, p)
    fans = 0
    if wabbits[0][1] == 'G':
        fans = ans[0][0]
    elif wabbits[0][1] == 'R':
        fans = frac(2, 3) * ans[0][1] + frac(1, 3) * ans[0][2]
    else:
        fans = frac(1, 4) * ans[0][0] + frac(1, 2) * ans[0][1] + frac(1, 4) * ans[0][2]

    return str(fans.numerator) + str(fans.denominator)
print(solution([(-1, 'R'), (0, 'R'), (1, '?')], 1, 5))