#include"main.h"
enum ss
{
		insert=1,
		del,
		search,
		print,
		save,
		exit1
};	
void init(pList *ppp);
void inset(pList ppp);
int main()
{
		int i;
		pList ppp=NULL;
		init(&ppp);//初始化并开空间
		inset(ppp);//打开原来文件中的数据；
		do
		{
				printf("\n请输入你的选择:\n1 insert\n2 del\n3 search\n4 print\n5 save\n6 exit\n");

			scanf("%d",&i);
				switch(i)
				{
						case insert:Insert(ppp);break;  
						case del:Del(ppp);break;
						case search:Search(ppp);break;
						case print:Print(ppp);break;
						case save:Save(ppp);break;
						case exit1:destory(ppp);my_free((void **)&ppp);exit(0);break;
						default:printf("您的输入有误\n");exit(-1);break;
				}
		}while(1);
}
