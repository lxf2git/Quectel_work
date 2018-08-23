#include"insert.h"
int Idfind(pStu phead,pStu pInsert)
{
	pStu ptr = phead;
	while(ptr->next!=phead)
	{
		if(ptr->num == pInsert->num)
		{
			return EXIST;
		}
		ptr = ptr->next;
    }

	if(ptr->num == pInsert->num )
	{
		return EXIST;
	}
	else
	{
		return TURE;
	}
}
pStu InsertPosition(pStu phead,pStu pInsert)
{
	pStu ptr = phead;
	while(ptr->next!=phead)
	{
		if(ptr->next->num >= pInsert->num)
		{
			return ptr;
		}
	 	ptr = ptr->next;
	}
	return ptr;
}
int Insert(pStu phead,pStu pInsert,int (*pIDFind)(pStu pHead,pStu pInsert),pStu(*pInsertPosition)(pStu pHead,pStu pInsert))
{	
	pInsert->stu_input = stu_in;
	(pInsert->stu_input)(pInsert);
	int i = (*pIDFind)(phead,pInsert);
		if(i == EXIST )
		{
			printf("id exist\n");
			free(pInsert);
			pInsert = NULL;
		}
		else 
		{
			pStu ptr =(*pInsertPosition)(phead,pInsert);
			pInsert->next = ptr->next; 
			ptr->next = pInsert;
			printf("insert complete!\n");
		}	
}
