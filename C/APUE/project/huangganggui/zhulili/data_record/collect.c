#include"collect.h"

void collected(pNode pHead_N,pDis pHead_D)
{
	pDis ptmp = NULL;
	pNode pnode = NULL;
	pNode px = NULL;
	pNode pp = NULL;
	pNode ptail = NULL;
	pnode = pHead_D->next->record;
	pNode pdel = NULL;
	//删除单链表下的数，进行收集
	for(ptmp=pHead_D->next;ptmp!=pHead_D;ptmp=ptmp->next)
	{
		for(ptail=ptmp->record->prev;ptail!=ptmp->record;ptail=pp)
		{
			//把数据从单链表中删除
			ptail = ptmp->record->prev;
			pp = ptail->prev; //先记录位置后运算
			ptail->prev->next = ptmp->record;
			ptmp->record->prev = ptail->prev;
			
			//把删除的节点按尾插的方法在放回原来的头节点			
			pHead_N->prev->next = ptail;
			ptail->prev = pHead_N->prev;
			pHead_N->prev = ptail;			
			ptail->next = pHead_N;					
		}
	}		
}


