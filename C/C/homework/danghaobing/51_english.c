#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
		char *name;
		int mgrade;
		int cgrade;
		int egrade;
		int zpgrade;
}*sSt;
void print(sSt s,int *z,int n)
{
		int i;
		printf("不及格名单：\n");
		for(i=0;i<n;i++)
		{
				if(s[i].zpgrade<(z[3]*0.3))
				{
						printf("姓名：%s 数学成绩：%d 语文成绩：%d 英语成绩：%d 总分：%d \n",s[i].name,s[i].mgrade,s[i].cgrade,s[i].egrade,s[i].zpgrade);
				}
		}

}
void av(int *z,int n)
{
	int i;
	for(i=0;i<4;i++)
	{
			z[i]/=n;
	}
}
void cal(sSt s,int i,int *z,int n)
{
	z[0]+=s[i].mgrade;
   	z[1]+=s[i].cgrade;
	z[2]+=s[i].egrade;
	z[3]+=s[i].zpgrade;
	if(i==n-1)
	av(z,n);
}
int main() 
{
	sSt s;
	int n;
	printf("请输入人数\n");
	scanf("%d",&n);
	s = malloc(n*sizeof(struct Student));
	int i;
	int *z;
	z = (int *)malloc(sizeof(int)*4);
	for(i=0;i<n;i++)
	{
			printf("请输入姓名,数学成绩，语文成绩，英语成绩\n");
			s[i].name = (char *)malloc(20*sizeof(char)); 
			scanf("%s%d%d%d",s[i].name,&s[i].mgrade,&s[i].cgrade,&s[i].egrade);
			s[i].zpgrade = s[i].cgrade+s[i].mgrade+s[i].egrade;
			cal(s,i,z,n);
	}
	printf("数学平均成绩：%d 语文平均成绩：%d 英语平均成绩：%d 总分平均分：%d \n",z[0],z[1],z[2],z[3]);
	print(s,z,n);
}
