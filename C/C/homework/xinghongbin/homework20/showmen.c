#include"main.h"
int l=1;
int languge()
{
		printf("请 输入 1 为    中文界面\n");
		printf("plese input 2 is English\n");	
		scanf("%d",&l);
		
}
int showmen()
{
		int a,choose;
		if(1==l)
		{
			do
			{
					printf("<---1---> 创建用户\n");
					printf("<---2--->   存款  \n");
					printf("<---3--->   取款  \n");
					printf("<---4--->   查询  \n");
					printf("<---5--->   退出  \n");
					scanf("%d",&choose);
			}while((choose!=1&&choose!=2&&choose!=3&&choose!=4&&choose!=5)&&printf("输入错误 请重新输入\n"));
			printf("<-----------------------欢迎来到uplooking银行--------------------->_\n");
		}	
		if(2==l)
		{
			do
			{
					printf("<---1--->  create  \n");
					printf("<---2--->   save   \n");
					printf("<---3---> withdraw  \n");
					printf("<---4--->   query   \n");
					printf("<---5--->   exit   \n");
					scanf("%d",&choose);
			}while((choose!=1&&choose!=2&&choose!=3&&choose!=4&&choose!=5)&&printf("input error please again\n"));
			printf("<-----------------------welcome uplooking yinhang--------------------->_\n");
		}	
			switch(choose)
			{
					case 1:
							creatMenu();
							break;
					case 2:
							saveMenu();
							break;
					case 3:
							withdrawMenu();
							break;
					case 4:
							queryMenu();
							break;
					case 5:
							exit(0);		
			}
		
		return a;

}
