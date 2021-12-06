#include"snake.h"
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
             if(canvas[i][j]>0)
               {
                   canvas[i][j]++;
                   if(max<canvas[i][j])
                   {
                       max = canvas[i][j];
                       oldTail_i=i;
                       oldTail_j=j;
                   }
                   if(canvas[i][j]==2)
                   {
                       oldHead_i=i;
                       oldHead_j=j;
                   }
               }
         }
    }
   // canvas[oldTail_i][oldTail_j]=0;
    int newHead_i,newHead_j;
    if(moveDirection==1)
    {
       // canvas[oldHead_i-1][oldHead_j]=1;
        newHead_i=oldHead_i-1;
        newHead_j=oldHead_j;
    }

    if(moveDirection==2)
    {
        //canvas[oldHead_i+1][oldHead_j]=1;
        newHead_i=oldHead_i+1;
        newHead_j=oldHead_j;
    }

    if(moveDirection==3)
    {
        //canvas[oldHead_i][oldHead_j-1]=1;
        newHead_i=oldHead_i;
        newHead_j=oldHead_j-1;
    }

    if(moveDirection==4)
    {
        // canvas[oldHead_i][oldHead_j+1]=1;
          newHead_i=oldHead_i;
        newHead_j=oldHead_j+1;
    }

    if(canvas[newHead_i][newHead_j]==-2)
    {
        canvas[food_x][food_y]=0;
        food_x=rand()%(High-5)+2;
        food_y=rand()%(Width-5)+2;
        canvas[food_x][food_y]=-2;
    }
    else
    {
        canvas[oldTail_i][oldTail_j]=0;
    }
    if(canvas[newHead_i][newHead_j]>0||canvas[newHead_i][newHead_j]==-1)
    {
        printf("Failed!\n");
        exit (0);
    }
    else
    {
        canvas[newHead_i][newHead_j]=1;

    }



}

