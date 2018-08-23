#include<stdio.h>
#include<stdlib.h>
void koujuebiao();
int main()
{
	printf("乘法口诀表\n");
	koujuebiao();

	return 0;
}
void koujuebiao()
{
	int i,j;
	j=1;	
	while(j<10)
	{
		for(i=1;i<j+1;i++)
		{
			printf("%d*%d=%d  ",i,j,i*j);
			
		}
		printf("\n");
		j++;
	}
	exit(0);
}	
