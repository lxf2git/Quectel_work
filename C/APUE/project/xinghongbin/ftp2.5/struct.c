#include<stdio.h>
#include<stdlib.h>
#define N 3
void add(int m,int n);
struct Student
{
		char *name;
		char gender;
		int age;
		char addr[20];
		int score;
		void (*p1)(int,int);
};
int main()
{
		int i;
		struct Student *p;
		p=(struct Student *)malloc(N*sizeof(struct Student));
		for(i=0;i<N;i++,p++)
		{
				p->name=(char *)malloc(20*sizeof(char *));

				printf("input :name,gender,age,addr,score\n");
				scanf("%s",p->name);
				getchar();
				scanf("%c%d%s%d",&p->gender,&p->age,p->addr,&p->score);
				printf("%s %c %d %s %d\n",p->name,p->gender,p->age,p->addr,p->score);
		}
		p->p1=add;
		(*(p->p1))(1,2);
//		(p->(void add))(1,2);
		return 0;
}


void add(int m,int n)
{
		printf("%d\n",m+n);
}
