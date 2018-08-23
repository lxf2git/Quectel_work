#include<stdio.h>
void total();

int main()
{
	total();
	return 0;
}
void total()
{
	int total,a,b,c,d; 
	for(total=0;;total++)
	{
		if(total%5==1)
		{
			a=(total-1)/5;
			if((total-a-1)%5==1)
			{
				b=(total-a-2)/5;
				if((total-a-b-2)%5==1)
				{
					c=(total-a-b-3)/5;
					if((total-a-b-c-3)%5==1)
					{
						d=(total-a-b-c-4)/5;
						if((total-a-b-c-d-4)%5==1)
						{
							printf("最少有%d条鱼\n",total);
							break;
						}
						else continue;
					}
					else continue;
				}
				else continue;
			}
			else continue;
		}
		else continue;
	}
}
