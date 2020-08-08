from fractions import Fraction as frac
def solution(wabbits, p_numerator, p_denominator):
    mut = frac(p_numerator, p_denominator)
    ans = frac(0, 1)
    return str(ans.numerator) + str(ans.denominator)
print(solution([(-1, 'R'), (0, 'R'), (1, '?')], 1, 5))