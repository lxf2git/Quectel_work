#include"main.h"
#include"insert.h"
#include"del.h"
#include"search.h"
#include"print.h"
#include"save.h"

enum stu
{
	INSERT=1,
   	DEL,
	SEARCH,
	PRINT,
	SAVE,
	EXIT
};

int main()
{
	FILE *fp=NULL;	
	int choose1;
	pList p=NULL;pStu pnew = NULL;	
	init_node((void **)&p,sizeof(sList));
//	printf("p:%p\n",p);
	p->head = NULL;
//	p = (pList)malloc(sizeof(sList))
	init_node((void **)&p->head,sizeof(sStu));
//	printf("p:%p\n",p->head);
	pnew =NULL;	
//	*p->head = (pList)malloc(sizeof(sList));
//	printf("p:%p\n",pnew);
//	pnew = (pStu)malloc(sizeof(sStu));
	for(;;)
	{
			printf("input 1:insert 2:del 3:search(1:age 2:id) 4:print 5:save 6:exit\n");
			scanf("%d",&choose1);
			switch(choose1)
			{
				case INSERT:
						  	 p->pInsert = max;
							 init_node((void **)&pnew,sizeof(sStu));
						  	 p->pInsert(p->head,pnew,pIDFind,pInsertPosition);
						  	 break;			
				case DEL:
						  	 printf("please input del age\n");
						  	 p->pDel = del_age;
						  	 p->pDel(p->head,pDelPosition);
						  	 break;	
				case SEARCH: 
						     printf("please input choose 1:age 2id\n");
							 p->pSearch = find;
							 p->pSearch(p->head,pFun_Search);
							 break;
						
				case PRINT:
							 p->pPrint = input;
							 p->pPrint(p->head);
							 break; 
				case SAVE:

							 p->pStu_Save = save;
							 p->pStu_Save(p->head,fp);
				             break; 
				case EXIT:	
						     exit(-1);		
			}
	}
}
