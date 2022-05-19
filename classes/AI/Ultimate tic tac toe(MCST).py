import pygame
import sys
WIDTH = 729 # 3^6
HEIGHT = 729
BG_COLOR = (28, 170, 156)
LINE_COLOR = (23, 145, 135)
CROSS_COLOR = (66, 66, 66)
CIRCLE_COLOR = (239, 231, 200)
FADE = (28, 170, 156)
ALPHA = 100
DIM = 3
class BoardDims:
    def __init__(self):    
        self.size = size
        self.sqsize = size//ROWS
        self.xcor = xcor
        self.ycor = ycor
class Board():
    def __init__(self):
        self.squares = [[0,0,0] for row in range(ROWS)]
    def  render_board(self, surface):
        for row in range(ROWS):
            for col in range(COLS):
                sqr = self.squares[row][col]
        pygame.draw.line(surface,LINE_COLOR)
class Game:
    def __init__(self):
        self.board = Board()
class Main:
    def __init__(self):
        self.screen = pygame.display.set_mode( (WIDTH, HEIGHT) )
        self.screen.fill(BG_COLOR)
        pygame.display.set_caption('ULTIMATE TIC TAC TOE')

    def mainloop(self):

        while True:

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()

            pygame.display.update()

if __name__ == '__main__':
    main = Main()
    main.mainloop()
    
