#include "main.h"
#include "func.h"
#include "init.h"
#include "del.h"

#define ph plist->head


int main()
{
	pList plist=NULL;
	getmemory((void **)&plist,sizeof(sList));
	prepare(&ph,sizeof(sStu));
	load(ph);
	function(ph,plist);
	delete(ph);
	free_m(&ph);
	free_n(&plist);
	return 0;
}
