#include<stdio.h>
#include<stdlib.h>
typedef struct Student 
{
	int id;
	char *name;
	int score;
}sStu;
void show(sStu *p)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(p[i].score<60)
			printf("id:%d name:%s score:%d 加油\n",p[i].id,p[i].name,p[i].score);
		else
			printf("id:%d name:%s score:%d GOOD\n",p[i].id,p[i].name,p[i].score);
	}
}
int main()
{
	int i;
	sStu a[3];
	for(i=0;i<3;i++)
	{
		a[i].name=(char *)malloc(20*sizeof(char));
		printf("please id name score\n");
		scanf("%d%s%d",&a[i].id,a[i].name,&a[i].score);
	}
	show(a);
	return 0;
}
