#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//��ͷ�ļ������ṩʵʱ��ȡ��������ĺ���getch()
#include<windows.h>
#define v 10//v��С�ߵ������ٶ�
#define High 30//��Ϸ��߶�
#define Width 50//��Ϸ����
extern int  map[High][Width];//map���ڴ洢��Ϸ��ͼ���ݣ�����Ϸͨ���޸������������ʵ��ʵʱˢ�µĹ��ܣ�����
void HideCursor();
void gotoxy(int x,int y);//�ú���ͨ������WIN32API���������������Ż�ȫ��ˢ�£�������˸���ﵽ����Ŀ�ġ�
void welcome();//������Ϸ��ʼǰ�Ļ�ӭ���棺��������Ϸ�����߸��£���ȡ�浵�����߳�ֵ
void startup();
void moveSnakeByDirection();
void updateWithoutInput();
void show();
void updateWithInput();

int moveDirection;//1,2,3,4
int food_x,food_y;

