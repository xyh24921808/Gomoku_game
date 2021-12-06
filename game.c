#include"game.h"

int x=0;
int y=0;
int Chesscount(int board[][COL],int row,int col,enum Dir d)
{
	int count=0;
	int i=x-1;
	int j=y-1;
	while(1)
	{
		switch(d)
		{
			case LEFT:
				j--;
				break;
			case RIGHT:
				j++;
				break;
			case UP:
				i++;
				break;
			case DOWN:
				i--;
				break;
			case LEFT_UP:
				j--;
				i++;
				break;
			case LEFT_DOWN:
				i--;
				j--;
				break;
			case RIGHT_UP:
				i++;
				j++;
				break;
			case RIGHT_DOWN:
				i--;
				j++;
				break;
			defuatl:
				break;
		}
		if(i<0||j<0||i>=row||j>=col)
		{
			break;
		}
		if(board[x-1][y-1]==board[i][j])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
void Showboard(int board[][COL],int row,int col)
{
	printf("\e[1;1H\e[2J");
 	printf("  ");
	for(int i=1;i<=col;i++)
	{
		printf("%3d",i);
	}
	printf("\n");
	for(int i=0;i<row;i++)
	{
		printf("%2d ",i+1);
		for(int j=0;j<col;j++)
		{
			if(board[i][j]==0)
			{
				printf(" . ");
			}
			else if(board[i][j]==Player1)
			{
				printf(" ● ");
			}
			else
			{
				printf(" ○ ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
}
int Isover(int board[][COL],int row,int col)
{
	int count1=Chesscount(board,row,col,LEFT)+Chesscount(board,row,col,RIGHT)+1; 
	int count2=Chesscount(board,row,col,UP)+Chesscount(board,row,col,DOWN)+1; 
	int count3=Chesscount(board,row,col,LEFT_UP)+Chesscount(board,row,col,RIGHT_DOWN)+1; 
	int count4=Chesscount(board,row,col,RIGHT_UP)+Chesscount(board,row,col,LEFT_DOWN)+1;
	if(count1>=5||count2>=5||count3>=5||count4>=5)
	{
		if(board[x-1][y-1]==Player1)
		{
			return Player1win;
		}
		else
		{
			return Player2win;
		}
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(board[i][j]==0)
			{
				return NEXT;
			}
		}
	}
	return Draw;
}
void Playermove(int board[][COL],int row,int col,int player)
{
	while(1)
	{
		printf("Player[%d] pls chose x & y:>",player);
		fflush(stdin);
		scanf("%d%d",&x,&y);
		if(x<1||y<1||x>row||y>col)
		{
			continue;
		}
		else if(board[x-1][y-1]!=0)
		{
			printf("error\n");
			continue;
		}
		else
		{
			board[x-1][y-1]=player;
			break;
		}
	}
}
void game()
{
	int board[ROW][COL];
	memset(board,0,sizeof(board));
	int ret=0;
	do
	{
		Showboard(board,ROW,COL);
		Playermove(board,ROW,COL,Player1);
		ret=Isover(board,ROW,COL);
		if(ret!=NEXT)
		{
			break;
		}

		Showboard(board,ROW,COL);
		Playermove(board,ROW,COL,Player2);
		ret=Isover(board,ROW,COL);
		if(ret!=NEXT)
		{
			break;
		}
	}while(1);
	switch(ret)
	{
		case 1:
			printf("Player1 win!!!\n");
			break;
		case 2:
			printf("Player 2 win!!!\n");
			break;
		case 3:
			printf("OVER  DRWA\n");
			break;
		defuatl:
			//noting do!!!
			break;
	}
}		
