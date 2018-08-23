#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
typedef struct Vote
{
		char *name;
		int ticket;
}*pSv;
void output(pSv p);
void input(pSv p);
void create_memory(void **p ,int size);
int main()
{
		pSv p;
		create_memory((void **)&p,3*sizeof(struct Vote));
		input(p);
		output(p);
		return 0;

}
void create_memory(void **p ,int size)
{
		*p=malloc(size);
}
void input(pSv p)
{
		char *name[N];

		int i,j;
		for(i=0;i<3;i++,p++)
		{
				create_memory((void **)&p->name,20);
				printf("input voted name\n");
				scanf("%s",p->name);
				p->ticket=0;
		}
		p-=i;
		for(i=0;i<N;i++)
		{
				create_memory((void **)&name[i],20);
				
				printf("input you hope name\n");
				scanf("%s",name[i]);
				for(j=0;j<3;j++)
						if( strcmp(name[i],(p+j)->name) == 0)
								(p+j)->ticket++;
		}
}
void output(pSv p)
{
		int i;
		for(i=0;i<3;i++,p++)
				printf("%s %d\n",p->name,p->ticket);

}
