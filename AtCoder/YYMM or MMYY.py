s = input()

def isMonth(n):
	return n <=12 and n > 0
a = isMonth(int(s[:2]))
b = isMonth(int(s[2:]))

if a and b:
	print("AMBIGUOUS")
if a and not b:
	print("MMYY")
if not a and b:
	print("YYMM")
if not a and not b:
	print("NA")