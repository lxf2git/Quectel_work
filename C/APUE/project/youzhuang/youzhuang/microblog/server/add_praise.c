#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Add_praise(int confd ,int *praise)
{
		printf("赞\n");
		int ret =0;
		(*praise)++;
		write(confd,&ret,sizeof(int ));
}
