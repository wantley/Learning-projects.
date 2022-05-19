import random
Sn = []
St = []
policy = ""
Reward = 0
##
##def roll(N):
##    val = random.choice(N)
##    States.append.R
##def play(N,X): 
##    while True:
##            result = roll(N)
##            if result in Good:
##                print("you got "+str(result)+" KEEP PLAYING FOR MORE.")
##                X = X + result**2
##                if( X > 100):
##                    print("You got the max 100 dollars congrats")
##                    return X;
##            else:
##                print("you got "+str(result)+" and lost all money.")
##        else:
##            print("you ended the game.")
##            return X

for i in range(0,100):
     Sn.append(i)
for i in range(100,136):
     St.append(i)
def finalCalc(V,V2):
     final = 0
     for i in range(0,len(V)):
          final += abs(V[i] - V2[i])
     return final
def value(X,V):
     global policy
     global St
     accept = 0
     reject = 0
     valid = [X+9,X+25,X+36]
     zero = [0,0,0]
    # reject = X
     for s in valid:
          accept += (1/6)*V[s]
     if accept >= X:
          return accept
     else:
          return 0    
def valueIteration():
     E = 0.01
     global S
     V = [[],[]]
     i = 1
     final = 0.00
     for j in Sn:
          V[0].append(0)
     for j in St:
          V[0].append(j)
     while True:
          for s in range(0,len(Sn)):
               V[i].append(Sn[s]+value(Sn[s],V[i-1]))
          for j in St:
               V[i].append(j)
          final = finalCalc(V[i], V[i-1])
          if final <= E:
               break
          V.append([])
          i += 1
     return V
V = valueIteration()
c = 0
for i in V:
     c2 = 0
     print("i: "+str(c))
     for j in range(0,len(Sn)):
          print("V*("+str(c2)+"): "+str(i[j]))
          c2 += 1
     c += 1

