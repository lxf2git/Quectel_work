#include"main.h"
int main()
{
		int n,ret;
		char ch;
		FILE *fp=NULL;
		pStu pHead = NULL;
		init_node(&pHead);
		pStu pnew=NULL;
		sList fun;
		pList po =&fun;
		po->pInsert = Insert;
		po->pDel = Delete;
		po->pPrint = Print;
		po->pSearch = Search;
		po->pStu_Save = Save;
		int (*pFun_Search[2])(pStu pHead,int num) = {Search_id,Search_age};
		read_file(pHead,fp);
		while(1)
		{	
				printf("please input choose \n1 insert 2 del 3 search(1 age 2 id)\n4 print 5 save 6 exit\n");
				scanf("%d",&n);
				while(getchar()!='\n');
				init_node(&pnew);
				switch(n)
				{
						case INSERT:
								(po->pInsert)(pHead,pnew,Idfind,InsertPosition); 
								break;
						case DEL:
								(po->pDel)(pHead,DelPosition);
								break;
						case SEARCH:
								(po->pSearch)(pHead,pFun_Search);
								break;

						case PRINT:
								(po->pPrint)(pHead);
								break;
						case SAVE:
								(po->pStu_Save)(pHead,fp);
								break;
						case EXIT:
								{
										printf("Exit before sure save Y/N?\n");
										scanf("%c",&ch);
										while(getchar()!='\n');
										if(ch == 'Y')
										{
												(po->pStu_Save)(pHead,fp);
												exit(-1);
										}
										else if(ch == 'N')
										{
												exit(-1);
										}
										else
										{
												printf("save error\n");
												exit(-1);
										}
								}
						default :
								printf("input error please again\n");
								break;
				}
		}
}
void read_file(pStu phead,FILE *ff)
{
		int re,i=0; 
		pStu pread = NULL; 
		pStu ptmp = phead;
		ff = fopen("save.txt","r");
		while(NUM)
		{
				init_node(&pread);
				re  = fread(pread,sizeof(sStu),NUM,ff);
				if(re <= 0)
				{
						break;
				}
				ptmp->next = pread;
				pread->next = phead;
				ptmp = ptmp->next;
		}
		fclose(ff);
}
