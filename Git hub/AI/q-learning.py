import numpy as np

envRows = 11
envCols = 11

qTable = np.zeros((envRows, envCols, 4))
actions = ['up','rigth','down','left']
#set all rewards to -100 
rewards = np.full((envRows,envCols), -100)
#goal
rewards[0,5] = 100 
#save walkable areas as a dictionary.
safeAreas = {}
safeAreas[1] = [i for i in range(1,10)]
safeAreas[2] = [1, 7, 9]
safeAreas[3] = [i for i in range(1,8)]
safeAreas[3].append(9)
safeAreas[4] = [3,7]
safeAreas[5] = [i for i in range(11)]
safeAreas[6] = [5]
safeAreas[7] = [i  for i in range(1, 10)]
safeAreas[8] = [3, 7]
safeAreas[9] = [i for i in range(11)]

for  ri in range(1,10):
    for ci in safeAreas[ri]:
        rewards[ri,ci] = -1

def is_terminal(rowi, columni):
    if rewards[rowi, columni] == -1:
        return False
    else:
        return True

def get_start():
    rowi = np.random.randint(envRows)
    coli = np.random.randint(envCols)
    while is_terminal(rowi, coli):
        rowi = np.random.randint(envRows)
        coli = np.random.randint(envCols)
    return rowi, coli
def get_action(rowi,coli, epsilon):
    #take the best action possible with a small
    #probability to take a random action this is
    #done in order to take make the agent experiment
    if np.random.random() < epsilon:
        return np.argmax(qTable[rowi, coli])
    else:
        return np.random.randint(4)
def get_location(rowi, coli, actioni):
    newRowi = rowi
    newColi = coli
    if actions[actioni] == 'up' and rowi > 0:
        newRowi -= 1
    elif actions[actioni] == 'rigth' and coli < envCols - 1:
        newColi += 1
    elif actions[actioni] == 'down' and rowi < envRows - 1:
        newRowi += 1
    elif actions[actioni] == 'left' and coli > 0:
        newColi -= 1
    return newRowi, newColi

def get_shortest_path(startRowi, startColi):
    if is_terminal(startRowi, startColi):
        return []
    else:
        rowi, coli = startRowi, startColi
        shortest_path = []
        shortest_path.append([rowi, coli])
        while not is_terminal(rowi, coli):
            actioni = get_action(rowi, coli, 1.)
            rowi, coli = get_location(rowi, coli, actioni)
            shortest_path.append([rowi,coli])
        return shortest_path
epsilon = 0.9#chance of making a random action.
discount_factor = 0.9#weitgs of the values
learning_rate = 0.9 #how fast the AI will learn
#AI runs for 1000 episodes
for episode in range(1000):
    rowi, coli = get_start()
    while not is_terminal(rowi, coli):
        actioni = get_action(rowi,coli, epsilon)
        oldRowi, oldColi = rowi, coli
        rowi, coli = get_location(rowi,coli,actioni)

        reward = rewards[rowi, coli]
        oldq = qTable[oldRowi, oldColi, actioni]
        temporal_difference = reward + (discount_factor * np.max(qTable[rowi,coli])) - oldq

        newq = oldq + (learning_rate * temporal_difference)
        qTable[oldRowi, oldColi, actioni] = newq

print("training complete")

print(get_shortest_path(9,10))      
