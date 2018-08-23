#include "stusys.h"


int create_memory(void **memory, unsigned int size)
{
	*memory = malloc(size);

	if (NULL == *memory)
		return FAIL;

	return SUCCESS;
}


void catch(int flag)
{
	if (flag == FAIL)
		exit(FAIL);
}


void wait()
{
	printf("0返回主菜单\n");
	int tmp;

	while(1){
		scanf("%d", &tmp);

		if (tmp == 0)
			break;
	}
}


