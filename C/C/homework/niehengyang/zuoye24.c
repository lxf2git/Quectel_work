#include<stdio.h>
int main()
{
	int i,j;
	char a[100];
	printf("");
	scanf("%s",a);
	for(i=0;i<100;i++)
	{
		if(a[i]==99)
		{
			for(j=i;j<100;j++)
			{
			a[j]=a[j+1];
			}
			i=i-1;
		}
	}
       printf("%s",a);
	printf("\n");
	return 0;
}
