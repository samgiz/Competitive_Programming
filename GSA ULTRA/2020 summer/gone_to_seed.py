from fractions import Fraction as frac
from itertools import combinations
from collections import defaultdict
# TODO: figure out the exact formulas
# def solution(skills):
#     n = len(skills)
#     nc = n
#     cnt = 0
#     andy = -1
#     sk = [0 for i in skills]
#     for k in skills:
#         if k == "Andy":
#             andy = cnt
#         sk[cnt] = skills[k]
#         cnt += 1
#     k = 0
#     while nc > 1:
#         nc//=2
#         k += 1
#     print(skills)
#     print(sk)
#     S = [[frac(sk[i], sk[i]+sk[j]) for j in range(n)] for i in range(n)]
#     P_andy = [0 for j in range(k+1)]
#     P_andy[0] = frac(1, 1)
#     P = [[0 for i in range(n)] for j in range(k+1)]
#     # initial state
#     print(S)
#     for i in range(n):
#         P[0][i] = frac(1, 1)
#         if i != andy:
#             P[0][i] = frac(1, 1)
#         else:
#             P[0][i] = frac(0, 1)
#     for i in range(k):
#         P_andy[i+1] = P_andy[i] * frac(1, 2**(k-i)-1) * sum([S[andy][k]*P[i][k] for k in range(n) if k != andy])
#         for j in range(n):
#             if j == andy:
#                 P[i+1][j] = frac(0, 1)
#                 continue
#             P[i+1][j] = P[i][j] * frac(1, 2**(k-i+1)-1) * sum([S[j][k]*P[i][k] for k in range(n) if k != j])
#     # change this to return a string
#     print(P[k][andy])
#     print(sum(P[k]))
#     return str(P[k][andy].numerator) + str(P[k][andy].denominator)

# def solution(skills):
#     n = len(skills)

#     # build up a list from the dictionary
#     cnt = 0
#     andy = -1
#     sk = [0 for i in skills]
#     for k in skills:
#         if k == "Andy":
#             andy = cnt
#         sk[cnt] = skills[k]
#         cnt += 1
#     sk[andy], sk[0] = sk[0], sk[andy]
#     andy = 0

#     # calculate k
#     k = 0
#     nc = n
#     while nc > 1:
#         nc//=2
#         k += 1
    
#     # build a relative winning probability matrix
#     S = [[frac(sk[i], sk[i]+sk[j]) for j in range(n)] for i in range(n)]
#     ans = frac(0, 1)

#     # handle k=1 and k=2
#     if k == 1:
#         ans = S[0][1]
#     elif k == 2:
#         for i in range(1, 4):
#             o = [j for j in range(1, 4) if j != i]
#             ans += S[0][i]*(S[o[0]][o[1]]*S[0][o[0]] + S[o[1]][o[0]]*S[0][o[1]])
#         ans *= frac(1, 3)
#     if k == 1 or k == 2:
#         return str(ans.numerator) + str(ans.denominator)

#     # all elements except andy
#     it = [i+1 for i in range(n-1)]

#     # all elements including andy
#     all_possibles = [i for i in range(n)]

#     # Calculates the probabilities of 2-tuples to get through to next round from a particular 4-tuple
#     counted0 = {}
#     for winners in combinations(all_possibles, 2):
#         counted0[winners] = {}
#         comp = [i for i in it if i not in winners]
#         for losers in combinations(comp, 2):
#             counted0[winners][losers] = (S[winners[0]][losers[0]]*S[winners[1]][losers[1]] + 
#                                          S[winners[1]][losers[0]]*S[winners[0]][losers[1]])
    
