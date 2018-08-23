#include"huffman.h"

int compress_file(char *fname)
{
	FILE *pof = NULL;	//被操作文件	
	FILE *pnf = NULL;	//新建压缩文件
	char new_file[256];
	pNode pHead = NULL;
	pNode proot = NULL;

	init_node(&pHead);	//初始化链头，用于遍历接权值
	pHead->parent = pHead;
	pHead->next = pHead;

	pof = fopen(fname,"r");//只读方式打开被操作文件
	if(pof == NULL)
	{
		printf("hm: cannot compress`%s' : No such file\n",fname);//判断被压缩文件是否存在
		return FAIL;
	}

	//deal_chain.c
	creat_chain(pHead,pof);	//遍历建链获得权值
//	show_chain(pHead);
	sort_chain(&proot,pHead);	//排序
	proot = creat_huffman_tree(pHead);	//建huffman树
//	show_tree(proot);
//	show_chain(pHead);

	sprintf(new_file,"%s.hm",fname);	//命名压缩文件
	pnf = fopen(new_file,"w");	//写方式建立压缩文件
	if(pnf == NULL)
	{
		printf("compress fail\n");	//容错
		return FAIL;
	}
	rewind(pof);
	do_compress(pnf,pof,pHead,proot);

	fclose(pof);
	fclose(pnf);
	return SUC;
}
void do_compress(FILE *pnf,FILE *pof,pNode pHead,pNode proot)
{
	char ch;
	char bt = 0x00;
	int i = 0;
	pNode ptmp = NULL;
	pStack ps = NULL;
	int pop_b = 0;
	int ret = 0;
	init_stack(&ps);
//	fwrite(pHead,sizeof(sNode),1,pnf);	//存入头
	save_huffman_tree(pnf,proot);		//先序存入树
	ch = fgetc(pof);
	push_data_node(pHead,ch,ps);	//找到ch对应的叶子节点
	while(!feof(pof))	//写入
	{
		while(i<8)
		{
			ret = pop(ps,&pop_b);
				if(ret == EMPTY)
				{
						break;
				}
				if(pop_b == 1)
				{
					bt <<= 1;
					bt |= 0x01;
	//				printf("1");
				}
				if(pop_b == 0)
				{
					bt <<= 1;
					bt |= 0x00;
	//				printf("0");
				}
				i++;
		}
		if(i >= 8)
		{
			i = 0;
	//		bt = bin8_rev(bt);
	//		printf("%c",bt);
			fwrite(&bt,1,1,pnf);
			bt = 0x00;
		printf(" ");
		}
		if(ret == EMPTY)
		{
			ch = fgetc(pof);
			push_data_node(pHead,ch,ps);
		}
		
	}
	while(i<8&&i>0)
	{
		i++;
		bt <<= 1;	//处理一下
//		bt = bin8_rev(bt);
	}
	fwrite(&bt,1,1,pnf);
}
int push_data_node(pNode pHead,char ch,pStack ps)
{
	pNode ptmp = NULL;
	for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
	{
		if(ptmp->data == ch)
		{
			break;
		}
	}
	if(ptmp == pHead)
	{
		return FAIL;
	}
//	printf("\n%c:",ptmp->data);
	while(ptmp->parent != NULL)
	{
		if(ptmp->parent->lc == ptmp)
		{
//			printf("1");
			push(ps,1);
		}
		if(ptmp->parent->rc == ptmp)
		{
//			printf("0");
			push(ps,0);
		}
		ptmp = ptmp->parent;
	}
//	printf("\n");
	return SUC;
}
/*
char bin8_rev(char bt)
{
	bt = (bt&0xF0>>4)|(bt&0x0F<<4);
	bt = (bt&0xCC>>2)|(bt&0x33<<2);
	bt = (bt&0xAA>>1)|(bt&0x55<<1);
	return bt;
}*/
void save_huffman_tree(FILE * pnf,pNode pnode)
{
	pNode pnull = NULL;
	fwrite(pnode,sizeof(sNode),1,pnf);
	if(pnode->lc != NULL)
	{
		save_huffman_tree(pnf,pnode->lc);
	}
	else
	{
		init_node(&pnull);
		pnull->weight = -1;
		fwrite(pnull,sizeof(sNode),1,pnf);	//空处存入weight=-1的节点
		free_node(&pnull);
	}
	if(pnode->rc != NULL)
	{
		save_huffman_tree(pnf,pnode->rc);
	}
	else
	{
		init_node(&pnull);
		pnull->weight = -1;
		fwrite(pnull,sizeof(sNode),1,pnf);
		free_node(&pnull);
	}
}
/*
void show_chain(pNode pHead)
{
	pNode ptmp = NULL;
	for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
	{
		printf("data:%c %d\n",ptmp->data,ptmp->weight);
	}
}*/
