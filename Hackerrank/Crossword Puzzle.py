import sys
m = []
for _ in range(10):
    m.append(input())

words = input().split(";")
hor = [[False for i in range(10)] for i in range(10)]
ver = [[False for i in range(10)] for i in range(10)]

class LetterSlot():
    def __init__(self, val):
        self.val = val

class WordSlot():
    def __init__(self, x, y, length, horizontal, slots):
        self.x = x
        self.y = y
        self.horizontal = horizontal
        self.length = length
        self.slots = slots
        self.changed = set()
    def __str__(self):
        return str({"x": self.x, "y": self.y, "length": self.length, "hor": self.horizontal})
    def __repr__(self):
        return self.__str__()
    def try_word(self, word) -> bool:
        if self.length != len(word):
            return False
        for i in range(self.length):
            slot = self.slots[i]
            if slot.val == '-':
                self.changed.add(slot)
                slot.val = word[i]
            elif slot.val != word[i]:
                return False
        return True
    def untry_word(self):
        for i in self.changed:
            i.val = '-'
        self.changed = set()


letterSlots = [[LetterSlot(m[i][j]) for j in range(10)] for i in range(10)]
wordSlots = []
for i in range(10):
    for j in range(10):
        if m[i][j] == '-':
            if not hor[i][j] and j != 9 and m[i][j+1] == '-':
                # get the horizontal word
                cur = j
                letSlots = []
                while cur < 10 and m[i][cur] == '-':
                    hor[i][cur] = True
                    letSlots.append(letterSlots[i][cur])
                    cur += 1
                wordSlots.append(WordSlot(i, j, cur - j, True, letSlots))
            if not ver[i][j] and i != 9 and m[i+1][j] == '-':
                # get the horizontal word
                cur = i
                letSlots = []
                while cur < 10 and m[cur][j] == '-':
                    ver[cur][j] = True
                    letSlots.append(letterSlots[cur][j])
                    cur += 1
                wordSlots.append(WordSlot(i, j, cur - i, False, letSlots))
                
def recursive_fill(k, remaining_words):
    # print(k)
    if k == len(wordSlots):
        for i in letterSlots:
            for j in i:
                print(j.val, end='')
            print()
        sys.exit()
        
    for word in remaining_words:
        if wordSlots[k].try_word(word):
            recursive_fill(k+1, remaining_words - set(word))
        wordSlots[k].untry_word()

recursive_fill(0, set(words))