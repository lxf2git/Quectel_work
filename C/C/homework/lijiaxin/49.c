#include<stdio.h>
#include<stdlib.h>
#define N 3
typedef struct Student{
		char *number;
		char name[20];
		int math_score;
}sStu,*psStu;
void print(psStu p,int n);
int main()
{
		sStu arr[N];
		int i;
		for(i=0;i<N;i++)
		{
				arr[i].number = (char *)malloc(20);
				printf("please input number name math:\n");
				scanf("%s",arr[i].number);
				getchar();
				scanf("%s%d",arr[i].name,&arr[i].math_score);
		}
		print(arr,N);
		return 0;
}
void print(psStu p,int n)
{
		int i;
		for(i=0;i<n;i++)
		{
				printf("学号:%s 姓名:%s 数学分数:%d ",p->number,
								p->name,p->math_score);
				if(p->math_score<60)
						printf("加油!\n");
				else
						printf("good!\n");
				p++;
		}
}


