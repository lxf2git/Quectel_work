#include<stdio.h>
//#define R (n)
//#define C (n)
int n;
void input(int a[][n], int i,int j);
void put(int a[][n]);
int main()
{
		while (1)
		{
				int i, j;
				printf("please input n:\n"); 
				scanf("%d",&n);
				int a[n][n];
				for ( i= 0 ; i<n; i++)
				{
						for (j = 0; j<n; j++)
						{

								input(a,i,j);		 

						}

				}
				put(a);
		}
	return 0; 
}
void input(int a[][n], int i,int j)
{
	int l;	
		if (i == 0)
		{
	    a[i][j] = 1; 
		}
		for (l = 1; l<n; l++)
		{
			a[i][j] = i-j+1;
			if (a[i][j] <= 0)
			{
					a[i][j]=1;
			}
		
		}


}

void put(int a[][n])
{
	int i, j;

	for (i =0; i<n; i++)
	{
			for (j=0; j<n; j++)
			{
				printf("%-4d ",a[i][j]); 
				
			}
			putchar('\n');

	}
}
