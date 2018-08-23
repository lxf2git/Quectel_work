#include<stdio.h>
void creat_memory(void **q,int size)//q=&p  q=&pp
{
	*q = malloc(size);//p=malloc()  pp=malloc()
	if()
	{
	
	}
}

int main()
{
	int **pp;//&pp;
	int *p;//&p
	char *ch;
	creat_memory((void **)&p,m*sizeof(int));	
	creat_memory((void **)&pp,n*sizeof(int*));	
	creat_memory((void **)&ch,n*sizeof(char));	
	return 0;

}
