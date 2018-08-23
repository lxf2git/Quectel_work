//输出乘法表

#include<stdio.h>

int main()
{
	int cheng1, cheng2, ji;
	for(cheng1 = 1;cheng1 <= 9;cheng1++)
		{
			for(cheng2 = 1;cheng2 <= cheng1;cheng2++)
			{
				ji = cheng1 * cheng2;
				printf(" %d * %d = %d ",cheng1,cheng2,ji);
			}
			printf("\n");
		}
}
