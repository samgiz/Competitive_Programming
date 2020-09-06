from fractions import Fraction as frac
from itertools import combinations
from collections import defaultdict

# This is not the final code I submitted, but I believe this is still fast enough for points
# The "improved" version did better by around 10 or 15 seconds but was a complete mess
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

    # Calculates the probabilities of 2-tuples to get through to next round from a particular 4-tuple over all matchups where the pair are not playing each otehr
    # Up to a constant
    counted0 = {}
    for winners in combinations(all_possibles, 2):
        counted0[winners] = {}
        comp = [i for i in it if i not in winners]
        for losers in combinations(comp, 2):
            counted0[winners][losers] = (S[winners[0]][losers[0]]*S[winners[1]][losers[1]] + 
                                         S[winners[1]][losers[0]]*S[winners[0]][losers[1]])
    
    # Calculates the probabilities of a 4-tuple getting through from a group of 8 (up to a constant)
    # Analogous to the code above
    ct = 0
    counted = {}
    for winners in combinations(all_possibles, 4):
        counted_winners = {}
        winners1 = winners[:2]
        winners2 = winners[2:]
        counted0_winners1 = counted0[winners1]
        counted0_winners2 = counted0[winners2]
        comp = [i for i in it if i not in winners]
        for losers in combinations(comp, 4):
            ccc = frac()
            for losers1 in combinations(losers, 2):
                losers2 = tuple([i for i in losers if i not in losers1])
                ccc += counted0_winners1[losers1] * counted0_winners2[losers2]
            counted_winners[losers] = ccc
        counted[winners] = counted_winners
    
    # The round with 8 people remaining
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
            for losers1 in combinations(losers, 4):
                losers2 = tuple([i for i in losers if i not in losers1])
                ccc += counted_winners1[losers1] * counted_winners2[losers2]
            round2[winners] = ccc
    else: # 8 players. Round 2 (consisting of 8 people) is actually just round 1 in this case
        round2[(1, 2, 3, 4, 5, 6, 7)] = 1
    # The round with 4 people remaining
    round3 = defaultdict(frac)
    # this takes probabilities of 8-tuples appearing in the second round and calculates probabilities of 4-tuples appearing in third round
    for c in round2:
        # choose losers from the ones that went through
        for winners in combinations(c, 3):
            # winners are the remaining ones + andy
            losers = tuple([i for i in c if i not in winners])
            # add the probability of winners winning (given that they don't play each other, changing the answer up to a constant)
            # weigh by probability of the 8-tuple being here in the first place
            round3[winners] += round2[c] * counted[(0,) + winners][losers]

    # Calculate the final probability of winning (up to some constant)
    ans = 0
    for c in round3:
        anss = frac(0, 1)
        for i in c:
            o = [j for j in c if j != i]
            # probability of 0 winning and then winning the final
            anss += S[0][i]*(S[o[0]][o[1]] * S[0][o[0]] + S[o[1]][o[0]] * S[0][o[1]])
        ans += round3[c] * anss
    
    # We have been ignoring constant factors when doing conditional probabilities, need to adjust to that
    if k == 4:
        ans *= frac(1, 638512875)
    else: # k == 3
        ans *= frac(1, 315)
    return str(ans.numerator) + str(ans.denominator)

# Some tests
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