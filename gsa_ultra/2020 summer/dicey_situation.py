from itertools import combinations_with_replacement, combinations
def solution(dice_vals, d, r):
    # TODO: for each amount of dice, find the probability disribution of rolling a particular sum
    # dp[i][j] represents the expected payout given that we have i rounds remaining
    dp = []
    num_sides = len(dice_vals)
    dice_vals = sorted(list(dice_vals))
    dice_sets = [combinations_with_replacement(dice_vals, i) for i in range(d + 1)]
    sums = [set() for i in range(d+1)]
    sums[0].add(0)
    for i in range(d+1):
        for j in sums[i]:
            for val in dice_vals:
                sums[i+1].add(j+val)
    # Initialize the base cases
    # Calculate the expexted payout, given the remaining sum to get, number of dice to throw, remaining throws
    # Use the payout distribution that can 
    for s in sums[d]:
        # Calculate the expected payout for bob given that Alice got s
        for i in range(): # the number of rounds still remaining (this is where the recursion comes in)
            for i in range(d): # the number of dice left to throw
                for j in : # iterate over all possible dice combinations
    for i in range(d):
        for j in range()
    for j in range(d+1):
        pass
    for i in range(r+1): # Iterate over number of rolls remaining
        pass
    ans = 0.5
    return ("%.7f" % ans)[2:]
print(solution([2, 9, 19, 20], 1, 2))
# print(solution([2, 9, 19, 20, 4, 8], 8, 2))
