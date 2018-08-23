#include"show.h"
void show_mid(pTree pHead)
{
	if(pHead->tr_lc!=NULL)
	{
			show_mid(pHead->tr_lc);
	}
	printf("%c",pHead->tr_data);
	if(pHead->tr_rc!=NULL)
	{
			show_mid(pHead->tr_rc);
	}
}

void show_first(pTree pHead)
{
	printf("%c",pHead->tr_data);
	if(pHead->tr_lc!=NULL)
	{
		show_first(pHead->tr_lc);
	}
	if(pHead->tr_rc!=NULL)
	{
		show_first(pHead->tr_rc);
	}
}
void show_last(pTree pHead)
{
	if(pHead->tr_lc!=NULL)
	{
		show_last(pHead->tr_lc);
	}
	if(pHead->tr_rc!=NULL)
	{
		show_last(pHead->tr_rc);
	}
	printf("%c",pHead->tr_data);
}
