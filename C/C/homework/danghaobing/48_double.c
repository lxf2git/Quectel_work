#include<stdio.h>
#include<stdlib.h>
int print(int a)
{
	printf("%d ",a);
}
int double_t(int a)
{
	return 2*a;
}
int main()
{
		int a;
		int (*p[2])(int);
		p[0] = print;
		p[1] = double_t;
		printf("请输入多个数，以空格隔开，以回车结束\n");
		for(;;)
		{
				scanf("%d",&a);
				p[0](p[1](a));
				if(getchar()=='\n')
						break;
		}
		printf("\n");


}
