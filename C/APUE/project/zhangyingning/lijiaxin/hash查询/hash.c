#include"hash.h"

creat_chain(struct data *pHead,struct data *pnew)
{
		pnew->next = pHead;
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
}
void deal(int in_data,struct data *p)
{
	//	printf("创建链表并对data赋值\n");
		struct data *pnew = NULL;
		get_memory((void **)&pnew,sizeof(struct data));
		pnew->data = in_data;
		creat_chain(p,pnew);
}
int finds(struct data *pHead,int fdata)
{
	//	printf("对新输入数据hush进行查询.\n");
		struct data *ptmp=pHead;
		while(ptmp->next!=pHead)
		{
				if(fdata == ptmp->next->data)
				{
						printf("存在");
						return 0;
				}
		}
		printf("不存在.\n");
		return -1;

}
void destory(struct data *pHead)
{
		struct data *ptmp=pHead->next;
		while(ptmp!=pHead)
		{
				pHead->next = ptmp->next;
				ptmp->next->prev = pHead;
				my_free((void **)&ptmp);
	//			printf("IIIIIIIIIIII\n");				
				ptmp = pHead->next;
		}
}
int main()
{
		int i,j,input_data;
		int sum;
		int find_data;
		struct mod p;
		struct and_ pand;
		printf("sizeof(p):%d",sizeof(p));
		for(i=0;i<5;i++)
		{
			get_memory((void **)&(p.mod)[i],sizeof(struct and_));
			printf("sizeof(p.mod[%d]):%d\n",i,sizeof(p.mod)[i]);
			for(j=0;j<8;j++)
			{
					get_memory((void **)&((p.mod)[i]->and)[j],sizeof(struct data));
					((p.mod)[i]->and)[j]->prev = ((p.mod)[i]->and)[j];
					((p.mod)[i]->and)[j]->next = ((p.mod)[i]->and)[j];
			}
		}
		printf("请输入要操作的数据个数\n");
		scanf("%d",&sum);
		while(sum--)
		{
			printf("请输入需要存入的数据.\n");
			scanf("%d",&input_data);
			deal(input_data,((p.mod)[input_data%5]->and)[input_data&7]);
		}
		printf("请输入需要查找的数据。\n");
		scanf("%d",&find_data);
		finds(((p.mod)[find_data%5]->and)[find_data&7],find_data);
		for(i=0;i<5;i++)
		{
			for(j=0;j<8;j++)
			{
					destory(((p.mod)[i]->and)[j]);
					my_free((void **)&((p.mod)[i]->and)[j]);
			 }
			my_free((void **)&((p.mod)[i]));
		}


		
}

