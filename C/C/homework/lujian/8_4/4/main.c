#include"main.h"
int n;
int main()
{
		int i;
		char ch;
		printf("please \'\\n\' <enter>\nother keys exit\n");
		ch =getchar();	
		while (ch =='\n')
		{
				printf("please input n (n>0)\n");
				scanf("%d",&n);
				int a[n][n], max[n];	
				input(a);
				put(a);

				for (i =0; i<n; i++)
				{
						max[i] = count_max(a[i]);
				}	


				printf("min = %d\n", count_min(max));
				printf("please \'\\n\'  <enter> \nother keys exit\n");
				getchar();
				ch = getchar();
		}
}

int input(int a[][n])
{
	int i, j; 
	srand(time(NULL));
	
	for(i =0; i<n; i++)
	{
		for (j=0; j<n; j++)
			a[i][j] = (rand()%100);
	}
	return 0; 
}

int put(int a[][n])
{
	int i,j;
	for (i = 0; i<n; i++)
	{
		for (j=0; j<n; j++)
				printf("%4d",a[i][j]); 
		printf("\n"); 
	}


	return 0; 
}
