#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//该头文件用于提供实时获取键盘输入的函数getch()
#include<windows.h>
#define v 10//v是小蛇的爬行速度
#define High 30//游戏框高度
#define Width 50//游戏框宽度
extern int  map[High][Width];//map用于存储游戏地图数据，本游戏通过修改与遍历该数组实现实时刷新的功能！！！
void HideCursor();
void gotoxy(int x,int y);//该函数通过调用WIN32API用于清屏，且能优化全局刷新，减少闪烁，达到护眼目的。
void welcome();//制作游戏开始前的欢迎界面：包括新游戏，在线更新，读取存档，在线充值
void startup();
void moveSnakeByDirection();
void updateWithoutInput();
void show();
void updateWithInput();

int moveDirection;//1,2,3,4
int food_x,food_y;

