#include"memory.h"
extern sRec *pHrec[N];
extern int rec;
int apply_mem(pMem pHapp,pMem pHfre)
{
	int area;
	int all_size;
	printf("input apply area\n");
	scanf("%d",&area);
	all_size = judge_area(pHapp);//判断剩余容量
	if(all_size < area)
	{
		return FAIL;
	}
	rec++;
	init_rec_node(&pHrec[rec]);
	deal_area(pHapp,pHfre,area);//提取空间
//	printf("test1:%d\n",pHrec[rec]->next->pdata->size);
//	printf("test2:%d\n",pHrec[rec]->next->next->pdata->size);
	return SUC;
}

void deal_area(pMem pHapp,pMem pHfre,int area)
{
	int max_size;
	int size;
	max_size = traversal_mem_max(pHapp);//遍历，返回最大size
//	printf("max:%d\n",max_size);
//	printf("rec:%d\n",rec);
	if(area > max_size)
	{
		area = area - max_size;
//		printf("area:%d\n",area);
		size = max_size;
		search_distribute(size,pHapp,pHfre);//传size 查找并分配空间

//		printf("a\n");
//		printf("area:%d\n",area);
		deal_area(pHapp,pHfre,area);//递归开剩余空间
		//可能要返回	
	}
	else
	{
		size = area;
		search_distribute(size,pHapp,pHfre);
//		printf("b\n");
//		deal_area(pHapp,pHfre,pHrec,area)//递归开剩余空间
	}
}
void search_distribute(int size,pMem pHapp,pMem pHfre)
{
	pMem pdeal;
	pMem pnew;
	init_mem_node(&pnew);
	pdeal = traversal_mem_size(pHapp,size);
	pnew->index = pdeal->index;
	pnew->size = size;
	pdeal->size = pdeal->size - size;
	if(pdeal->size == 0)
	{
		delete_mem_node(&pdeal);
	}
	insert_free_chain(pHfre,pnew);
}
void insert_free_chain(pMem pHfre,pMem pnew)
{
	pMem ptmp = pHfre;
	pHfre->size = N;
	for(ptmp=pHfre->next;ptmp!=pHfre;ptmp=ptmp->next)
	{
		if(pnew->size < ptmp->size)
		{
			break;
		}
//		printf("%d\n",ptmp->size);
	}
/*	ptmp->prev->next = ptmp;
	pnew->prev = ptmp->prev;
	ptmp->prev = pnew;
	pnew->next = ptmp;*/
	insert_mem_back(ptmp,pnew);
	insert_record(pnew);
}
void insert_record(pMem pnew)
{
	pRec ptmp;
	init_rec_node(&ptmp);
	ptmp->pdata = pnew;
	insert_rec_back(pHrec[rec],ptmp);
}
int judge_area(pMem pHapp)
{
	int all_size = 0;
	pMem ptmp = pHapp;
	for(ptmp=pHapp->next;ptmp!=pHapp;ptmp=ptmp->next)
	{
		all_size = all_size+ptmp->size;
	}
	return all_size;
}
pMem traversal_mem_size(pMem pHapp,int size)
{
	pMem ptmp = pHapp;
	int max_size;
	for(ptmp=pHapp->next;ptmp!=pHapp;ptmp=ptmp->next)
	{
		if(ptmp->size == size)
		{
			return ptmp;
		}
	}
	max_size = traversal_mem_max(pHapp);
	for(ptmp=pHapp->next;ptmp!=pHapp;ptmp=ptmp->next)
	{
		if(ptmp->size == max_size)
		{
			return ptmp;
		}
	}
}
int traversal_mem_max(pMem pHapp)
{
	int max_size = 0;
	pMem ptmp = pHapp;
	for(ptmp=pHapp->next;ptmp!=pHapp;ptmp=ptmp->next)
	{
		if(ptmp->size > max_size)
		{
			max_size = ptmp->size;
		}
	}
	return max_size;
}
