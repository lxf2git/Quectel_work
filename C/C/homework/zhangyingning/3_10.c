#include<stdio.h>


int main()
{
	int integer, x, z, f = 0;
	printf("请输入一个数");
	scanf("%d",&z);
	for(x = 0;x <= z;x++)
	{
		if(x % 7  == 1 )
		{
			if(x % 5 == 3)
			{
				if(x % 3 == 2)
				{	++f;
					printf(" %d ",x);
					if(f % 6 == 0)
					{
						printf("\n");
					}
				}
			}
		}
	}
printf("\n");
return 0;
}
