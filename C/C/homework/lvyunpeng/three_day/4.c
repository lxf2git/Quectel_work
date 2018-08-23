#include<stdio.h>
int ath(int i,int j);
int main()
{	int i,j;
	printf("九九算数乘法表:\n");
	for(i=1;i<=9;i++)
{
	ath(i,j);

} 
		return 0;
}
int ath(int i,int j)
{


		for(j=1;j<=i;j++)
	{
		printf("%d*%d=%d ",i,j,i*j);
	}
		printf("\n");

}
