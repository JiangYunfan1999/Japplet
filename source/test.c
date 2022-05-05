#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

//游戏实现
void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while(1)
	{
		//玩家落子
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断胜负
		ret = IsWin(board, ROW, COL);
		if(ret != 'C')
			break;
		//电脑落子
		ComputerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断胜负
		if(ret != 'C')
			break;
	}
	if(ret == '*')
		printf("玩家获胜");
	else if(ret == '#')
		printf("电脑获胜");
	else
		printf("平局");
}

//打印菜单
void menu()
{
	printf("******* 三子棋游戏 ********/n");
	printf("***** 1.play   0.exit *****/n");
	printf("***************************/n");
}

//测试程序
void test()
{
	int input=0;
	//设置随机种子
	srand((unsigned int)time(NULL));
	do
	{
		//打印菜单
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				printf("开始三子棋游戏");
				//游戏实现
				game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入错误，请重新选择");
				break;
		}
	}while(input); //仅当input为0时才跳出
}

int main()
{
	// 测试程序
	test();
	return 0;
}
