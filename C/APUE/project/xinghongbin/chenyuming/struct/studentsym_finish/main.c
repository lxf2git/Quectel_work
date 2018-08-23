#include "stusys.h"

int main()
{
	pList pStusys = NULL;	
	int flag = 0;
	int value = 0;

	value = create_memory((void **)&pStusys, sizeof(sList));
	catch(value);

	init(pStusys);
	value = pStusys->pLoad(pStusys);
	catch(value);

	while(1){
		flag = interface();

		value = pStusys->pFun_stu[flag-1](pStusys);
		catch(value);
	
		if (flag = 6)
			break;
	}
	
	free(pStusys);
	return 0;
}
