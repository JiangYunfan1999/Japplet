#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//函数的声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
//能返回四种状态：玩家赢'*'；电脑赢'#'；平局'Q'；游戏继续'C'
