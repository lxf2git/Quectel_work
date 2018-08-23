#include"huffman.h"
//压缩关键字z
//解压关键字x
int main(int argc,char *argv[])
{
	switch(argv[1][1])
	{
			case 'z':
			{
				compress_file(argv[2]);
				break;
			}
			case 'x':
			{
				uncompress_file(argv[2]);
				break;
			}
			default:
			{
				printf("hm: invalid option -- '%s'\n",argv[1]);
				printf("Try `hm -z' for compress file\n");
				printf("or `hm -x' for uncompress file.\n");
				return FAIL;
			}
	}	
	return 0;
}
void show_tree(pNode proot)
{
	mid_tree(proot);
	printf("\n");
}
void mid_tree(pNode pnode)
{
	printf("ch:%c weight:%d\n",pnode->data,pnode->weight);
	if(pnode->lc != NULL)
	{
		mid_tree(pnode->lc);
	}
//	printf("ch:%c weight:%d\n",pnode->data,pnode->weight);
	if(pnode->rc != NULL)
	{
		mid_tree(pnode->rc);
	}
}
void show_chain(pNode pHead)
{
	pNode ptmp = NULL;
	for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
	{
		printf("data:%c %d\n",ptmp->data,ptmp->weight);
	}
}     
