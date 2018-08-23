#include"search.h"
int fun_ID(pStu pHead,int num)//查询Id的函数
{
		pStu ptmp=NULL;
		ptmp = pHead;
		while(ptmp->next!=NULL)
		{
				if(ptmp->next->num == num)
				{
						printf("ID:%d AGE:%d\n",ptmp->next->num,ptmp->next->age);
				}
				ptmp = ptmp->next;
		}
		return 0;
}
int fun_AGE(pStu pHead,int age)//查询年龄的函数
{
		pStu ptmp=NULL;
		int count=0;
		ptmp = pHead;
		while(ptmp->next!=NULL)
		{
				if(ptmp->next->age == age)
				{
						count++;
				}
				ptmp = ptmp->next;
		}
		printf("共有%d个%d岁的人",count,age);
		return 0;
}
int search_(pStu pHead,int (*pFun_search[2])(pStu pHead,int num))
{
		int find,choose;
		printf("1:ID查询\n2:AGE查询\n");
		scanf("%d",&choose);
		printf("请输入需要查询的数字:\n");
		scanf("%d",&find);
		if(choose==1)
		{
				pFun_search[0](pHead,find); //调用
		}
		if(choose==2)
		{
				pFun_search[1](pHead,find);
		}
}
int Search(pList ppp)//主函数入口
{
		int (*pFun_search[2])(pStu pHead,int num);//定义一个函数指针数组
		ppp->pSearch = search_;
		pFun_search[0] = fun_ID;//对函数指针赋值
		pFun_search[1] = fun_AGE;
		ppp->pSearch(ppp->head,pFun_search);
		return 0;
}

//函数指针数组，1声明2赋值3调用；
