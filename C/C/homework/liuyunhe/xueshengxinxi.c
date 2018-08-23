#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
		char *name;
		int age;
		int id;
		struct Node *next;
}sNode,*pNode;

void Deatory_deat(pNode *pdel);

gmemory(void **p,int size)			//开空间
{
		*p= malloc(size);
}

enum en_name
{
		input =1,
		find,
		save,
		print,
		quit,

};

pNode input_sort(pNode pHead,pNode pNew)
{
		pNode palit=pHead;
		while(palit->next!=NULL)
		{
				if(palit->next->id >= pNew->id)
				{
						return palit;
				}
				palit=palit->next;
		}
		return palit;

}

int input_back(pNode pSort,pNode pNew)
{
		if(pSort==NULL||NULL==pNew)
		{
				printf("pSort||pNew为空\n");
				exit (-1);
		}
		pNew->next = pSort->next;
		pSort->next=pNew;
		return 0;
}

void input_(pNode pHead)
{
		pNode pNew;
		gmemory((void **)&pNew,sizeof(sNode));
		gmemory((void **)&pNew->name,10*sizeof(char));
		pNew->next=NULL;
		printf("请输入学生的姓名 年龄 id\n");
		scanf("%s%d%d",pNew->name,&pNew->age,&pNew->id);
		pNode pSort = input_sort(pHead,pNew);
		input_back(pSort,pNew);
}

void find_retur2(pNode pHead,int age)
{
		int i=0;
		pNode palit=pHead->next;
		while(palit!=NULL)
		{
				if(palit->age==age)
				{
					
						printf("name: %s age: %d id: %d \n",
										palit->name,palit->age,palit->id);
						i++;
				}
				palit=palit->next;
		}
		if(i==0)
		{
				printf("没有要查找的年龄\n");
		}
}
void find_(pNode pHead)
{
		int age;
		printf("请输入要查找的年龄\n");
		scanf("%d",&age);
		find_retur2(pHead,age);
}

void save_(pNode pHead)
{
		int i=0;
		FILE *fp;
		fp=fopen("student.txt","w+");
		pNode palit;
		palit=pHead->next;
		while(palit!=NULL)
		{
				fwrite(palit->name,10*sizeof(char),1,fp);
				fwrite(&palit->age,sizeof(int),1,fp);
				fwrite(&palit->id,sizeof(int),1,fp);
				palit=palit->next;
				i++;
		}
		fwrite(&i,sizeof(int),1,fp);
		fclose(fp);

}

void print_(pNode pHead)
{
		int i=0;
		FILE *fp1;
		fp1=fopen("student.txt","r+");
		fseek(fp1,-4,SEEK_END);
		fread(&i,sizeof(int),1,fp1);
	//	printf("%d",i);
		fseek(fp1,0,SEEK_SET);
		pNode palit;
		palit=pHead->next;
		pNode ppr;
		gmemory((void **)&ppr,sizeof(sNode));
		gmemory((void **)&ppr->name,10*sizeof(char));
		for(i;i>0;i--)
		{
				fread(ppr->name,10*sizeof(char),1,fp1);
				fread(&ppr->age,sizeof(int),1,fp1);
				fread(&ppr->id,sizeof(int),1,fp1);
				printf("name: %s age: %d id: %d \n",
								ppr->name,ppr->age,ppr->id);
		}
		fclose(fp1);
		Deatory_deat((pNode *)&ppr->name);
		Deatory_deat(&ppr);
}

void Deatory_deat(pNode *pdel)
{
		if(*pdel!=NULL)
		{
				free(*pdel);
				*pdel=NULL;
		}
}

void Destory_list(pNode *pHead)
{
		pNode pdel=NULL;
		while((*pHead)->next!=NULL)
		{
				pdel=(*pHead)->next;
				Deatory_deat((pNode *)&pdel->name);
				(*pHead)->next=(*pHead)->next->next;
				pdel->next=NULL;
				Deatory_deat(&pdel);
		}
}

int main()
{
		int scan;
		pNode pHead;
		gmemory((void **)&pHead,sizeof(sNode));
		while(1)
		{
		printf("选择菜单\n");
		printf("1.输入学生信息\n");
		printf("2.查询（按年龄查询）\n");
		printf("3.保存\n");
		printf("4.打印\n");
		printf("5.退出\n");
		scanf("%d",&scan);
				switch (scan)
				{
						case input:
								input_(pHead);
								break;
						case find:
								find_(pHead);
								break;
						case save:
								save_(pHead);
								break;
						case print:
								print_(pHead);
								break;
						case quit:
		Destory_list(&pHead);
								return 0;
								break;
						befaulu:
								printf("输入选择错误\n");
								break;

				}
		}
}
