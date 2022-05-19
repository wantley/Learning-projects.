import gym
import random
import numpy as np
env = gym.make("MountainCar-v0")
class HillclimbingAgent():
    def __init__(self,env):
        self.action_size = env.action_space.n
        self.state_dim = env.observation_space.shape
        self.build_model()        
    #We create the first case the start of the model
    #by usign random variables.
    def build_model(self):
        #create the array w.
        self.weights = 1e-4*np.random.rand(*self.state_dim, self.action_size)
        #variable that will hold best reward so far.
        self.best_reward = -np.Inf#-infinity initially
        #variable that will hold the best weights.
        #initially random.
        self.best_weights = np.copy(self.weights)
        #scale of the noise array.
        self.noise_scale = 1e-2
    
    def get_action(self, state):
        #matrix mult of the current env and the weigths.
        p = np.dot(state, self.weights)
        #use the result from before as the probability of action 1 or 2.
        action = np.argmax(p)
        return action
    def update_model(self, reward):
        if reward >= self.best_reward:
            self.best_reward = reward
            #make weigths the current weigths.
            self.best_weights = np.copy(self.weights)
            self.noise_scale = max(self.noise_scale/2, 1e-3)
        else:
            self.noise_scale = min(self.noise_scale*2, 2)
        #creates current weight ny adding new noise and scalling it to weigth array.
        self.weights = self.best_weights + self.noise_scale * np.random.rand(*self.state_dim, self.action_size)
        
agent = HillclimbingAgent(env)
num_episodes = 10000

for ep in range(num_episodes):
    state = env.reset()
    total_reward = 0
    done = False
    while not done:
        action = agent.get_action(state)
        #bellow is the response of the enviroment after an action.
        state, reward, done, info = env.step(action)
        env.render()
        total_reward += reward

    agent.update_model(total_reward)
    print("Episode: {}, total_reward: {:.2f}".format(ep,total_reward))

