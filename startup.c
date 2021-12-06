#include"snake.h"


void startup()//数据初始化
{
   int i,j;
   for(i=0;i<High;i++)
   {
         map[i][0]=-1;
        map[i][Width-1]=-1;
   }
   for(j=0;j<Width;j++)
   {
        map[0][j]=-1;
        map[High-1][j]=-1;
   }
    map[High/2][Width/2]=1;
   for(i=1;i<4;i++)
         map[High/2][Width/2-i]=i+1;

    moveDirection=4;

    food_x=rand()%(High-5)+2;
    food_y=rand()%(Width-5)+2;
     map[food_x][food_y]=-2;

}
