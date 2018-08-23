#include"del.h"
pStu DelPosition(pStu pNode,int age) //查找年龄的函数，并返回该年龄前一个的节点
{
		pStu ptmp = pNode;
		while(ptmp->next!=NULL)
		{
				if(ptmp->next->age == age)
				{
						return ptmp;
				}
				ptmp = ptmp->next;
		}
		return NULL;

}
void destory_chain(pStu ppdel)  //删除摘下来的链表
{
		pStu pdel=NULL;
		pdel = ppdel->next;
		ppdel->next = ppdel->next->next;
		pdel->next = NULL;
		my_free((void **)&pdel);
}
int del(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age))
{
		int age;
		pStu ppdel=NULL;
		printf("请输入需要删除哪个年龄的学生:\n");//删除某一年龄的学生
		scanf("%d",&age);
		ppdel = pDelPosition(pHead,age);     //查找学生的年龄，
		while(ppdel!=NULL)
		{
				destory_chain(ppdel);
				ppdel = pDelPosition(pHead,age);
		}
		

}
int Del(pList ppp)		//主函数入口函数
{
		ppp->pDel = del;//结构体中的函数指针赋值
		ppp->pDel(ppp->head,DelPosition);
		return 0;
}
int destory(pList ppp)  //主函数入口函数
{
		printf("*******************\n");
		pStu ptmp = ppp->head;
		while(ptmp->next!=NULL) //删除链表
		{
			destory_chain(ptmp);
			ptmp = ppp->head;
		}
}
