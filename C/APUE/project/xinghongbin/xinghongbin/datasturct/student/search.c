#include"search.h"

void search_chain(pStu pHead,pList plist)
{

		pFun_Search choose;
		choose[0] = search_age;
		choose[1] = search_id;
		plist->pSearch = search_fun;
		plist->pSearch(pHead,choose);

}
int search_fun(pStu pHead,pFun_Search choose)
{
		int choice;
		int num;
		printf("input you search age/id:");
		scanf("%d",&num);
		printf("input 0 and 1 \n");
		printf("0 choose age\n");
		printf("1 choose id\n");
		scanf("%d",&choice);
		choose[choice](pHead,num);

}
int search_age(pStu pHead,int num)
{
		pStu pTemp=pHead->next;
		printf("search age\n");
		while(pTemp != NULL)
		{
				if(pTemp->age == num)
				{
						printf("id:%d age:%d\n",pTemp->id,pTemp->age);
				}
				pTemp = pTemp->next;
		}
		return 0;


}
int search_id(pStu pHead,int num)
{
		pStu pTemp=pHead;
		printf("search id \n");
		while(pTemp->next != NULL)
		{
				if(pTemp->id == num)
				{
						printf("id:%d age:%d\n",pTemp->id,pTemp->age);
				}
				pTemp = pTemp->next;
		}
		return 0;

}
