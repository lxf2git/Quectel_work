#include"hash.h"

int main()
{
	pData phead = NULL;
	init_node(&phead);
	creat_org_chain(phead);
	printf("orginal data\n");
	show_chain(phead);
	creat_hash_list(phead);
	return 0;
}

void show_chain(pData phead)
{
	int i;
	pData ptmp = phead;
	for(ptmp=phead->next;ptmp!=phead;ptmp=ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}
