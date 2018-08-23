#include<stdio.h>
int main()
{
	int i,j;
	int a[5][5];
	int maxr,maxl;
	printf("");
	scanf("%d",&a[0][0]);
		maxr=a[0][0];
		maxl=a[0][0];
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			
			scanf("%d",&a[i][j]);
			if(j>=i)
			{
				if(maxr<a[i][j])
					{
				maxr=a[i][j];
					}
			}
			else
			{
				if(maxl<a[i][j])
					{
				maxl=a[i][j];
					}
			}
		}
	}
		printf("%d %d",maxr,maxl);

}
