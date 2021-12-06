#include"snake.h"
int score=0;
int   map[High][Width]={0};
//二维数组存储游戏画布的元素
//0为空格，-1为边框#，1为蛇头@，》1为蛇身,-2 food
void gotoxy(int x,int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
}
void HideCursor()
{

CONSOLE_CURSOR_INFO cursor_info = {1, 0};//第二个值0表示隐藏光标

SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}




void moveSnakeByDirection()
{
    int i,j;
    int max=0;
    int oldTail_i,oldTail_j;
    int oldHead_i,oldHead_j;
    for(i=1;i<High-1;i++)
    {
         for(j=1;j<Width-1;j++)
         {
             if(  map[i][j]>0)
               {
                     map[i][j]++;
                   if(max<  map[i][j])
                   {
                       max =   map[i][j];
                       oldTail_i=i;
                       oldTail_j=j;
                   }
                   if(  map[i][j]==2)
                   {
                       oldHead_i=i;
                       oldHead_j=j;
                   }
               }
         }
    }
   //   map[oldTail_i][oldTail_j]=0;
    int newHead_i,newHead_j;
    if(moveDirection==1)
    {
       //   map[oldHead_i-1][oldHead_j]=1;
        newHead_i=oldHead_i-1;
        newHead_j=oldHead_j;
    }

    if(moveDirection==2)
    {
        //  map[oldHead_i+1][oldHead_j]=1;
        newHead_i=oldHead_i+1;
        newHead_j=oldHead_j;
    }

    if(moveDirection==3)
    {
        //  map[oldHead_i][oldHead_j-1]=1;
        newHead_i=oldHead_i;
        newHead_j=oldHead_j-1;
    }

    if(moveDirection==4)
    {
        //   map[oldHead_i][oldHead_j+1]=1;
          newHead_i=oldHead_i;
        newHead_j=oldHead_j+1;
    }

    if(  map[newHead_i][newHead_j]==-2)
    {
          map[food_x][food_y]=0;
        food_x=rand()%(High-5)+2;
        food_y=rand()%(Width-5)+2;
          map[food_x][food_y]=-2;
          score++;
    }
    else
    {
          map[oldTail_i][oldTail_j]=0;
    }
    if(  map[newHead_i][newHead_j]>0||  map[newHead_i][newHead_j]==-1)
    {
        printf("Failed!\n");
        exit (0);
    }
    else
    {
          map[newHead_i][newHead_j]=1;

    }



}




void show()//显示画面
{
    int i,j;
    gotoxy(0,0);
    for(i=0;i<High;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(  map[i][j]==0)
                printf(" ");//输出 *
            else if(  map[i][j]==-1)
                printf("#");
            else if(  map[i][j]==1)
                printf("@");
            else if(  map[i][j]>1)
                printf("*");
            else if(  map[i][j]==-2)
                printf("F");
        }
        printf("\n");
    }
    Sleep(1000/v);
    printf("Score : %d",score);
}

void updateWithoutInput()//与用户输入无关的更新
{
    moveSnakeByDirection();
}

void updateWithInput()//与用户输入有关的更新
{
    char input;
    if(kbhit())//按键时执行
    {
        input=getch();
        if(input=='a'||input=='A'||input==72)
            moveDirection=3;
        if(input=='d'||input=='D')
             moveDirection=4;
        if(input=='w'||input=='W')
             moveDirection=1;
        if(input=='s'||input=='S')
             moveDirection=2;

    }
}

int main()
{
    //void HideCursor();
    system("mode con cols=60 lines=38");
    system("COLOR 40");
    welcome();
    startup();

    while(1)
    {
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}
