#include"stack.h"
int main()
{
	int in,data;
	sStack sta;
	init_stack(&sta);
	printf("Input a int:\n");
	scanf("%d",&data);
	while(1)
	{
		printf("<1>********************十进制->二进制\n");
		printf("<2>********************十进制->八进制\n");
		printf("<3>********************十进制->十六进制\n");
		printf("<4>********************退出\n");
		printf("请输入要进行哪种进制转换：\n");
		scanf("%d",&in);
		switch(in)
		{
			case TWO : func(2,data,&sta); break;
			case EIGHT : func(8,data,&sta); break;
			case SIXTEEN : func(16,data,&sta); break;
			case EXIT : exit(0);
			default : printf("小伙你输错了，请重新输入！\n"); break;
		}
	}
	myfree(&sta);
	
	return 0;

}
