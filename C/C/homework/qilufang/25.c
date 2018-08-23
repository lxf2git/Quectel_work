#include<stdio.h>
#define N 4 
void output(int input[][N]);
int main()
{
	int i,j,input[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j>=i)
			{
				input[i][j] = 1;
			}
			else
			{
				input[i][j]=i-j+1;
			}
		}
	}
	output(input);
	return 0;

}
void output(int input[][N])
{	
	int i,j,a=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",input[i][j]);
			a++;
			if(a%4==0)
			printf("\n");
		}
	}
}
