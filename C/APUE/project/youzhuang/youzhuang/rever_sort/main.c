#include"main.h"

void print(pMod hash)
{
		pWord phead=NULL;
		int i,j;
		for(i=0;i<ROW;i++)
		{
				for(j=0;j<COL;j++)
				{
						phead=hash->mod[i]->letter[j];
						pWord p=phead->next;
						while(p!=phead)
						{
								printf("                   i:%d   ",j);
								printf("j:%d   \n",i);
								output_word(p);
								p=p->next;
						}
				}
		}
		printf("\n");
}

int main()
{
		pMod hash=NULL;
		create_memory((void **)&hash,sizeof(sMod));
		init_hash(hash);
		menu(hash);
	//	print(hash);
		return 0;
}

int menu(pMod hash)
{
		int function;
		while(1)
		{
				printf("\n");
				printf("-------词典-------\n");
				printf("  1、添加文档\n");
				printf("  2、查找单词\n");
				printf("  3、退出\n");
				printf("------------------\n");
				printf("请选择功能:\n");
				scanf("%d",&function);
				if(fun(function,hash)==EMPTY)
				{
						return EMPTY;
				}
		}
}

int fun(int function,pMod hash)
{
		switch(function)
		{
				case ADDFILE:
						file(hash);
						break;
				case FINDWORD:
						find(hash);
						break;
				case EXIT:
						return EMPTY;
						break;
				default:
						printf("请按套路出牌!\n");
						break;
		}
		return SUB;
}