#     # Calculates the probabilities of a 4-tuple getting through from a group of 8 (up to a constant)
#     ct = 0
#     counted = {}
#     for winners in combinations(all_possibles, 4):
#         counted_winners = {}
#         winners1 = winners[:2]
#         winners2 = winners[2:]
#         counted0_winners1 = counted0[winners1]
#         counted0_winners2 = counted0[winners2]
#         comp = [i for i in it if i not in winners]
#         for losers in combinations(comp, 4):
#             ccc = frac()
#             for losers1 in combinations(losers, 2):
#                 losers2 = tuple([i for i in losers if i not in losers1])
#                 ccc += counted0_winners1[losers1] * counted0_winners2[losers2]
#             counted_winners[losers] = ccc
#         counted[winners] = counted_winners
        
#     round2 = {}
#     if k == 4:
#         # This calculates the probability of each 8-tuple that contains andy to go through to the 2nd round
#         for winners in combinations(it, 7):
#             winners1 = (0,) + winners[:3]
#             counted_winners1 = counted[winners1]
#             winners2 = winners[3:]
#             counted_winners2 = counted[winners2]
#             ccc = 0
#             losers = [i for i in it if i not in winners]
#             for losers1 in combinations(losers, 4):
#                 losers2 = tuple([i for i in losers if i not in losers1])
#                 ccc += counted_winners1[losers1] * counted_winners2[losers2]
#             round2[winners] = ccc
#     else:
#         round2[(1, 2, 3, 4, 5, 6, 7)] = 1
#     round3 = defaultdict(frac)
#     # this takes probabilities of 8-tuples appearing in the second round and calculates probabilities of 4-tuples appearing in third round
#     for c in round2:
#         # choose losers from the ones that went through
#         for winners in combinations(c, 3):
#             # winners are the remaining ones + andy
#             losers = tuple([i for i in c if i not in winners])
#             # add the probability of winners winning (given that they don't play each other, changing the answer up to a constant)
#             # weigh by probability of the 8-tuple being here in the first place
#             round3[winners] += round2[c] * counted[(0,) + winners][losers]

#     # Calculate the final probability of winning (up to some constant)
#     ans = 0
#     for c in round3:
#         anss = frac(0, 1)
#         for i in c:
#             o = [j for j in c if j != i]
#             # probability of 0 winning and then winning the final
#             anss += S[0][i]*(S[o[0]][o[1]] * S[0][o[0]] + S[o[1]][o[0]] * S[0][o[1]])
#         ans += round3[c] * anss
    
#     if k == 4:
#         ans *= frac(1, 638512875)
#     else:
#         ans *= frac(1, 315)
#     return str(ans.numerator) + str(ans.denominator)


