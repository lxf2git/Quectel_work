#include"insert.h"
int stu_Input(struct student *pnew)//输入函数
{
		printf("请输入学生的学号和年龄\n");
		scanf("%d%d",&pnew->num,&pnew->age);
}
pStu InsertPosition(pStu pTrav,pStu pInsert)//待插入的节点位置
{
		while(pTrav->next!=NULL)
		{
				if(pTrav->next->num > pInsert->num)
				{
						return pTrav; 
				}
				pTrav = pTrav->next;
		}
		return pTrav;
}
int IDFind(pStu pHead,pStu pInsert)//ID查询
{
		pStu ptmp = pHead->next;
		while(ptmp!=NULL)
		{
				if(ptmp->num == pInsert->num)
				{
						return 1;
				}		
				ptmp=ptmp->next;
		}
		return 0;
}
void creat_chain(pStu pp,pStu pInsert)//创建链表
{
				 pInsert->next = pp->next;
				 pp->next = pInsert;
}
int ppInsert(pStu pHead,pStu pInsert,int(*pIDFind)(pStu,pStu),pStu(*pInsertPosition)(pStu ,pStu ))
{
		int num=0;
		pStu pp=NULL;
		init_S(&pInsert);//调用初始化函数开空间
		pInsert->stu_input = stu_Input;//调用函数指针中的指针并赋值传参
		pInsert->stu_input(pInsert);
		num = IDFind(pHead,pInsert); //调用函数查找ID
		while(num != 0)//判断ID是否被使用，若使用重新注册并查找
		{
				printf("id已被注册,请重新输入:\n");
				pInsert->stu_input(pInsert);
				num = IDFind(pHead,pInsert);
				printf("num %d",num);
		}
		pp = InsertPosition(pHead,pInsert);//对插入的ID进行排序
		creat_chain(pp,pInsert);
}
int Insert (pList ppp)  //主函数的接口；
{
		pStu pnew=NULL;
		ppp->pInsert = ppInsert; //调用结构体的pInsert函数指针并赋值
		ppp->pInsert(ppp->head,pnew,IDFind,InsertPosition);
}
