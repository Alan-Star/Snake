#include"snake.h"
void welcome()
{

    char inp;
    int i;
    for(i=0;i<27;i++)
        printf("●");
    printf("\n");
    for(i=0;i<30;i++)
       printf("●\t\t\t\t\t\t    ●\n");
    for(i=0;i<27;i++)
        printf("●");
    gotoxy(5,15);

    printf("\t\tI.开始游戏      （请按1和Enter）\n");
    printf("●\t\tII.在线更新!  （请按2和Enter）\n");
    printf("●\t\tIII.在线充值! （请按3和Enter）\n");
    printf("●\t\tIV.在线客服   （请按4和Enter）\n");
    printf("●\t\tIV.读取存档   （请按5和Enter）\n");

    scanf("%d",&inp);

    if(inp==1)
        return;
    else if(inp==2)
    {
         system("start http://alan-star.github.io");
          goto start;
    }
    else if(inp==3)
        system("start https://s3.bmp.ovh/imgs/2021/12/5517914f22a8c4d0.png");
    else if(inp==4)
        printf("QQ:2404320281");
    else if(inp==5)
        system("start http://alan-star.github.io");

    Sleep(7000);
    start:
    system("cls");
}
