#include <iostream>
#include <cstring> 
#include <string>
#define SIZE 9
using namespace std;

const string HUMAN = "X";  
const string COMPUTER = "O";

void print(string panel[]);
int connect(string p[])
{
	string winner;
	bool tie = true;
	for(int i = 0; i< SIZE; i++)
	{
		if(p[i] == " ")
		{
			tie = false;
		}
	}

	if(tie == true)
	{
		winner = "T";
	}
	if(p[0] == p[1] && p[1] == p[2])
	{
		winner = p[0];
	}
	else if(p[3] == p[4] && p[4] == p[5])
	{
		winner = p[3];
	}
	else if(p[6] == p[7] && p[7] == p[8])
	{
		winner = p[6];
	}
	else if(p[0] == p[3] && p[3] == p[6])
	{
		winner = p[0];
	}
	else if(p[1] == p[4] && p[4] == p[7])
	{
		winner = p[1];
	}
	else if(p[2] == p[5] && p[5] == p[8])
	{
		winner = p[2];
	}
	else if(p[0] == p[4] && p[4] == p[8])
	{
		winner = p[0];
	}
	else if(p[2] == p[4] && p[4] == p[6])
	{
		winner = p[2];
	}
	
	if(winner == "X")
	{
		return 1;
	}
	else if(winner == "O")
	{
		return 2;
	}
	else if(winner == "T")
	{
		return 3;
	}
	else
	{
		return 0;
	}	
}
void play(int input, string symbol, string panel[])
{
	switch(input)
	{
		case 1: 
			panel[0] = symbol;
			break;
		case 2: 
			panel[1] = symbol;
			break;
		case 3:
			panel[2] = symbol;
			break;
		case 4:
			panel[3] = symbol;
			break;
		case 5:
			panel[4] = symbol;
			break;
		case 6:
			panel[5] = symbol;
			break;
		case 7:
			panel[6] = symbol;
			break;
		case 8:
			panel[7] = symbol;
			break;
		case 9:
			panel[8] = symbol;
			break;
	}
}
void print(string panel[])
{
	cout<<"    |   |  \n";
	cout<<"  "+panel[0]+" | "+panel[1]+" | "+panel[2]+"\n";
	cout<<"____|___|____\n    |   |  \n";
	cout<<"  "+panel[3]+" | "+panel[4]+" | "+panel[5]+"\n";
	cout<<"____|___|____\n    |   |  \n";
	cout<<"  "+panel[6]+" | "+panel[7]+" | "+panel[8]+"\n";
	cout<<"    |   |  \n";
}
int count_tiles(string p[])
{
	int tiles = 0;
	for(int i = 0; i< SIZE; i++)
	{
		if(p[i] == " ")
		{
			tiles++;
		}
	}
	return tiles;
}
int minimax(string panel[], int depth, bool isAi)
{
	int score; 
	int bestScore;
 	int gameState;
	gameState = connect(panel);
	if(gameState == 3)
	{
		return 0;
	}
	if(gameState != 0)
	{
		if(isAi == true)
		{
			return -1;
		}
		else if(isAi == false)
		{
			return 1;
		}
	}
	else
	{		
			if(isAi == true)
			{
				bestScore = -999;
				for(int i = 0; i < 9;i++)
				{	
					if(panel[i] == " ")
					{
						panel[i] = "O";
						score = minimax(panel, depth+1,false);
						panel[i] = " ";
						if(score > bestScore)
						{
							bestScore = score;
						}
					}
				}
				return bestScore;
			}
			else
			{
				bestScore = 999;
				for(int i = 0; i < SIZE;i++)
				{	
					if(panel[i] == " ")
					{
						panel[i] = "X";
						score = minimax(panel, depth+1,true);
						panel[i] = " ";
						if(score < bestScore)
						{
							bestScore = score;
						}
					}
				}
				return bestScore;
			}
	}
}
	

int aiMove(string panel[],int move)
{
	int x = -1;
	int score = 0, bestScore = -999;
	for (int i = 0; i < SIZE; i++)
	{
		if (panel[i] == " ")
		{
			panel[i] = "O";
			score = minimax(panel, move+1, false);
			panel[i] = " ";
			if(score > bestScore)
			{
				bestScore = score;
				x = i;
			}
			
		}
	}
	return x;
}

int main()
{
	string panel[SIZE] = {" "," "," "," "," "," "," "," "," "};
	int Agent;
	int i = 0;
	int input;
	int dump = 0;
	string s = "1";
	while(connect(panel) == 0)
	{
		cout<<"player "+s+"'s turn\n";
		if(s == "1")
		{	
			cin>>input;	
			while(panel[input-1] != " ")
			{
				cout<<"no cheating";
				cin>>input;
			}
			play(input, "X", panel);
		}

		else
		{
			Agent = aiMove(panel,0);
			play(Agent+1, "O", panel);
			print(panel);
		}

		if(s == "1")
		{
			s = "2";
		}
		else
		{
			s = "1";
		}
	}
	int finalState = connect(panel);
	print(panel);
	if(finalState  == 3)
	{
		cout<<"Tie";
	}	
	else if(finalState  == 1)
	{
		cout<<"Human won";
	}
	else
	{
		cout<<"AI won";
	}
}
