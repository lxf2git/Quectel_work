#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x,i=1;
    for(i=1;;i++)
	{	
		x=i;
		if(x%5==1)
		{
			x=(x-1)*4/5;
			if(x%5==1)
			{
				x=(x-1)*4/5;
			if(x%5==1)
			{
				x=(x-1)*4/5;
				if(x%5==1)
				{
					x=(x-1)*4/5;
					if(x%5==1)
					{
						x=(x-1)*4/5;
							printf("鱼的条数：%d\n",i);
					return 0;	
			        }
				}
			}
		}

	}
	}

}
