s = input()

a = len(list(filter(lambda x: x == 'a', s)))
print(min(2*a-1, len(s)))