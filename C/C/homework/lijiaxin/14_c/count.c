#include"count.h"

void count(int i)
{
		int j=1;
		while(i/10!=0)
		{
				j++;
				i/=10;
		}
		printf("共有%d位\n",j);
}
