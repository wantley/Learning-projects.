import random
Arr = []
Yl = 0
S = []
k = 100
with open('hw3b.txt') as f:
    for line in f:
        line = int(line)
        Arr.append(line)
    for i in range(0,k):
        Yl = Arr.pop(random.randrange(len(Arr)))
        S.append(Yl)
print(S)     
        
