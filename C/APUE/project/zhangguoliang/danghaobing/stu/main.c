#include"main.h"

void free_Node(pStu *pNode)
{
	if(*pNode!=NULL)
	{
			free(*pNode);
			*pNode=NULL;
	}
}

void destroy(pStu *pHead)
{
		pStu ptmp = *pHead;
		while(ptmp->next!=NULL)
		{
				pStu pdel = ptmp->next;
				ptmp->next=ptmp->next->next;
				free_Node(&pdel);
		}
		free_Node(pHead);
}

int main()
{
		pList plist = NULL;
		init_list(&plist,sizeof(sList));
		init_Node(&plist->head,sizeof(sStu));
		FILE *fp = NULL;
		fp = fopen("student.txt","w+");
		int x;//选择功能
		for(;;)
		{
			printf("please input number below!\n");
			printf("1 insert student information\n"
					"2 delete information in the chain\n"
					"3 search student from age or id\n"
					"4 print students' information\n"
					"5 save information in the chain\n"
					"6 exit the system\n");
			scanf("%d",&x);
			switch(x)
			{
					case 1:
							printf("please input how many student you'll input\n");
							int h;
							scanf("%d",&h);
							while(h>0)
							{
								pStu pInser = Insert_pnew();
								int ret = plist->pInsert(plist->head,pInser,IDFind,InsertPosition);
								if(ret==1)
								{
										h++;
								}
								h--;
							}
							break;
					case 2:
							plist->pDel(plist->head,DelPosition);
							break;
					case 3:
							{
							int (*Fun_Search[2])(pStu,int);
							Fun_Search[1]=Fun_Searchi;
							Fun_Search[2]=Fun_Searcha;
							plist->pSearch(plist->head,Fun_Search);
							}
							break;
					case 4:
							plist->pPrint(plist->head);
							printf("input '0' to continue!\n");
							int key=0;
							scanf("%d",&key);
							break;
					case 5:
								plist->pStu_Save(plist->head,fp);
							break;
					case 6:	
							destroy(&plist->head);
							exit(0);
					default:
							printf("choose error! please input again!\n");
							break;
			}

		}

		return 0;
}
