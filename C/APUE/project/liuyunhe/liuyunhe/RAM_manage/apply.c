#include"apply.h"


void apply_max(pmanage apply_head,pmanage *palit_max)
{
		int mem_size_sum=0;
		int mem_size_max=0;
		pmanage palit=apply_head->next;
		while(palit!=apply_head)
		{
				if(mem_size_max < palit->mem_size)
				{
						mem_size_max=palit->mem_size;
						(*palit_max)=palit;
				}
				mem_size_sum+=palit->mem_size;
				palit=palit->next;
		}
		apply_head->mem_size=mem_size_sum;
}

void select(pmanage apply_head,pmanage myfree_head,
				pRecord precord_head,pmanage *palit_max)
{
		int space;
		printf("please scan space\n");
		scanf("%d",&space);
		int i=0;
		pmanage palit;
		pRecord precord_new;
		pre_memory(&precord_new);

	//	printf("apply_head->mem_size:%d\n",apply_head->mem_size);
		if(space<=apply_head->mem_size)
		{
				while(space!=0)
				{
						if(space<=(*palit_max)->mem_size)
						{
								for(palit=apply_head->next;palit!=
											apply_head;palit=palit->next)
								{
										if(space==palit->mem_size)
										{
											palit->prev->next=palit->next;
											palit->next->prev=palit->prev;
											palit->prev=palit;
											palit->next=palit;
													strack(myfree_head,palit);
													precord_new->pdata[i]=palit;
													i++;
													space=0;
													break;
										}
								}
								if(space!=0)
								{
										great_memory(&palit);
										palit->index=(*palit_max)->index;
										palit->mem_size=space;
										((*palit_max)->mem_size)-=space;
										strack(myfree_head,palit);

										precord_new->pdata[i]=palit;
										i++;

										space=0;
								}
						}
						else
						{
								(*palit_max)->prev->next=(*palit_max)->next;
								(*palit_max)->next->prev=(*palit_max)->prev;
								(*palit_max)->prev=(*palit_max);
								(*palit_max)->next=(*palit_max);
								strack(myfree_head,(*palit_max));
								space=space-(*palit_max)->mem_size;

								precord_new->pdata[i]=(*palit_max);
								i++;
								apply_max(apply_head,palit_max);

						}
						printf("apply ok\n");
				}
		}
		else
		{
				printf("空间不够\n");
		}
		precord_new->next=precord_head;
		precord_new->prev=precord_head->prev;
		precord_head->prev->next=precord_new;
		precord_head->prev=precord_new;
}

void apply(pmanage apply_head,pmanage myfree_head,pRecord precord_head)
{
		pmanage palit_max=NULL;
		apply_max(apply_head,&palit_max);

		select(apply_head,myfree_head,precord_head,&palit_max);
}
