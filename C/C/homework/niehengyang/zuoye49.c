#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	typedef struct Student
	{
	
		char name[20];
		int id;
		int score;
	}sStu,*pStu,sStu_arr[3];
void show(sStu_arr s);

int main()
{
	sStu_arr s;
	//sStu s.name[20];
	//struct Student *p;
	//p=s;
	int i;
	//for(i=0;i<3;i++)
	//{
	//s[i]=(struct Student *)malloc(sizeof(struct Student));
	//s[i].name=(char *)malloc(20*sizeof(char));
	//}
	for(i=0;i<3;i++)
	{
		//s[i].name=(char *)malloc(20*sizeof(char));
		printf("please input student's name,id,score: \n");
		scanf("%s",s[i].name);
		getchar();
		scanf("%d%d",&s[i].id,&s[i].score);

	}
	show(s);

}


void show(sStu_arr s)
{
	int i;
	for(i=0;i<3;i++)
	{
		printf("id:%d,name:%s,score:%d\n",s[i].id,s[i].name,s[i].score);
		if(s[i].score>=60)
		{
			printf("good!\n");
		}
		if(s[i].score<60)
		{
			printf("加油!\n");
		}
		
	}
	

}

