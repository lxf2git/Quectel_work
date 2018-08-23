#include<stdio.h>
#include<stdlib.h>

int error(int);
void divisors(int);
int main()
{
	int a;
	scanf("%d",&a);
	a=error(a);

	divisors(a);

	return 0;
}

void divisors(int a)
{
	int i,j,k;
	j = 0 ;
	k = 0 ;
	for(i=1;i<500;i++)
	{
		if((a % i == 0)&&(i != 1)&&(i != a))
		{
			printf("%d\n",i);
			j++;
			k=k+i;
		}
		
	}
	printf("\ncount:%d\nsum:%d\n",j,k);
}

int error(int a)
{
	if(a<100||a>500)
	{
		printf("error!\n");
		exit(0);
	}
}
