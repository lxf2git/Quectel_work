#include<stdio.h>
#include<stdlib.h>
typedef struct Age
{
		char *name;
		int age;

}*pSa;
void creat_memory(void **p,int size);
void input(pSa p,int n);
void output(pSa p,int n);
int main()
{
		int n;
		printf("input number of human\n");
		scanf("%d",&n);
		pSa p;
		creat_memory((void **)&p,n*sizeof(struct Age));
		input(p,n);
		output(p,n);
}
void creat_memory(void **p,int size)
{
		*p=malloc(size);
}
void input(pSa p,int n)
{
		int i;
		for(i=0;i<n;i++,p++)
		{
				creat_memory((void**)&p->name,20);
				printf("input name age\n");
				scanf("%s%d",p->name,&p->age);
		}
		p-=n;
}
void output(pSa p,int n)
{
		int i,j;
		struct Age temp;
		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
						if((p+j)->age < (p+i)->age)
						{
								temp=*(p+i);
								*(p+i)=*(p+j);
								*(p+j)=temp;
						}

		}
		printf("name:%s age:%d\n",p->name,p->age);
}
