#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
		char *name;
		int age;
		int id;
		struct Student *next;
}sStu,*pStu;

void creat_memory(pStu *p,int size)
{
	*p = (pStu)malloc(size);
 	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_memory(pStu *p,int size)
{
	creat_memory(p,size);
	(*p)->next = NULL; 
}

int load_num()
{
	FILE *fp;
  fp	= fopen("save.txt","r");
	int n;
	fseek(fp,-4,SEEK_END);
	fread(&n,4,1,fp);
	printf("n:%d\n",n);
	return n;
}


pStu load_chain()
{
	pStu pHead=NULL,ptmp;
	pHead=(pStu)malloc(sizeof(sStu));
	ptmp=pHead;
	FILE *fp;
	fp = fopen("save.txt","r");
	if(NULL==fp)
	{
		printf("fopen error\n");
		exit(-1);
	}
	
	int i,n;
	n = load_num();
	for(i=0;i<n;i++)
	{
		pStu pnew;
		pnew =(pStu)malloc(sizeof(sStu));
		ptmp->next=pnew;
		ptmp->next->name=malloc(20*sizeof(char));
		fgets(pnew->name,21*sizeof(char),fp);
		fread(&pnew->age,sizeof(int),1,fp);
		fread(&pnew->id,sizeof(int),1,fp);
		fseek(fp,1,SEEK_CUR);
		ptmp=pnew;
	}
	
	ptmp=pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("%s %d %d\n",ptmp->name,ptmp->age,ptmp->id);
	}

	return pHead;
}



pStu find_max(pStu pHead,pStu pnew)
{
	pStu ptmp=pHead;
	while(ptmp->next!=NULL)
	{
		if(ptmp->next->id >= pnew->id)
		{
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return ptmp;
}

int insert_back(pStu pPos,pStu pIn)
{
	if(pPos==NULL||pIn==NULL)
	{
		return -1;
	}
	pIn->next = pPos->next;
	pPos->next = pIn;

	return 0;
}

pStu Input(pStu pHead)
{
	pStu pnew=NULL;
	init_memory(&pnew,sizeof(sStu));
	printf("请输入学生姓名 年龄 序号\n");
	pnew->name = malloc(20*sizeof(char));
	scanf("%s %d %d",pnew->name,&pnew->age,&pnew->id);
	pStu pmax = find_max(pHead,pnew);
	insert_back(pmax,pnew);

}

void show_chain(pStu pHead)
{
	pStu ptmp=NULL;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("%3d %6s %3d \n",ptmp->id,ptmp->name,ptmp->age);
	}

}

void save_txt(pStu pHead)
{
	pStu ptmp=NULL;
	FILE *fp;
  fp = fopen("save.txt","w+");
	
	/*FILE *fp1;
	fp1 = fopen("num.txt","w+");
*/
	if(NULL==fp)
		{
			printf("fopen error\n");
			exit(-1);
		}
	char en[2]={'\n','\0'};
	int n=0;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		n++;
		fwrite(ptmp->name,20*sizeof(char),1,fp);
		fwrite(&ptmp->age,sizeof(int),1,fp);
		fwrite(&ptmp->id,sizeof(int),1,fp);
		fputs(en,fp);
	}
	fwrite(&n,sizeof(int),1,fp);
	printf("保存成功\n");
}

void Find(pStu pHead)
{
	printf("请输入查询的年龄信息\n");
	int age_f;
	scanf("%d",&age_f);
	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(age_f==ptmp->age)
		{
			printf("序号:%d 姓名:%6s 年龄:%d\n",ptmp->id,ptmp->name,ptmp->age);
		}
	}
}

int main()	
{
	int out = 1;
	pStu pHead=NULL;
	init_memory(&pHead,sizeof(sStu));
	pHead = load_chain();
	while(out==1)
	{
		printf("/***输入学生信息 按“1”号键***/\n");
		printf("/***查找学生信息 按“2”号键***/\n");
		printf("/***保存学生信息 按“3”号键***/\n");
		printf("/***打印学生信息 按“4”号键***/\n");
		printf("/***退出管理信息 按“5”号键***/\n");
		
		enum menu {input=1,find,save,print,exit};
	
		int i;
		scanf("%d",&i);
	
		switch(i)
		{
			case input:
					Input(pHead);
					break;
			case find:
					Find(pHead);
					break;
			case save:
					save_txt(pHead);
					break;
			case print:
					show_chain(pHead);
					break;
			case exit:
					printf("信息存储文件save.txt\n");
					out = 0;
					break;
			default:
					printf("choose error!\n");
					//exit(-1);
					break;
		}
	}
}
