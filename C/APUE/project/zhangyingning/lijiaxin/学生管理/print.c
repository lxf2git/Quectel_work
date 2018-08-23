#include"print.h"
void print(pStu pHead)//输出函数
{
		pStu ptmp = pHead;
		while(ptmp->next!=NULL)
		{
				printf("ID:%d AEG:%d \n",ptmp->next->num,ptmp->next->age);
				ptmp=ptmp->next;
		}
}
void creat_tail_chain(pStu pHead,pStu pnew)//把之前文件的重新建链表
{
		pHead->next = pnew;
}
void inset(pList ppp)//主函数入口
{
		FILE *pf = NULL;
		pf = fopen("student.txt","r");
		pStu fpp=NULL;
		init_S(&fpp);
		pStu p_back=ppp->head;
		int count = 0;
		while(1)
		{
				count = fread(fpp,sizeof(sStu),1,pf);
				if(count==0)
				{
						break;
				}
				creat_tail_chain(p_back,fpp);
				p_back = fpp;
				init_S(&fpp);
		}
		fclose(pf);
}
int Print(pList ppp) //主函数入口
{
		ppp->pPrint = print;//结构体中的函数指针赋值
		ppp->pPrint(ppp->head);
		return 0;
}
