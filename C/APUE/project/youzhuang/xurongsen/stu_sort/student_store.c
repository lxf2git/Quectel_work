#include "student.h"

/*
 *该文件有一下几个函数
 *
void openfile(FILE **pin)        //打开一个文件作为磁盘，用于存储学生的信息
void create_memory(void **p, int size) //创建内存
void init_node(pStu *pp, int size)     //创建节点，开开空间，p->next=null;
int insert_back(pStu pPos, pStu pIn)   //在pPos位置之后插入pIn 节点
pStu find_first_max(pStu pHead, pStu pnew) //找到第一个节点的ID大于pnew的节                                            //点，并返回该节点之前的节点
void input_message(pStu *pstu,FILE *pin)             //输入信息
void show_node(pStu pHead)                 //显示信息
void save_file(pStu pHead,FILE *pin)       //保存链表到文件中
void find_age(int age,FILE *pin,pStu pHead)             //到文件中查询id的信息
void close_release(FILE **pin,pStu *ppHead) //释放文件，节点
void Destory_node(pStu *pp)                //销毁节点，指向赋值为空
int id_look(pStu pHead,int id)             //id冗余检验
void choose()                           //选择功能
 * ***/

void openfile(FILE **pin)
{
	*pin = fopen("/home/struct/18_s/works/a.txt","a+");
	if(NULL == *pin)
	{
		printf("pin open fail !\n");
		
	}
}

void create_memory(void **p, int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}

void init_node(pStu *pp, int size)
{
	create_memory((void **)pp,size);
	(*pp)->next = NULL;
//	printf("init_node---success!\n");
}

int insert_back(pStu pPos, pStu pIn)
{
	if(NULL==pPos || NULL==pIn)
	{
		printf("排序位置不能为空或插入节点不能为空！\n");
		return -1;
	}
	pIn->next = pPos->next;
	pPos->next = pIn;
}

pStu find_first_max(pStu pHead, pStu pnew)
{
	pStu pTrav = pHead;
	while(pTrav->next != NULL)
	{
		if(pTrav->next->id >= pnew->id)
		{
			return pTrav;
		}
		pTrav = pTrav->next;
	}
	return pTrav;
}

int id_look(pStu pHead,int id)
{
	pStu pnew=NULL;
	for(pnew=pHead->next;pnew != NULL;pnew=pnew->next)
	{
		if(id == pnew->id)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}		
}

void input_message(pStu *pstu,FILE **pin)
{
	pStu pnew,pmax;
	int i,num,ret=0;
	printf("please input nember of student:");
	scanf("%d",&num);
//----------------------------------------------
#if 0
	int len = sizeof(sStu);
	pStu p;
	fseek(*pin, 0, SEEK_SET);
	while(!feof(*pin))
	{
		init_node(&p, sizeof(sStu));
	//	printf("len:%d\n",len);
	//	printf("&p:%p\n",p);
		fread(p,1,len,*pin);
		if(NULL != p)
		{
	//	printf("file student of message:%s %d %d\n",p->name,
	//					p->age,p->id);
			pmax = find_first_max(*pstu,p);
				insert_back(pmax, p);
			//	*pstu = p;
			//	fseek(*pin,len,SEEK_CUR);
			//	fread(p,1,len,*pin);
			//	break;
		}
	//	break;
	}
#endif
//---------------------------------------------

	for(i=0;i<num;i++)
	{
		init_node(&pnew, sizeof(sStu));
		printf("please input message of %d (name,age,id):",i+1);
		scanf("%s",(pnew->name));
		scanf("%d%d",&(pnew->age),&(pnew->id));
		ret = id_look(*pstu,pnew->id);
		if(0 == ret)
		{
			pmax = find_first_max(*pstu,pnew);
			insert_back(pmax, pnew);
		}
		else
		{
			printf("%d has the same id!\n",pnew->id);
			input_message(pstu,pin);
		}
	}
//	printf("input_message--->success!\n");
}

void show_node(pStu pHead)
{
	pStu pnew=NULL;
	int i=0;
	for(pnew=pHead->next;pnew != NULL;pnew=pnew->next)
	{
		if(pnew->age != 0)
		{		
		i++;
		printf(" %d student of message:%s %d %d\n",i,pnew->name,
						pnew->age,pnew->id);
		}
	}
}

void save_file(pStu pHead,FILE *pin)
{
	pStu p=NULL;
	int len;
	len = sizeof(sStu);
	for(p=pHead->next;p != NULL;p=p->next)
	{
		fwrite(p, 1, len, pin);
	}
	
}

void find_age(int age,FILE *pin,pStu pHead)
{
	pStu p=NULL;
	int a=0;//判断是否找到
	int len;
	len = sizeof(sStu);
	init_node(&p,sizeof(sStu));

	printf("accord with:\n");
	for(p=pHead->next;p != NULL;p=p->next)
	{
		if(p->age == age)
		{
			printf("name:%s  age:%d id:%d\n",
						p->name,p->age,p->id);
			a=1;
		}
	}
#if 0         
	//从已保存的磁盘上读取
	fseek(pin, 0, SEEK_SET);
	fread(p,1,len,pin);
		while(NULL != p)
		{
			if(p->age == age)
			{
				printf("find student of message:%s %d %d\n",p->name,
						p->age,p->id);
				a=1;
				break;
			}
			else
			{
				fread(p,1,len,pin);
			}
				fseek(pin,len,SEEK_CUR);
				fread(p,1,len,pin);
		}
#endif
	if(a == 0)
	{
		printf("no find age is %d!\n",age);
	}
}

void Destory_node(pStu *pp)
{
	if(NULL != *pp)
	{
		free(*pp);
		*pp = NULL;
	}
}

void close_release(FILE **pin,pStu *ppHead)
{
	fclose(*pin);
	pStu pdel = NULL;
	while((*ppHead)->next != NULL)
	{
		pdel = (*ppHead)->next;
		(*ppHead)->next = pdel->next;
		pdel->next = NULL;
		Destory_node(&pdel);
	}
	Destory_node(ppHead);
}

void choose(FILE **pin)
{
	int m;
	pStu pHead;
	init_node(&pHead,sizeof(sStu));
	printf("please choose (1:输入 2:查找 3:保存 4:打印所有信息 5:退出)");
	scanf("%d",&m);
	do
	{
	switch(m)
	{
		case INPUT:
				{
					input_message(&pHead,pin);
					break;
				}
		case FIND:
				{
					printf("please input age of your search:");
					int age;
					scanf("%d",&age);
					find_age(age,*pin,pHead);
					break;
				}
		case SAVE:
				{
		//			input_message();
					save_file(pHead,*pin);
					break;
				}
		case PRINT:
				{
					show_node(pHead);
					break;
				}
		case QUIT:
				{
					close_release(pin,&pHead);
					break;
				}
		default:
				{
					printf("input error!\n");
					choose(pin);
					break;
				}
	}
	}while(printf("choose(1:输入2:查找3:保存4:打印所有信息5:退出)") 
					&& (scanf("%d",&m)) && m != 5);
}

int main()
{
	FILE * pin;
	openfile(&pin);

	choose(&pin);


}
