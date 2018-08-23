#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
typedef struct Student
{
		char name[10];
		int age;
		char sex;
}sStu,*psStu[N];
void get_memory(void **q,int size)
{
		*q = malloc(size);
		if(NULL==*q)
		{
				printf("malloc is error.\n");
				exit(-1);
		}
}
int main()
{
		FILE *pf=fopen("a.txt","a+");
		psStu p;
		int i;
		sStu *str;
		str = (sStu*)malloc(sizeof(sStu));
		for(i=0;i<N;i++)
		{
				get_memory((void **)(p+i),sizeof(sStu));
				printf("please enter name age sex:\n");
				scanf("%s%d",p[i]->name,&p[i]->age);
				getchar();
				scanf("%c",&p[i]->sex);
				fwrite(p[i],1,sizeof(sStu),pf);
		}
		rewind(pf);
		i = 0; 
		while(i<4)
		{
				fseek(pf,2*i*sizeof(sStu),SEEK_SET);	
				fread(str,1,sizeof(sStu),pf);
				printf("%s %d %c\n",str->name,str->age,str->sex);
				i++;
				rewind(pf);
		}
		fseek(pf,-sizeof(sStu),SEEK_END);
		fread(str,1,sizeof(sStu),pf);
		printf("%s %d %c\n",str->name,str->age,str->sex);
		return 0;
}
