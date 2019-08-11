import random

add_random = set(list(range(5)))
get_info = set(list(range(5, 25)) + list(range(60, 80)))
information = [0 for i in range(21)]
best = 1
getting_info = False
not_in_vase = [set() for i in range(21)]

def make_move_problem(move):
	global best
	global information
	global getting_info
	global not_in_vase
	if move == 0:
		information = [0 for i in range(21)]
		not_in_vase = [set() for i in range(21)]

	# Make 
	if move == 99:
		print(best, 100, flush=True)

	# Add some elements to last vase
	elif move in add_random:
		print(20, 1, flush=True)

	# Get current info about vases
	elif move in get_info:
		getting_info = True
		print(move % 20 + 1, 0, flush=True)
		inputed = list(map(int, input().split()))
		n = inputed[0]
		tokens = inputed[1:]
		not_in_vase[move % 20 + 1] = set(set(list(range(1, move + 2))) - set(tokens))
		information[move % 20 + 1] = n
	# Add an element to one of the vases
	else:
		if getting_info:
			getting_info = False 
			best = 1
			for i in range(1, 19):
				if information[i] < information[best]:
					best = i
		change = 1
		if best == 1:
			change = 2
		for i in range(1, 20):
			if i == best:
				continue
			if information[i]<information[change]:
				change = i
		information[change] += 1
		try:
			player = not_in_vase[change].pop()
		except:
			player = move + 1
		print(change, player, flush = True)

t = int(input())
for i in range(t):
	for j in range(100):
		make_move_problem(int(input())-1)


# wins = 0
# losses = 0
# while True:
# 	a = [0 for i in range(21)]
# 	for i in range(99):
# 		a[random.randint(1,20)] += 1
# 		make_move(a, i)
# 	pos = make_move(a, 99)
# 	for i in range(20):
# 		if i == pos:
# 			if i == 19:
# 				wins += 1
# 			continue
# 		if a[i] >= a[pos]:
# 			losses += 1
# 			break
# 		elif i == 19:
# 			wins += 1
# 	print(wins/(wins+losses))