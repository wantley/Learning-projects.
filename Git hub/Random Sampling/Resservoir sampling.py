import random
def func():
    k = 100
    R = 0
    S = []
    count = 0
    with open('hw3b.txt') as f:
        for line in f:
            line = int(line)
            if count <= k:
                S.append(line)
                count += 1
                continue
            R = random.randint(0, count)
            if R <= k:
                S[R] = line
            count += 1
    return S
print(func())
