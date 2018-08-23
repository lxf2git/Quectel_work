#include"main.h"
int main()
{
		int a,i,b,n,c;
		pMem pHead;
		init_pnode(&pHead);
		create_tail_chain(pHead,10);
		pMem pHead1;
		init_pnode(&pHead1);
		pr pHead2;
		init_pnode1(&pHead2);
				show_chain(pHead);
				for(;;)
				{
						printf("1,2,3,4\n");
						scanf("%d",&b);
				switch(b)
				{
						case 1:
							printf("输入申请内存大小\n");
							scanf("%d",&a);
								apply(pHead,pHead1,a,pHead2);
							break;
						case 2:
							printf("输入释放内存次数\n");
							scanf("%d",&c);
							fre(pHead,pHead1,pHead2,c);
							break;
						case 3:
							printf("---\n");
							show_chain(pHead);
							show_chain(pHead1);
						//	show_chain1(pHead2);
							break;
						case 4:
						//	return 0;
							break;
				}
				if(b==4)
						break;
				}
}
