#include<stdio.h>
#include<stdlib.h>
void fun()
{
	int *q;	
	q = malloc(100);
	printf("q:%p\n",q);
	if(q!=NULL)
	{
		free(q);
		q = NULL;
	}
	free(q);
	//if 
	
}
int main()
{
	int *p = NULL;
	printf("bf:%p\n",p);	
	fun();

}
