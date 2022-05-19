import numpy as np
k = 40
Bl = []
Cl = []
for i in range(0,40):
    Bl.append(-1)
for i in range(0,40):
    Cl.append(0)
index = 0
with open('hw3a.txt') as f:
    for line in f:
        line = int(line)
        if line in Bl:
            indx = Bl.index(line)
            Cl[indx] += 1
        elif -1 in Bl:
            indx = Bl.index(-1)
            Bl[indx] = line
            Cl[indx] += 1
        else:
            for i in range(0,len(Cl)):
                Cl[i] = Cl[i] - 1
                if Cl[i] == 0:                
                    Bl[i] = -1
for i in range(0,len(Bl)):
    if Bl[i] > -1:
        print(str(Bl[i]))
        
    

