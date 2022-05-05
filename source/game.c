#include <stdio.h>
#include "game.h"

//函数的实现
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			board[i][j] = ' ';
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i=0; i<row; i++)
	{
		//打印一行棋盘
		int j = 0;
		for(j=0; j<col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col-1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if(i < row-1)
		{
			for(j=0; j<col; j++)
			{
				printf("---");
				if(j == col-1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走棋：");
	while(1)
	{
		printf("请输入要下的坐标：");
		scanf("%d%d", &x, &y);
		//判断坐标合法性
		if(x>=1 && x<=row && y>=1 && y<= col)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
				printf("该坐标已占用，请重新输入");
				
		}
		else
			printf("坐标无效，请重新输入");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走棋：");
	while(1)
	{
		x = rand()%row;
		y = rand()%col;
		if(board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(board[i][j]==' ')
				return 0; //棋盘未满
		}
	}
	return 1; //棋盘已满
}


char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//检查横行
	for(i=0; i<row; i++)
	{
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
			return board[i][0];
	}
	//检查竖列
	for(i=0; i<row; i++)
	{
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
			return board[0][i];
	}
	//检查对角线
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
		return board[1][1];
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
		return board[1][1];
	//判断是否平局
	if(IsFull(coard, ROW, COL)==1)
		return 'Q';
	return 'C';
}
