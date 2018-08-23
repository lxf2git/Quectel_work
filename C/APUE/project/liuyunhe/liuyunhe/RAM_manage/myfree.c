#include"myfree.h"

int strack(pmanage myfree_head,pmanage palit)		//插入到free链
{
		pmanage paar=myfree_head->next;
		if(paar==myfree_head)
		{
				myfree_head->next=palit;
				myfree_head->prev=palit;
				palit->next=myfree_head;
				palit->prev=myfree_head;
		}
		else
		{
				for(;paar!=myfree_head;paar=paar->next)
				{
						if(palit->index<paar->index)
						{
								palit->prev=paar->prev;
								palit->next=paar;
								paar->prev->next=palit;
								paar->prev=palit;
								return 0;
						}
				}
				myfree_head->prev->next=palit;
				palit->prev=myfree_head->prev;
				myfree_head->prev=palit;
				palit->next=myfree_head;

		}
}


int myfree(pmanage apply_head,pmanage myfree_head,pRecord precord_head,int app)
{
		int su;
		int i;
		pmanage paar;
		pRecord palit=precord_head;
		printf("free第几次的\n");
		printf("共输入%d次\n",app);
		scanf("%d",&su);
		for(i=0;i<su;i++)
		{
				palit=palit->next;
				if(palit==precord_head)
				{
						printf("输入次数越界\n");
						return 0;
				}
				
		}
		if(palit==precord_head)
		{
				printf("输入次数为0\n");
				return 0;
		}


		for(i=0;palit->pdata[i]!=NULL;i++)
		{
				for(paar=apply_head->next;paar!=apply_head;paar=paar->next)
				{
					if(paar->index==palit->pdata[i]->index)
					{
							paar->mem_size+=palit->pdata[i]->mem_size;

							palit->pdata[i]->prev->next=palit->pdata[i]->next;
							palit->pdata[i]->next->prev=palit->pdata[i]->prev;
							 palit->pdata[i]->prev=palit->pdata[i];
							 palit->pdata[i]->next=palit->pdata[i];
							 if( palit->pdata[i]!=NULL)
							 {
									 free(palit->pdata[i]);
									 palit->pdata[i]=NULL;
							 }
							 break;
					}
				}
				if(palit->pdata[i]!=NULL)
				{
						for(paar=apply_head->next;paar!=apply_head;paar=paar->next)
						{
							if(paar->index>palit->pdata[i]->index)
							{
									palit->pdata[i]->prev->next=palit->pdata[i]->next;
									palit->pdata[i]->next->prev=palit->pdata[i]->prev;
							 		palit->pdata[i]->prev=palit->pdata[i];
							 		palit->pdata[i]->next=palit->pdata[i];

									paar->prev->next=palit->pdata[i];
									palit->pdata[i]->next=paar;
									palit->pdata[i]->prev=paar->prev;
									paar->prev=palit->pdata[i];
									break;
							}
							
						}
			//			printf("*********\n");
						if(paar==apply_head)
						{
									palit->pdata[i]->prev->next=palit->pdata[i]->next;
									palit->pdata[i]->next->prev=palit->pdata[i]->prev;
							 		palit->pdata[i]->prev=palit->pdata[i];
							 		palit->pdata[i]->next=palit->pdata[i];

									palit->pdata[i]->prev=paar->prev;
									palit->pdata[i]->next=paar;
									paar->prev->next=palit->pdata[i];
									paar->prev=palit->pdata[i];
							
						}				
				}
		printf("free ok\n");
		}
}


exit_free(pmanage apply_head)
{
		pmanage palit;
		for(palit=apply_head->next;palit!=apply_head;)
		{
				palit->prev->next=palit->next;
				palit->next->prev=palit->prev;
				palit->next=palit;
				palit->prev=palit;
				free(palit);
				palit=apply_head->next;
		}	
}
