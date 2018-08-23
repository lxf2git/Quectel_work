#include<stdio.h>
int main()
{
		int a;
		scanf("%d",&a);
		if(a>=1&&a<=7)
			switch(a)
				{
					case 1:
					printf("星期1\n");
					break;
					case 2:
					printf("星期2\n");
					break;
					case 3:
					printf("星期3\n");
					break;
					case 4:
					printf("星期4\n");
					break;
					case 5:
					printf("星期5\n");
					break;
					case 6:
					printf("星期6\n");
					break;
					default:
					printf("星期天\n");
					break;
				}
		else
				printf("打错了\n");
		return 0;
}
