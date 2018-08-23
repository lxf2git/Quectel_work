#include "pub.h"


int main(int argc, char *argv[])
{
	pStack data_stack = InitStack();
	int convert_num = atoi(argv[1]);
	int flag = 0;
	int ret = 0;

	init_fun;
//	convert_numsys[0] = convert_two;

	printf("输入的数据是:%d\n", convert_num);
	printf("请选择转换成:\n");
	printf("1.二进制\n");
	printf("2.十六进制\n");
	printf("3.八进制\n");
	printf("请选择:\n");
	scanf("%d", &flag);

	ret = convert_numsys[flag-1](data_stack, convert_num);
	
	if (flag != 3){
		printf("%d\n", ret);
	}
	
	return 0;
}
