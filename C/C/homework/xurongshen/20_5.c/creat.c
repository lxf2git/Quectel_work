#include"my.h"

long creat()
{
	user use;
	printf("creat--->s!\n");
	printf("creat will into genertorId--->s!\n");
	use.id = generatorId();
	printf("creat will into showMenu--->s!\n");
	showMenu();

	return 0;
}
