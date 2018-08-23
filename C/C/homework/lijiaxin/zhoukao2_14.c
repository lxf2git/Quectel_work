#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
void get_memory(void **q,int size)
{
		*q = malloc(size);
		if(NULL==*q)
		{
				printf("mallocerror!\n");
				exit(-1);
		}
}
void exchange(char *q)
{
		char temp;
		int i,count;
		count = strlen(q);
		for(i=0;i<count/2;i++)
		{
				temp = q[i];
				q[i] = q[count-1-i];
				q[count-1-i] = temp;
		}
		puts(q);
}
int main()
{
		char *p=NULL;
		get_memory((void **)&p,N*sizeof(char));
		printf("please enter a string:\n");
		gets(p);
		exchange(p);
		return 0;
}
