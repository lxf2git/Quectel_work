#include"insert.h"

/******查找是否与已存在的ID重复********/
int id_find(pStu pHead,pStu p_stu_new)
{			
	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		//printf("ptmp->num:%d\n",ptmp->num);
		//printf("pnew->num:%d\n",p_stu_new->num);
		if(ptmp->num==p_stu_new->num)
		return 1;
	}
	return 0;	
}

/******确定新加入的数据要插入地址*******/
pStu InsertPos(pStu phead,pStu pInsert)
{
	pStu ptmp;
	for(ptmp=phead;ptmp->next!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->next->num >= pInsert->num)
		{
			return ptmp;
		}	
	}
	return ptmp;
}

/******数据链插入函数结构******/
int _Insert(pStu pHead,pStu pInsert,
							int(*pIDFind)(pStu pHead,pStu pInsert),
	pStu (*pInsertPosition)(pStu pHead,pStu pInsert))
{
	int r;
	r = (*pIDFind)(pHead,pInsert);
	if(r==0)
	{
		pStu ptmp;
		ptmp = (*pInsertPosition)(pHead,pInsert);
		
		pInsert->next = ptmp->next;
		ptmp->next = pInsert;
	}else
		{
			printf("ID already had,Sorry please again!\n");
			//exit(-1);
			//break;
		}	
}

/********输入函数********/
int input(pStu p_stu_new)
{
	printf("please input ID & Age for student ^_^\n");
	scanf("%d %d",&p_stu_new->num,&p_stu_new->age);
}

/******插入功能主体函数*******/
void s_insert(pStu pHead)
{
	pList p_list;
	init_memory_list(&p_list);
	pStu p_stu_new;//pInsert
	init_memory(&p_stu_new);
	p_stu_new->stu_input = input;
	p_stu_new->stu_input(p_stu_new);

	p_list->pInsert = _Insert;
	p_list->pInsert(pHead,p_stu_new,id_find,InsertPos);

	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("num:%d age:%d\n",ptmp->num,ptmp->age);
	}
}
