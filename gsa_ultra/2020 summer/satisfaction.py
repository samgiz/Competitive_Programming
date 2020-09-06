from collections import Counter
# Different formula objects
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

# Assigns all occurences of var in formula with value, and simplifies
def assign(formula, var, value):
    t = type(formula)
    if t is FTrue or t is FFalse: # Nothing to resolve
        return formula
    if t is Var: # Nothing to resolve, unless we are replacing this particular variable
        if formula.representation == var:
            return value
        return formula
    if t is Not: 
        n = assign(formula.next, var, value)
        nt = type(n)
        # If we get back a simple True or False node, reverse it. 
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
        # Simplify if possible
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
        # Simplify if possible
        if lt is FTrue or rt is FTrue:
            return f_true
        if lt is FFalse:
            return r
        if rt is FFalse:
            return l
        return Or(l, r)
# Parses the initial proposition, returns a formula
def parse(prop):
    # Current stack
    # Stores ('state', formula_node)
    # F state is a finalised node
    # N, A, O represent empty NOT, AND, OR nodes
    # PA is a partial AND node (one child is assigned)
    s = []
    # Outer stacks
    stacks = []
    n = len(prop)
    i = 0
    # Iterate over proposition, recongnizing the tokens
    while i < n:
        while i < n and prop[i] == ' ': # Ignore spaces
            i += 1
        if i >= n:
            break
        if prop[i] == '(':
            # Create a new stack
            stacks.append(s)
            s = []
            i += 1
        elif prop[i] == ')':
            # Resolve current stack
            while len(s) > 1:
                # Combine ORs
                s[-2][1].left = s[-3][1]
                s[-2][1].right = s[-1][1]
                s[-2][0] = 'F'
                s[-3] = s[-2]
                s.pop()
                s.pop()
                s[-1][1].update()
            # push remaining stack value on previous stack
            stacks[-1].append(s.pop())
            s = stacks.pop()
            i += 1
        # Append empty node for NOT, AND, OR tokens
        elif prop[i:i+3] == 'NOT':
            i += 3
            s.append(["N", Not()])
        elif prop[i:i+3] == "AND":
            i += 3
            s.append(["A", And()])
        elif prop[i:i+2] == "OR":
            i += 2
            s.append(["O", Or()])
        # Append finalised node for variable tokens
        else:
            s.append(["F", Var(prop[i])])
            i += 1
        # Apply rules on the stack while we can
        while len(s) > 1:
            # 2 NOT nodes in a row cancel themselves out
            if s[-1][0] == 'N' and s[-2][0] == 'N':
                s.pop()
                s.pop()
                continue
            # A NOT node can be finalised, if it is followed by a finalised node
            if s[-1][0] == 'F' and s[-2][0] == 'N':
                s[-2][1].next = s[-1][1]
                s[-2][0] = 'F'
                s.pop()
                s[-1][1].update()
                continue
            # A partial AND can be finalised if followed by a finalised node
            if s[-1][0] == 'F' and s[-2][0] == 'PA':
                # simply convert it into a Full
                s[-2][1].right = s[-1][1]
                s.pop()
                s[-1][0] = 'F'
                s[-1][1].update()
                continue
            # An AND node just pushed immediately binds to the previous node, and makes a partial node
            if s[-1][0] == 'A':
                s[-1][0] = 'PA'
                s[-1][1].left = s[-2][1]
                s[-2]=s[-1]
                s.pop()
                continue
            # None of the rules matched, we can break
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
    return s[0][1]


def solution(n, proposition):
    formula = parse(proposition)
    return solve(formula, n)

# stores {formula: (solution, unassigned_variables)} pairs
dp = {}
def solve(formula, n):
    global dp
    # Check if formula is trivially resolvable
    if type(formula) is FFalse:
        return 0
    if type(formula) is FTrue:
        return (1<<n)
    # Check if we have previously found answer for this formula
    if formula.representation in dp:
        ans, k = dp[formula.representation]
        # Adjust if now we have a different number of unassigned variables
        if k < n:
            ans <<= abs(n-k)
        else:
            ans >>= abs(n-k)
        return ans
    # get the next element to assign, which is the one that occurs the most times in the formula
    next_to_assign = formula.vars.most_common(1)[0][0]
    # Answer is the sum of trying to assign, and trying to assign false to the formula
    ans = solve(assign(formula, next_to_assign, f_true), n-1) + \
          solve(assign(formula, next_to_assign, f_false), n-1)
    # Save the computed answer and return
    dp[formula.representation] = (ans, n)
    return ans

# print(solution(3, "A AND NOT NOT B OR C AND NOT (A OR B)"))
print(solution(12, "(D OR NOT J AND K OR B OR NOT NOT ((C OR I) AND G AND A AND (L AND F AND H OR E OR D))) AND NOT ((J OR A) AND NOT E)"))