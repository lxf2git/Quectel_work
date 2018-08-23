#include"stack.h"

int main()
{
		char *str=NULL;
		get_memory((void **)&str,SIZE*sizeof(char));
		printf("请输入需要操作的运算式:\n");
		gets(str);
		pStack p_data=NULL;
		pStack p_oper=NULL;
		init_stack(&p_data);
		init_stack(&p_oper);
		init(p_data,p_oper,str);
		print(p_data,p_oper);
}
