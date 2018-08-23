#include<stdio.h>
int main()
{
	int i,j;
	int a[3][3];
	int b[3],m;
	printf("");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}


	}
		for(i=0;i<3;i++)
		{
			b[i]=a[i][0];
			for(j=0;j<3;j++)
			{
				if(b[i]<a[i][j])
				{
				b[i]=a[i][j];
				}
				
			}
		printf("%d ",b[i]);
		}
		printf("\n");	
		for(i=0;i<3;i++)
		{
		m=b[0];
			if(m>b[i])
			{
				m=b[i];
			}
		}
	printf("%d\n",m);
}
