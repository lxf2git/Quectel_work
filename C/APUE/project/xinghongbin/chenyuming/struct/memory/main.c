#include "pub.h"

static list_declare(apply_list);
static list_declare(free_list);
static list_declare(record_list);

unsigned int record_index = 1;

void (*Memory_Fun[2])(struct syslist *syslist) = {ApplyMemory, FreeMemory};

int main()
{
	int flag;
	struct syslist sys_list;
	sys_list.apply_list = &apply_list;
	sys_list.free_list = &free_list;
	sys_list.record_list = &record_list;
	
	init_memory_list(sys_list.apply_list);

	while(1){
		printf("1.申请.\n");
		printf("2.释放.\n");
		printf("3.退出.\n");

		scanf("%d", &flag);
		
		if (flag == 3)
			exit(0);

		Memory_Fun[flag-1](&sys_list);
		PrintData(sys_list.apply_list);
		printf("free.\n");
		PrintData(sys_list.free_list);
	}
	return 0;
}

