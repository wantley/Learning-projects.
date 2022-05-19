import random
import math
def heuristic():
    St = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    R = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    mistakes = 0
    with open("hw4.txt") as f:
        for line in f:
            c1 = 0
            c0 = 0
            rt = line[-2]
            for i in range(0,16):
                if St[i] == 1:
                    if line[i] == '0':
                        c0 += 1
                    elif line[i] == '1':
                        c1 += 1  
                if line[i] != rt:
                    R[i] += 1
            mini = min(R)
            for i in range(0,16):
                if R[i] == mini:
                    St[i] = 1
                else:
                    St[i] = 0
            if c0 > c1:
                decision = '0'
            elif c1 > c0:
                decision = '1'
            else:
                decission = random.choice([0,1])
            if(decision != rt):
                mistakes += 1
    return mistakes
def WM():
    W = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    R = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]   
    mistakes = 0
    Ri = 0
    with open("hw4.txt") as f:
        for line in f:
            c0 = 0
            c1 = 0
            rt = int(line[-2])
            for i in range(0,16):
                e = int(line[i])
                if(e == 0):
                    c0 += W[i]
                else:
                    c1 += W[i]
                
                if e != rt:
                    W[i] = W[i]/2
                    R[i] += 1
            if(c0 > c1):
                decision = 0
            elif(c1 > c0):
                decision = 1
            else:
                decision = random.choice([0,1])
            if(decision != rt):
                mistakes += 1
    Ri = 2.41*(min(R)+math.log2(16))
    return (mistakes,Ri)         
def RWM():
    W = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
    mistakes = 0
    Ri = 0
    R = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]   
    with open("hw4.txt") as f:
        for line in f:
            c0 =0
            c1 = 0
            rt = line[-2]
            for i in range(0,16):
                if(line[i] == '0'):
                    c0 += W[i]
                else:
                    c1 += W[i]
                if line[i] != rt:
                    W[i] = W[i]*(1-0.03)
                    R[i] += 1
            decision = random.choices(['0','1'],weights = (c0/(c0+c1),c1/(c0+c1)))
            if(decision[0] != rt):
                mistakes += 1
        Ri = (1+0.03)*min(R)+math.log(16)/0.03
        
        return (mistakes,Ri)

arr1 = []
arr2 = []
h = heuristic()
W = WM()
for i in range(0,1000):
    R = RWM()
    arr1.append(R[0])
    arr2.append(R[1])
print("mistakes made by heuristic: "+str(h))
print("mistakes made by WM: "+str(W[0]))
print("Regret of Wm: " + str(W[1]))
print("mistakes made by RWM: "+str(sum(arr1)/1000))                             
print("Regret of Wm: " + str(sum(arr2)/1000))      
            
