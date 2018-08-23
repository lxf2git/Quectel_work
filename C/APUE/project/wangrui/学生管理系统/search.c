#include"search.h"



int pFun_age(pStu pHead,int n)
{
	int Age,flag=0;;
	pStu page = pHead;
	printf("请输入年龄\n");
	scanf("%d",&Age);
	while(page!=NULL){
			if(page->age == Age){
					printf("id相符的学生信息为:\n");
					printf("id:%d,年龄:%d\n",page->num,page->age);
					flag=1;
			}
			page = page->next;
	}
	if(flag==0)
			printf("没有符合年龄的学生\n");
}

int pFun_id(pStu pHead,int n)
{
	int Num,flag=0;;
	pStu pNum = pHead;
	printf("请输入id\n");
	scanf("%d",&Num);
	while(pNum!=NULL){
			if(pNum->num == Num){
					printf("id相符的学生信息为:\n");
					printf("id:%d,年龄:%d\n",pNum->num,pNum->age);
					flag=1;
			}
			pNum = pNum->next;
	}
	if(flag==0)
			printf("没有符合id的学生\n");
}

int pSearch(pStu pHead,int (*pFun_Search[2])(pStu pHead,int n))
{
	int i,n;
	printf("1----------按id查找\n");
	printf("2----------按年龄查找\n");
	scanf("%d",&i);
	if(i!=1&&i!=2){
			printf("选择有误，请重新选择\n");
			main();
	}
	n = i-1;
	(*pFun_Search[n])(pHead,n);
}

void search_chain(pStu pHead)
{
	int (*pFun_Search[2])(pStu pHead,int n)={pFun_id,pFun_age};
	(*pSearch)(pHead,pFun_Search);
}
