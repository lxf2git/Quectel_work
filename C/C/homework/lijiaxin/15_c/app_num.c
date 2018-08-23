#include"app_num.h"

int main()
{
		int input;
		for (; ;)
		{
			scanf("%d",&input);
			while(input>=100&&input<=500)
			{
				yueshu(input);
				scanf("%d",&input);
			}
			break;
		}
		return 0;
}
