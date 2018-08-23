#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *a[3];
	int b[3]={0},i;
	printf("请输入候选人名字：\n");
	for(i=0;i<3;i++)
	{
		a[i] = (char *)malloc(10*sizeof(char));
		scanf("%s",a[i]);
	}
	a[4] = (char *)malloc(10*sizeof(char));
	printf("请给你喜欢的人物投票\n");
	for(i=0;i<10;i++)
	{
			printf("第 %d 票投给：",i+1);
			scanf("%s",a[4]);
					if(strcmp(a[4],a[0])==0)
						b[0]++;
					else if(strcmp(a[4],a[1])==0)
						b[1]++;
					else if(strcmp(a[4],a[2])==0)
						b[2]++;
					else
					{
							printf("没这个人，请重新投票\n");
							i--;
					}
	}
	for(i=0;i<3;i++)
	{
			printf("候选人%s 得票数：%d \n",a[i],b[i]);
	}
}
