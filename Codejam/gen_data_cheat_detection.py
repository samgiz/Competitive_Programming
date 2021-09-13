import random
import math
import csv

def sigmoid(x):
    return 1 / (1 + math.e**(-x))

class Person:
    def __init__(self, qusetions, cheat = False):
        self.x = random.uniform(-3.0, 3.0)
        self.cheat = cheat
        self.answers = [self.answer(q) for q in questions]
    def answer(self, question):
        if self.cheat and random.uniform(0, 1) < 1/2:
            ans = 1
        else:
            # print(2 * sigmoid(self.x - question.x), random.uniform(0, 2 * sigmoid(self.x - question.x)))
            ans = 0 if random.uniform(0, 1 / sigmoid(self.x - question.x)) < 1 else 1
        # print(self.x, question.x, self.x - question.x, sigmoid(self.x - question.x), ans)
        return ans

class Question:
    def __init__(self):
        self.x = random.uniform(-3.0, 3.0)

questions = [Question() for i in range(10000)]

people = [Person(questions) for i in range(200)]
cheats = [Person(questions, True) for i in range(100)]

# print([sum(i.answers) for i in people])
# print([sum(i.answers) for i in cheats])

def calculate_stats(test):
    n = len(test)
    stats = [[] for i in test]
    consensus = [sum(i.answers[j] for i in test) for j in range(10000)]
    for i in range(n):
        stats[i].append(sum(test[i].answers))
    for i in range(n):
        stats[i].append(sum(test[i].answers[j] * consensus[j] for j in range(10000)))
    for i in range(n):
        stats[i].append(sum((1-test[i].answers[j]) * (100-consensus[j]) for j in range(10000)))
    lim = 20
    for i in range(n):
        stats[i].append(sum(test[i].answers[j] for j in range(10000) if consensus[j] > 100-lim))
    for i in range(n):
        stats[i].append(sum(1-test[i].answers[j] for j in range(10000) if consensus[j] < lim))
    return stats

data_x = []
data_y = []
for i in range(50):
    print(i)
    random.shuffle(people)
    random.shuffle(cheats)
    test = people[:99] + [cheats[0]]
    stats = calculate_stats(test)
    for i in range(4):
        data_x.append(stats[i])
        data_y.append([0])
    data_x.append(stats[-1])
    data_y.append([1])


with open('x.csv', 'a', newline='') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=' ',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
    spamwriter.writerows(data_x)

with open('y.csv', 'a', newline='') as csvfile:
    spamwriter = csv.writer(csvfile, delimiter=' ',
                            quotechar='|', quoting=csv.QUOTE_MINIMAL)
    spamwriter.writerows(data_y)