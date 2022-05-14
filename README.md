# Japplet
noughts-and-crosses game

## 三子棋小游戏
经典叉叉圈圈九宫格，首先连成横/竖/斜三个即为胜利

## C语言实现
- 数组的应用
  - char board[ROW][COL] 棋盘
- 设置随机种子
  - srand((unsigned int)time(NULL))
- 自定义函数
  - InitBoard() 初始化棋盘
  - DisplayBoard() 展示棋盘
  - PlayerMove() 玩家下棋
  - ComputerMove() 电脑下棋
  - IsWin() 判断结果，返回四种状态：玩家赢'*'；电脑赢'#'；平局'Q'；游戏继续'C'

## 文件目录
- 头文件
  - game.h 包含全局常量的定义、函数的声明
- 源文件
  - game.c 游戏实现功能函数的定义
  - test.c 测试整体程序
