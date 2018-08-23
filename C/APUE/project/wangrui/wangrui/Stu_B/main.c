#include"student.h"
int main()
{
		int choose;
		pStu pIn = NULL;
		FILE *fp = NULL;
		int In_sus;	//init------
		int De_sus;
		int Se_sus;
		int Sa_sus;
		int Lo_sus;

		sList sFun;				//init
		Init_Stu(&sFun.head);	//head
		pStu pHead = sFun.head;	//head

		sFun.pInsert = Insert;	//2 insert 1
		sFun.pDel = Del;		//2 delete 2
		sFun.pSearch = Search;	//2 Search 3 
		sFun.pPrint = Print;	//2 print  4
		sFun.pStu_Save = Stu_Save;	//2 save 5
		
		Lo_sus = Stu_Load(pHead,fp);	//load
		printf("Load\n");
		Judge(Lo_sus);

		do
		{
			switch(choose = Menu())
			{
				case 1:
				{
					pIn = input();
					In_sus=(sFun.pInsert)(
									pHead,
									pIn,
									IDFind,
									InsertPos
									);
					Judge(In_sus);
					break;
				}
				case 2:
				{
					De_sus=(sFun.pDel)(
								   pHead,
								   DelPos
								   );
					Judge(De_sus);			
					break;
				}					
				case 3:
				{
					Se_sus=(sFun.pSearch)(
									pHead,
									Fun_Search
									);
					Judge(Se_sus);
					break;	
				}
				case 4:
				{
					(*sFun.pPrint)(pHead);
					break;
				}
				case 5:
				{
					Sa_sus=(sFun.pStu_Save)(
									pHead,
									fp
									);
					Judge(Sa_sus);
					break;
				}
				case 6:
				{
					Exit(&pHead);
					break;
				}
				default:
				{
					printf("choose error!\n");
					break;
				}
			}
		}while(choose != 6);
		return 0;
}
int Menu()
{
		int a;
		printf("choose");
		scanf("%d",&a);
		return a;
}

void Judge(int sus)
{
		if(sus == 0)
		{
			printf("Success\n");
		}
		else
		{
			printf("Failed\n");
		}
}

