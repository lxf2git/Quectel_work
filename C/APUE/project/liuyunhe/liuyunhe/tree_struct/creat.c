#include"creat.h"

void creat_rc_lc(pTree pTree_head,pTree pTree_new)
{
		if(pTree_new->tr_data<=pTree_head->tr_data)
		{
				if(pTree_head->tr_lc==NULL)
				{
						pTree_head->tr_lc=pTree_new;
						pTree_new->tr_parent=pTree_head;
				}
				else
				{
						creat_rc_lc(pTree_head->tr_lc,pTree_new);
				}
		}

		if(pTree_new->tr_data>pTree_head->tr_data)
		{
				if(pTree_head->tr_rc==NULL)
				{
						pTree_head->tr_rc=pTree_new;
						pTree_new->tr_parent=pTree_head;
				}
				else
				{
						creat_rc_lc(pTree_head->tr_rc,pTree_new);
				}
		}

}
void creat(pTree pTree_head)
{
		int data;
		pTree pTree_new;
		greate_memory(&pTree_new);
		init_tree(pTree_new);
		printf("请输入一个整数\n");
		scanf("%d",&data);
		if(pTree_head->tr_data==0)
		{
				pTree_head->tr_data=data;
		}
		else
		{
				pTree_new->tr_data=data;
			   creat_rc_lc(pTree_head,pTree_new);	
		}

}
