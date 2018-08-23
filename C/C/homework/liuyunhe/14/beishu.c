#include"beishu.h"
void beishu()
{
		int a,i=1;
		scanf("%d",&a);
		while(a!=0)
		{
				a=a/10;
				if(a!=0)
				{
						i++;
				}
		}
		printf("%d",i);
}

