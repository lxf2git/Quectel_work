#include<stdio.h>
void my_free(int **q)
{
	if(*q!=NULL)
	{
		free(*q);
		*q = NULL;
	}
}

int main()
{
	int *p;
	p = (int *)malloc(5*sizeof(int));	
	my_free(&p);
	return 0;

}
