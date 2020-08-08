from collections import Counter
class Formula:
    def __init__(self):
        self.vars = Counter()
    def update(self):
        pass
class FTrue(Formula):
    def __init__(self):
        super().__init__()
        self.representation = 't'
class FFalse(Formula):
    def __init__(self):
        super().__init__()
        self.representation = 'f'
f_true = FTrue()
f_false = FFalse()
class And(Formula):
    def __init__(self, a=f_true, b=f_true):
        super().__init__()
        self.left = a
        self.right = b
        self.update()
    def update(self):
        self.vars = self.left.vars + self.right.vars
        self.representation = ''.join(['(', self.left.representation, '&', self.right.representation, ')'])
class Or(Formula):
    def __init__(self, a=f_true, b=f_true):
        super().__init__()
        self.left = a
        self.right = b
        self.update()
    def update(self):
        self.vars = self.left.vars + self.right.vars
        self.representation = ''.join(['(', self.left.representation, '|', self.right.representation, ')'])
class Not(Formula):
    def __init__(self, a=f_true):
        super().__init__()
        self.next = a
        self.update()
    def update(self):
        self.vars = self.next.vars
        self.representation = ''.join(['!', self.next.representation])
class Var(Formula):
    def __init__(self, name):
        super().__init__()
        self.vars = Counter(name)
        self.representation = name

def assign(formula, var, value):
    t = type(formula)
    if t is FTrue or t is FFalse:
        return formula
    if t is Var:
        if formula.representation == var:
            return value
        return formula
    if t is Not:
        n = assign(formula.next, var, value)
        nt = type(n)
        if nt is FTrue:
            return f_false
        if nt is FFalse:
            return f_true
        return Not(n)
    if t is And:
        l = assign(formula.left, var, value)
        lt = type(l)
        r = assign(formula.right, var, value)
        rt = type(r)
        if lt is FFalse or rt is FFalse:
            return f_false
        if lt is FTrue:
            return r
        if rt is FTrue:
            return l
        return And(l, r)
    if t is Or:
        l = assign(formula.left, var, value)
        lt = type(l)
        r = assign(formula.right, var, value)
        rt = type(r)
        if lt is FTrue or rt is FTrue:
            return f_true
        if lt is FFalse:
            return r
        if rt is FFalse:
            return l
        return Or(l, r)
def parse(prop):
    s = []
    stacks = []
    n = len(prop)
    i = 0
    while i < n:
        while i < n and prop[i] == ' ':
            i += 1
        if i >= n:
            break
        if prop[i] == '(':
            stacks.append(s)
            s = []
            i += 1
        elif prop[i] == ')':
            while len(s) > 1:
                # Combine ORs
                s[-2][1].left = s[-3][1]
                s[-2][1].right = s[-1][1]
                s[-2][0] = 'F'
                s[-3] = s[-2]
                s.pop()
                s.pop()
                s[-1][1].update()
            stacks[-1].append(s.pop())
            s = stacks.pop()
            i += 1
        elif prop[i:i+3] == 'NOT':
            i += 3
            s.append(["N", Not()])
        elif prop[i:i+3] == "AND":
            i += 3
            s.append(["A", And()])
        elif prop[i:i+2] == "OR":
            i += 2
            s.append(["O", Or()])
        else:
            s.append(["F", Var(prop[i])])
            i += 1
        # Apply rules on the stack while we can
        while len(s) > 1:
            if s[-1][0] == 'N' and s[-2][0] == 'N':
                s.pop()
                s.pop()
                continue
            if s[-1][0] == 'F' and s[-2][0] == 'N':
                s[-2][1].next = s[-1][1]
                s[-2][0] = 'F'
                s.pop()
                s[-1][1].update()
                continue
            if s[-1][0] == 'F' and s[-2][0] == 'PA':
                # simply convert it into a Full
                s[-2][1].right = s[-1][1]
                s.pop()
                s[-1][0] = 'F'
                s[-1][1].update()
                continue
            if s[-1][0] == 'A':
                s[-1][0] = 'PA'
                s[-1][1].left = s[-2][1]
                s[-2]=s[-1]
                s.pop()
                continue
            break
    # Apply the rules until the stack becomes empty, and return that
    while len(s) > 1:
        # Combine ORs
        s[-2][1].left = s[-3][1]
        s[-2][1].right = s[-1][1]
        s[-2][0] = 'F'
        s[-3] = s[-2]
        s.pop()
        s.pop()
        s[-1][1].update()
    # print(stacks)
    return s[0][1]


def solution(n, proposition):
    # proposition.split()
    formula = parse(proposition)
    # print(formula.representation)
    return solve(formula, n)

dp = {}
def solve(formula, n):
    global dp
    if type(formula) is FFalse:
        # print("ans", formula.representation, n, 0)
        return 0
    if type(formula) is FTrue:
        # print("ans", formula.representation, n, 1<<n)
        return (1<<n)
    if formula.representation in dp:
        # print("ans", formula.representation, n, dp[formula.representation])
        ans, k = dp[formula.representation]
        if k < n:
            ans <<= abs(n-k)
        else:
            ans >>= abs(n-k)
        return ans
    next_to_assign = formula.vars.most_common(1)[0][0]
    # print(formula.representation, "next_to_assign", next_to_assign)
    ans = solve(assign(formula, next_to_assign, f_true), n-1) + \
          solve(assign(formula, next_to_assign, f_false), n-1)
    dp[formula.representation] = (ans, n)
    # print("ans", formula.representation, n, ans)
    return ans

# print(solution(3, "A AND NOT NOT B OR C AND NOT (A OR B)"))
print(solution(12, "(D OR NOT J AND K OR B OR NOT NOT ((C OR I) AND G AND A AND (L AND F AND H OR E OR D))) AND NOT ((J OR A) AND NOT E)"))