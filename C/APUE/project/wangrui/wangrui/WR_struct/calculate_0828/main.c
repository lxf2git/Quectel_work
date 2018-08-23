#include"calculate.h"

int main()
{
	int ret;
	pStack1 psd = NULL;
	creat_memory((void **)&psd,sizeof(sStack1));
	pStack2 psc = NULL;
	creat_memory((void **)&psc,sizeof(sStack2));
	init_stack_int(psd);
	init_stack_char(psc);
	ret = deal(psd,psc);
	printf("=%d\n",ret);
	return 0;
}
