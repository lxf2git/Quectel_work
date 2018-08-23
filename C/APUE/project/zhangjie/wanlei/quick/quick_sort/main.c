#include"main.h"
#include"stack.h"

int main()
{
	int *p=NULL;
	creat_memory(&p,sizeof(int));
	input(p);
	sSta sta;
	init_stack(&sta);
	quick_sort(p,&sta);
	output(p);
	return 0;
}
