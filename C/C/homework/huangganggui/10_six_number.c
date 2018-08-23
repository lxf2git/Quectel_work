#include<stdio.h>

void judge();

int main()
{
	judge();
	printf("\n");
	return 0;
}

void judge()
{
	int i,j = 0 ;

	for(i = 0 ; i <=1000; i++ )
	{
		if( (2 == i % 3)&&(3 == i % 5) &&(1 == i % 7))
		{	
			j++;
			printf ("%d ",i);
			if(6==j)
			{
				j==0;
				printf("\n");
			}
		}
	}

}
