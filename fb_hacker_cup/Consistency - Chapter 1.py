import string

t = int(input())
for test in range(t):
    print(f"Case #{test+1}: ", end='')
    s = input()

    vowels = "AEIOU"
    consonants = [i for i in string.ascii_uppercase if i not in vowels]

    full_answer = 2 * len(s)

    for letter in vowels:
        # change everything to vowel letter
        answer = 0 
        for i in s:
            if i != letter:
                if i in vowels:
                    answer += 1
                answer += 1
        full_answer = min(answer, full_answer)
    
    for letter in consonants:
        # change everything to vowel letter
        answer = 0 
        for i in s:
            if i != letter:
                if i not in vowels:
                    answer += 1
                answer += 1
        full_answer = min(answer, full_answer)
    print(full_answer)