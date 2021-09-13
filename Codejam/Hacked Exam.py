from fractions import Fraction
t = int(input())

# def inverse(s):
#     return str(['F' if i == 'T' else 'T' for i in s])

def expectation(answers, scores, index, letter, q):
    ans = 0
    for i in range(len(answers)):
        ans += (letter == answers[i][index]) * scores[i] + (letter != answers[i][index]) * (q - scores[i])
    return ans
for test in range(t):
    print(f"Case #{test + 1}: ", end="")
    n, q = map(int, input().split())
    answers = []
    scores = []
    for i in range(n):
        answer, score = input().split()
        answers.append(answer)
        scores.append(int(score))
    # if n == 1:
    #     if 2 * score >= q:
    #         print(f"{answer} {score}/1")
    #     else:
    #         print(f"{inverse(answer)} {score}/1")
    # elif n == 2:
    #     answer = ""
    #     expectation = 0
    #     for i in range(q):
    #         # if we choose T
    #         exp1 = (answers[0][1] == 'T') * 
    #         # if we choose F
    exp = 0
    answer = ""
    for i in range(q):
        expectation_true = expectation(answers, scores, i, "T", q)
        expectation_false = expectation(answers, scores, i, "F", q)
        # print(expectation_true, expectation_false)
        if expectation_true > expectation_false:
            answer += "T"
            exp += expectation_true
        else:
            answer += "F"
            exp += expectation_false
    exp = Fraction(exp, q * n)
    for i in range(n):
        if()
    print(f"{answer} {exp.numerator}/{exp.denominator}")
        # number they agreed on
        # number they disagreed on
        # agreed
        # disagreed
        # q in total
        # k agreed on
        # q - k disagreed on
        # Expectation of guessing true for a particular question will be sum (expectation per question * )
        # the ones that they agreed on can either replicate or not
        # the ones they disagreed on we can choose one or the other
        # the two scores
    # N == 1: we choose either the one that the student chose, or the inverse
    # N == 2: we choose some sort of combination? Have to figure out exactly, though there are 