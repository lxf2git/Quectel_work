#include"main.h"

enum name
{
	two=1,
	ten,
	sixteen,
	quit
};

int main()
{
	sStack ps;
	int data;
	int mod;
	int pop_data;
	int choose;
	init_stack(&ps);  //开空间
	printf("输入数据:\n");
	scanf("%d",&data);
	
	for(;;)
	{	printf("1-----转换成二进制\n");
		printf("2-----转换成八进制\n");	
		printf("3-----转换成十六进制\n");	
		printf("4--------------退出\n");	
		scanf("%d",&choose);
		switch(choose)
		{
			case two: 
				 	two_jinzhi(&ps,data,mod,&pop_data);
					break;
			case ten: 
				 	ten_jinzhi(&ps,data,mod,&pop_data);
					break;
			case sixteen: 
				 	sixteen_jinzhi(&ps,data,mod,&pop_data);
					break;
			case quit:   
					return 0;
					break;
			default:
					printf("error");
					break;
		}
	}	
	main();
	return 0;
}
