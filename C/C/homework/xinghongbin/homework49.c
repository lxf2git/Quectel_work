#include<stdio.h>
#include<stdlib.h>
#define N 3

typedef struct Student
{
		int id;
		char *name;
		int math;
}*pStu;
void creat_memory(void **p,int size);
void input(pStu p);
void output(pStu p);
int main()
{
		pStu p;
//		p=malloc(N*sizeof(struct Student));
		creat_memory((void **)&p,N*sizeof(struct Student));
		input(p);
		output(p);
		
		
}
void creat_memory(void **p,int size)
{
		*p=malloc(size);

}
void input(pStu p)
{

		int i;
		for(i=0;i<N;i++,p++)
		{
				
				printf("input id name math\n");

				creat_memory((void**)&p->name,20);
				scanf("%d%s%d",&p->id,p->name,&p->math);
				if(p->math>100)
				{
						printf("error\ninput again\n");
						p--;
						i--;
				}
		}
		p-=N;
}
void output(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
		{
				printf("id:%d name:%s math;%d %s\n",p->id,p->name,p->math,p->math>=60?"good":"come on");
		}
}
