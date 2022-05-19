from numpy import random
currentgen = []
temp1 = []
temp2 = []
agents = 4
size = 6
def crossover(parent1 = [], parent2 = []):
    children1 = []
    children2 = []
    children1.extend(parent1[:len(parent1)//2])
    children1.extend(parent2[len(parent1)//2:])
    if(random.randint(0,100) <= 2):
        mutation(children1)
    children2.extend(parent2[:len(parent1)//2])
    children2.extend(parent1[len(parent1)//2:])
    if(random.randint(0,100) >= 99):
        mutation(children2)
    return children1, children2
def mutation(child = []):
    i= random.randint(0,size)
    if(child[i] == 0):
        child[i] = 1
    else:
        child[i] = 0    
def fitness(arr=[]):
    score = []
    for i in range(agents):
        score.append(sum(arr[i]))
    return score
def selection(score=[]):
    survivors = []
    y = 0
    for i in range(int(agents//2)):
        y = score.index(max(score))
        survivors.append(y)
        score[y] = -1
    return survivors
def evolution(currentgen = [], gen = int):
    nextgen = []
    selected = selection(fitness(currentgen))
    for i in selected:
        nextgen.append(currentgen[i])
    for i in range(len(selected)//2):
        temp1, temp2 = crossover(currentgen[i], currentgen[(len(selected)//2)-i])
        nextgen.append(temp1)
        nextgen.append(temp2)
        
    print("Generation" + str(gen) +":")
    print(currentgen)
    fit = fitness(nextgen)
    better = fit.index(max(fit))
    print(better)
    if(sum(nextgen[better]) >= size):
        print("stopped at Generation" + str(gen) +":")
        print(nextgen)
    else:
        evolution(nextgen, gen+1)

for i in range(agents):
    currentgen.append(random.randint(2, size=(size)))
evolution(currentgen, 1)


    
