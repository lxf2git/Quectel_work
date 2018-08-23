#include"count.h"

int main()
{
		int integer;
		while(1)
		{
				printf("请输入一个整数(输入零后自动退出):\n");
				scanf("%d",&integer);
				if(0!=integer)
				{
						count(integer);
				}
				else
						break;

		}
		return 0;
}