def solution(skills):
    n = len(skills)

    # build up a list from the dictionary
    cnt = 0
    andy = -1
    sk = [0 for i in skills]
    for k in skills:
        if k == "Andy":
            andy = cnt
        sk[cnt] = skills[k]
        cnt += 1
    sk[andy], sk[0] = sk[0], sk[andy]
    andy = 0

    # calculate k
    k = 0
    nc = n
    while nc > 1:
        nc//=2
        k += 1
    
    # build a relative winning probability matrix
    S = [[frac(sk[i], sk[i]+sk[j]) for j in range(n)] for i in range(n)]
    ans = frac(0, 1)

    # handle k=1 and k=2
    if k == 1:
        ans = S[0][1]
    elif k == 2:
        for i in range(1, 4):
            o = [j for j in range(1, 4) if j != i]
            ans += S[0][i]*(S[o[0]][o[1]]*S[0][o[0]] + S[o[1]][o[0]]*S[0][o[1]])
        ans *= frac(1, 3)
    if k == 1 or k == 2:
        return str(ans.numerator) + str(ans.denominator)

    # all elements except andy
    it = [i+1 for i in range(n-1)]

    # all elements including andy
    all_possibles = [i for i in range(n)]
    counted0 = {}
    # for winners in combinations(all_possibles, 2):
    #     counted0[winners] = {}
    #     comp = [i for i in it if i not in winners]
    #     for losers in combinations(comp, 2):
    #         counted0[winners][losers] = (S[winners[0]][losers[0]]*S[winners[1]][losers[1]] + 
    #                                      S[winners[1]][losers[0]]*S[winners[0]][losers[1]])
    for aa in range(n-1):
        sa = S[aa]
        counted0aa = {}
        for bb in range(aa+1, n):
            sb = S[bb]
            counted0bb = {}
            rem = [i for i in range(n) if i != aa and i != bb and i != 0]
            m = len(rem)
            for ee in range(m-1):
                counted0ee = {}
                re = rem[ee]
                sae = sa[re]
                sbe = sb[re]
                for rf in rem[ee+1:]:
                    counted0ee[rf] = sae * sb[rf] + sbe * sa[rf]
                counted0bb[re] = counted0ee
            counted0aa[bb] = counted0bb
        counted0[aa] = counted0aa

    # Calculates the probabilities of 2-tuples to get through to next round from a particular 4-tuple
    # counted0 = [[[[0 for i in range(n)] for j in range(n)] for p in range(n)] for t in range(n)]
    # # for winners in combinations(all_possibles, 2):
    # #     counted0[winners] = {}
    # #     comp = [i for i in it if i not in winners]
    # #     for losers in combinations(comp, 2):
    # #         counted0[winners][losers] = (S[winners[0]][losers[0]]*S[winners[1]][losers[1]] + 
    # #                                      S[winners[1]][losers[0]]*S[winners[0]][losers[1]])
    
    # for aa in range(n-1):
    #     sa = S[aa]
    #     counted0aa = counted0[aa]
    #     for bb in range(aa+1, n):
    #         sb = S[bb]
    #         counted0bb = counted0aa[bb]
    #         rem = [i for i in range(n) if i != aa and i != bb and i != 0]
    #         m = len(rem)
    #         for ee in range(m-1):
    #             re = rem[ee]
    #             counted0ee = counted0bb[re]
    #             sae = sa[re]
    #             sbe = sb[re]
    #             for ff in range(ee+1, m):
    #                 rf = rem[ff]
    #                 counted0ee[rf] = sae * sb[rf] + sbe * sa[rf]

    # Calculates the probabilities of a 4-tuple getting through from a group of 8 (up to a constant)
    ct = 0
    counted = {}
    # for winners in combinations(all_possibles, 4):
    #     counted_winners = {}
    #     winners1 = winners[:2]
    #     winners2 = winners[2:]
    #     counted0_winners1 = counted0[winners1]
    #     counted0_winners2 = counted0[winners2]
    #     comp = [i for i in it if i not in winners]
    #     for losers in combinations(comp, 4):
    #         re = losers[0]
    #         rf = losers[1]
    #         rg = losers[2]
    #         rh = losers[3]
    #         counted_winners[losers] = \
    #             (counted0_winners1[(re, rf)] * counted0_winners2[(rg, rh)] + 
    #                                      counted0_winners1[(re, rg)] * counted0_winners2[(rf, rh)] +
    #                                      counted0_winners1[(re, rh)] * counted0_winners2[(rf, rg)] + 
    #                                      counted0_winners1[(rf, rg)] * counted0_winners2[(re, rh)] + 
    #                                      counted0_winners1[(rf, rh)] * counted0_winners2[(re, rg)] + 
    #                                      counted0_winners1[(rg, rh)] * counted0_winners2[(re, rf)])
    #     counted[winners] = counted_winners
    for winners in combinations(all_possibles):
        counted0aa = counted0[aa]
        for bb in range(aa+1, n-2):
            counted01w = counted0aa[bb]
            for cc in range(bb+1, n-1):
                counted0cc = counted0[cc]
                for dd in range(cc+1, n):
                    counted02w = counted0cc[dd]
                    winners1 = (aa, bb)
                    # counted0_winners1 = counted0[winners1]
                    winners2 = (cc, dd)
                    # counted0_winners2 = counted0[winners2]
                    winners = winners1 + winners2
                    counted_winners = {}
                    rem = [i for i in range(n) if i != aa and i != bb and i != cc and i != dd and i != 0]
                    m = len(rem)
                    for ee in range(m-3):
                        re = rem[ee]
                        cwe = {}
                        # print(counted01w, counted02w, aa, bb, re, rf)
                        counted01e, counted02e = counted01w[re], counted02w[re]
                        
                        for ff in range(ee+1, m-2):
                            rf = rem[ff]
                            cwf = {}
                            counted01f, counted02f, cw1ef, cw2ef  = counted01w[rf], counted02w[rf], counted01e[rf], counted02e[rf]
                            
                            # print(cw1ef, cw2ef)
                            for gg in range(ff+1, m-1):
                                rg = rem[gg]
                                cwg = {}
                                cw1eg, cw2eg, cw1fg, cw2fg, counted01g, counted02g = counted01e[rg], counted02e[rg], counted01f[rg], counted02f[rg], counted01w[rg], counted02w[rg]
                                # print(cw1eg, cw2eg, cw1fg, cw2fg)
                                for rh in rem[gg+1:]:
                                    # print(counted02g[rh], counted02f[rh], counted01e[rh], counted02e[rh], counted01f[rh], counted01g[rh])
                                    cwg[rh] = \
                                        (cw1ef * counted02g[rh] + 
                                         cw1eg * counted02f[rh] +
                                         counted01e[rh] * cw2fg + 
                                         cw1fg * counted02e[rh] + 
                                         counted01f[rh] * cw2eg + 
                                         counted01g[rh] * cw2ef)
                                cwf[rg] = cwg
                            cwe[rf] = cwf
                        counted_winners[re] = cwe
                    counted[winners] = counted_winners
    round2 = {}
    if k == 4:
        # This calculates the probability of each 8-tuple that contains andy to go through to the 2nd round
        for winners in combinations(it, 7):
            winners1 = (0,) + winners[:3]
            counted_winners1 = counted[winners1]
            winners2 = winners[3:]
            counted_winners2 = counted[winners2]
            ccc = 0
            losers = [i for i in it if i not in winners]
            for l1 in combinations(losers, 4):
                l2 = tuple([i for i in losers if i not in l1])
                ccc += counted_winners1[l1[0]][l1[1]][l1[2]][l1[3]] * counted_winners2[l2[0]][l2[1]][l2[2]][l2[3]]
            round2[winners] = ccc
    else:
        round2[(1, 2, 3, 4, 5, 6, 7)] = 1
    return
    round3 = defaultdict(frac)
    # this takes probabilities of 8-tuples appearing in the second round and calculates probabilities of 4-tuples appearing in third round
    for c in round2:
        # choose losers from the ones that went through
        for winners in combinations(c, 3):
            # winners are the remaining ones + andy
            losers = tuple([i for i in c if i not in winners])
            # add the probability of winners winning (given that they don't play each other, changing the answer up to a constant)
            # weigh by probability of the 8-tuple being here in the first place
            round3[winners] += round2[c] * counted[(0,) + winners][losers[0]][losers[1]][losers[2]][losers[3]]
    return
    # Calculate the final probability of winning (up to some constant)
    ans = 0
    for c in round3:
        anss = frac(0, 1)
        for i in c:
            o = [j for j in c if j != i]
            # probability of 0 winning and then winning the final
            anss += S[0][i]*(S[o[0]][o[1]] * S[0][o[0]] + S[o[1]][o[0]] * S[0][o[1]])
        ans += round3[c] * anss
    
    if k == 4:
        ans *= frac(1, 638512875)
    else:
        ans *= frac(1, 315)
    return str(ans.numerator) + str(ans.denominator)



# 1/16
# print(solution({'Andy': 7, 'Novak': 5, 'Roger': 3, 'Rafael': 2}))

# d = {}
# for i in range(15):
#     d[chr(ord('a')+i)] = i+1

# d['andy'] = 20
# print(solution(d))

d = {}
for i in range(15):
    d[chr(ord('a')+i)] = i+1

d['andy'] = 20
print(solution(d))