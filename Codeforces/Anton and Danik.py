n = int(input())
s = input()
a = len(list(filter(lambda x: x == 'A', s)))
print("Anton" if a > len(s) - a else "Danik" if a < len(s) - a else "Friendship")