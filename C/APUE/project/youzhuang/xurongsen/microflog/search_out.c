#include"init.h"

int search(void **phead)
{
	printf("*********************\n");
#if 0
	PMicroblog p;
	p = (*(PMicroblog *)phead)->next;
	while(p->s_praise != 0)
	{
		printf("s_praise:%d\n",p->s_praise);
		p = p->next;
	}
#endif
	PFriend pf;
	pf = (*(PFriend *)phead)->next;
	while(pf->s_id != 0)
	{
		printf("s_fans:%d\n",pf->s_id);
		pf = pf->next;
	}
	printf("*********************\n");
}
