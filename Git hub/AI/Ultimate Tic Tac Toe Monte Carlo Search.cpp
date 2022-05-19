#include <iostream>
#include <string>
#define SIZE 9
#include <math.h> 

using namespace std;
int connect(string p[]);
struct Struct  
{
    int x, y;
};
void printt(string panel[])
{
	cout<<"    |   |  \n";
	cout<<"  "+panel[0]+" | "+panel[1]+" | "+panel[2]+"\n";
	cout<<"____|___|____\n    |   |  \n";
	cout<<"  "+panel[3]+" | "+panel[4]+" | "+panel[5]+"\n";
	cout<<"____|___|____\n    |   |  \n";
	cout<<"  "+panel[6]+" | "+panel[7]+" | "+panel[8]+"\n";
	cout<<"    |   |  \n";
}
typedef struct Struct dimensions;
void print(string panel[][SIZE])
{
	int k = 0;
	int z = 0;
	for(int i = 0; i<9;i++)
	{
		for(int j = 0; j<3;j++)
		{
			cout<<"  "+panel[j+z][k]+" | "+panel[j+z][1+k]+" | "+panel[j+z][2+k];
			if(j != 2)
			cout<<"  ||";
		}
		k += 3;
		if(i==2 || i ==5)
		{
			k=0;
			z += 3;
			cout<<"\n=============||=============||============\n";
		}
		if(i!= 2 && i!=5 && i!=8)
			cout<<"\n ---|---|--- || ---|---|--- || ---|---|---\n";

	}
	cout<<endl;
}
void copy(string panel[][SIZE],string cpanel[][SIZE])
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE;j++)
		{
			cpanel[i][j] = panel[i][j]; 
		}
	}
}
int BIGconnect(string state[][SIZE], bool change)
{
	string winner;
	string p[SIZE] {" "," "," "," "," "," "," "," "," "};
	for(int i = 0; i< SIZE; i++)
	{
		int s; 
		s = connect(state[i]);
		if(s == 1)
		{
			p[i] = "X";
			if(change)
			{
				for(int j = 0; j< 9; j++)
				{
					state[i][j] = "X";
				}
			}
		}
		else if(s == 2)
		{
			p[i] = "O";
			if(change)
			{
				for(int j = 0; j< 9; j++)
				{
					state[i][j] = "O";
				}
			}
		}
		else if(s == 3)
		{
			p[i] = "T";
			if(change)
			{
				for(int j = 0; j< 9; j++)
				{
					state[i][j] = "T";
				}
			}
		}
		else
		{
			p[i] = "E";
		}
	}
	for(int i = 0; i<SIZE; i++)
	{
		if(p[i] == "E")
		{
			winner = "E";
		}
	}
	if(p[0] == p[1] && p[1] == p[2] && p[0] != " " && p[1] != " " && p[2] != " ")
	{
		winner = p[0];
	}
	else if(p[3] == p[4] && p[4] == p[5] && p[3] != " " && p[4] != " " && p[5] != " ")
	{
		winner = p[3];
	}
	else if(p[6] == p[7] && p[7] == p[8] && p[6] != " " && p[7] != " " && p[8] != " ")
	{
		winner = p[6];
	}
	else if(p[0] == p[3] && p[3] == p[6] && p[0] != " " && p[3] != " " && p[6] != " ")
	{
		winner = p[0];
	}
	else if(p[1] == p[4] && p[4] == p[7] && p[1] != " " && p[4] != " " && p[7] != " ")
	{
		winner = p[1];
	}
	else if(p[2] == p[5] && p[5] == p[8] && p[2] != " " && p[5] != " " && p[8] != " ")
	{
		winner = p[2];
	}
	else if(p[0] == p[4] && p[4] == p[8]&& p[0] != " " && p[4] != " " && p[8] != " ")
	{
		winner = p[0];
	}
	else if(p[2] == p[4] && p[4] == p[6] && p[2] != " " && p[4] != " " && p[6] != " ")
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
	else if(winner == "E")
	{
		return 0;
	}
	else
	{
		return 3;	
	}	
}

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
	if(p[0] == p[1] && p[1] == p[2] && p[0] != " " && p[1] != " " && p[2] != " ")
	{
		winner = p[0];
	}
	else if(p[3] == p[4] && p[4] == p[5] && p[3] != " " && p[4] != " " && p[5] != " ")
	{
		winner = p[3];
	}
	else if(p[6] == p[7] && p[7] == p[8] && p[6] != " " && p[7] != " " && p[8] != " ")
	{
		winner = p[6];
	}
	else if(p[0] == p[3] && p[3] == p[6] && p[0] != " " && p[3] != " " && p[6] != " ")
	{
		winner = p[0];
	}
	else if(p[1] == p[4] && p[4] == p[7] && p[1] != " " && p[4] != " " && p[7] != " ")
	{
		winner = p[1];
	}
	else if(p[2] == p[5] && p[5] == p[8] && p[2] != " " && p[5] != " " && p[8] != " ")
	{
		winner = p[2];
	}
	else if(p[0] == p[4] && p[4] == p[8]&& p[0] != " " && p[4] != " " && p[8] != " ")
	{
		winner = p[0];
	}
	else if(p[2] == p[4] && p[4] == p[6] && p[2] != " " && p[4] != " " && p[6] != " ")
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
	if(connect(panel)!=0)
	{
		cout<<"board already filled can't play there\n";
		return;
	}
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
class Node
{
	public:
		double t = 0;
		double n = 0;
		int limiter = -1;
		bool isAi;
		Node *parent = NULL;
		string state[SIZE][SIZE] = {{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},
							   	{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},
								{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "}};

		Node *children[SIZE][SIZE] = {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
							   	{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
								{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}};;
};
class Monte
{
	public:
		Node *root;
	bool isLeaf(Node *node)
	{
		for(int i = 0; i< SIZE;i++)
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(node->children[i][j] != NULL)
				{
					return false;
				}
			}
		}
		return true;
	}
	Node *select(Node *node)
	{
		bool leaf = true;
		Node *p = node;
		while(true)
		{
			int val = 0;
			int x = 0;
			int y = 0;
			int max = -9999;
			leaf = true;
			for(int i = 0; i<SIZE;i++)
			{
				for(int j = 0; j<SIZE;j++)
				{
					if(p->children[i][j] == NULL)
					{
						continue;
					}
					leaf = false;
					val = (p->children[i][j]->t/p->children[i][j]->n)+2*(log (p->n)/p->children[i][j]->n);
					if(val > max)
					{
						max = val;
						x = i;
						y = j;
					}
				}
			}
			if(leaf == true)
			{
				break;
			}
			p = p->children[x][y];
		}
		return p;
	}
	void expand(Node *node)
	{
		if(node->limiter != -1)
		{
			for(int j = 0; j < SIZE; j++)
			{
				if(node->state[node->limiter][j] == " ")
				{
					Node *temp = new Node;
					temp->parent = node;
					copy(node->state, temp->state);
					if(node->isAi)
					{
						temp->state[node->limiter][j] = "X";
						temp->isAi = false;
					}
					else
					{
						temp->state[node->limiter][j] = "O";
						temp->isAi = true;
					}
					if(connect(temp->state[j]) == 0)
					{
						temp->limiter = j;
					}
					//cout<<"exp->simul"<<endl;
					simulate(temp);
					//cout<<"after exp->simul"<<endl;
					//cout<<temp->t<<endl;
					node->children[node->limiter][j] = temp;
					//cout<<node->children[node->limiter][j]->t<<endl;
				}  		
			}		
		}
		else
		{
			for(int i = 0; i < SIZE; i++)
			{
				for(int j = 0; j < SIZE; j++)
				{
					if(node->state[i][j] == " ")
					{
						Node *temp = new Node;
						temp->parent = node;
						copy(node->state, temp->state);
						if(node->isAi)
						{
							temp->state[i][j] = "X";
							temp->isAi = false;
						}
						else
						{
							temp->state[i][j] = "O";
							temp->isAi = true;
						}
						if(connect(temp->state[j]) == 0)
						{
							temp->limiter = j;
						}
						//cout<<"exp->simul"<<endl;
						simulate(temp);
						//cout<<"after exp->simul"<<endl;
						node->children[i][j] = temp;
					}  		
				}
			}
		}
	}
	void simulate(Node *node)
	{
		string panel[SIZE][SIZE];
		double count = 0;	
		int gameState;
		int i;
		int i1;
		int i2;
		int limiter;
		bool isAi;
		double t = 0;
		while(count < 15)
		{
			//cout<<"simul while start"<<endl;
			limiter = node->limiter;
			isAi = node->isAi;
			copy(node->state,panel);
			int arr[SIZE];
			int c;
			int d;
			while(true)
			{
				//cout<<"simul while true start"<<endl;
				if (limiter != -1)
				{
				//	cout<<"on if"<<endl;
					i = rand() % SIZE; 
					while(panel[limiter][i] != " ")
					{
						i = rand() % SIZE;	
					}
					if(isAi)
					{
						panel[limiter][i] = "X";
						isAi = false;
					}
					else
					{
						panel[limiter][i] = "O";
						isAi = true;
					}
					if(connect(panel[i]) == 0)
					{
						limiter = i;
					}
					else
					{
						limiter = -1;
					}
				}
				else
				{
				//	cout<<"on else"<<endl;
					i2 = rand() % SIZE;
					c = 0;
					int tem;
					for(int k = 0; k <SIZE;k++)
					{
						tem = connect(panel[k]);
						if(tem == 0)
						{
							arr[c] = k;
							c++;
						}
					}
					if(c == 0)
					{
						goto out;
					}
					d = rand() % c;
					i1 = arr[d];
					while(panel[i1][i2] != " ")
					{
						//cout<<i2<<endl;
						i2 = rand() % SIZE;
					}
					if(isAi)
					{
						panel[i1][i2] = "X";
						isAi = false;
					}
					else
					{
						panel[i1][i2] = "O";
						isAi = true;
					}
					if(connect(panel[i2]) == 0)
					{
						limiter = i2;
					}
					else
					{
						limiter = -1;
					}
				}
				out:
				gameState = BIGconnect(panel, true);
			//	cout<<"gamestate has been chosen"<<endl;
				if(gameState == 2)
				{
					//cout<<"YOU WON"<<endl;
					t += 1;
					break;
				}
				else if(gameState == 1)
				{
					//cout<<"you lost";
					break;
				}
				else if(gameState == 3)
				{
					break;
				}
			}
			//cout<<count<<endl;
			count++;
		}
		//cout<<"simul while end"<<endl;
		node->t = t;
		node->n = count;
		//cout<<"simul back propag"<<endl;
		backPropagation(node);
		//cout<<"after simul back propag"<<endl;
		//cout<<node->parent->t<<endl;
	}
	void backPropagation(Node *node)
	{
		Node *p = node;
		double t = p->t;
		double n = p->n;
		while(true)
		{
			p = p->parent;
			p->n += n;
			p->t += t; 
			if(p == root)
			{
				break;
			}
		}
	}
};
void pprint(Node *p)
{
	cout<<"isAi: "<<p->isAi<<endl;
	cout<<"llimiter: "<<p->limiter<<endl;
	cout<<"n: "<<p->n<<endl;
	cout<<"parent: "<<p->parent->t<<endl;
	cout<<"t: "<<p->t<<endl;
	cout<<"state: "<<endl;
	print(p->state);
}
dimensions aiMove(string panel[][SIZE],int limiter,int moves)
{
	double max = -9999;
	dimensions d;
	d.x = -1;
	d.y = -1;
	Monte tree;
	int count = 0;
	tree.root = new Node;
	tree.root->limiter = limiter;
	tree.root->isAi = false;
	copy(panel,tree.root->state);
	//cout<<"exp"<<endl;
	tree.expand(tree.root);
//	cout<<"exp2"<<endl;
	/*
	for(int j = 0; j<SIZE;j++)
	{	
		if(tree.root->children[1][j] != NULL)
		{
			cout<<j<<endl;
			cout<<tree.root->children[1][j]->parent->t<<endl;
		}		
	}
	*/
	Node *p = new Node;
	while(count < 150*moves)
	{
		//cout<<"before select"<<endl;
		p = tree.select(tree.root);
		//cout<<"select over"<<endl;
		tree.expand(p);	
		//cout<<"expand over"<<endl;
		//cout<<count<<endl;
		count++;
	}
	p = tree.root;
	tree.select(p);
	if(limiter == -1)
	{
		for(int i =0;i<SIZE;i++)
		{
			for(int j = 0; j<SIZE;j++)
			{
				if(p->children[i][j] == NULL)
				{
					continue;
				}	
				if(p->children[i][j]->t/p->children[i][j]->n > max)
				{
					d.x = i;
					d.y = j;
					max = p->children[i][j]->t/p->children[i][j]->n;
				}
			}
		}
	}
	else
	{
		for(int i = 0; i<SIZE;i++)
		{
			if(p->children[limiter][i] == NULL)
			{
				continue;
			}
			if(p->children[limiter][i]->t/p->children[limiter][i]->n > max)
			{
				d.x = limiter;
				d.y = i;
				max = p->children[limiter][i]->t/p->children[limiter][i]->n;
			}
		}
	}
	cout<<max<<endl;
	return d;
}
int main()
{
	string panel[SIZE][SIZE] = {{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},
							   	{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},
								{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "},{" "," "," "," "," "," "," "," "," "}};
	dimensions Agent;
	int i = 0;
	int input;
	int input2;
	int dump = 0;
	int previn = -1;
	string s = "1";
	int move = 0;
	while(BIGconnect(panel, true) == 0 || BIGconnect(panel, true) == 4)
	{
		move++;
		print(panel);
		if(s == "1")
		{	
			if(previn != -1 && connect(panel[previn])!=0)
			{
				previn = -1;
			}
			cout<<"X turn"<<endl;
			if(previn == -1)
			{
				cout<<"you can play on any empty panel"<<endl;
				cin>>input;	
			}
			else
			{
				cout<<"you can play on panel "<<previn+1<<endl;
				input = previn+1;
			}
			cin>>input2;
			while(panel[input-1][input2-1] != " ")
			{
				cout<<"no cheating";
				if(previn == -1)
				{
					cout<<"you can play on any empty panel"<<endl;
					cin>>input;	
				}
				else
				{
					cout<<"you can play on panel "<<previn+1<<endl;
					input = previn+1;
				}
				cin>>input2;
			}
			play(input2, "X", panel[input-1]);
			previn = input2-1;
		}
		else
		{
			if(previn != -1 && connect(panel[previn])!=0)
			{
				previn = -1;
			}
			cout<<"O turn"<<endl;
			Agent = aiMove(panel,previn,move);
			cout<<"Ai played"<<Agent.x+1<<" and "<<Agent.y+1<<endl;
			play(Agent.y+1, "O", panel[Agent.x]);
			previn = Agent.y;
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
	int finalState = BIGconnect(panel, true);
	print(panel);
	if(finalState  == 3)
	{
		cout<<"Tie";
	}	
	else if(finalState  == 1)
	{
		cout<<"Human won";
	}
	else if(finalState == 2)
	{
		cout<<"AI won";
	}
}
