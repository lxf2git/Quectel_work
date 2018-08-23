#include"init.h"

pTree delete_if(pTree *palit,pTree pTree_head,int data)
{
	//	printf("%4d",pTree_head->tr_data);
		if(pTree_head->tr_data==data)
		{
	//	printf("==%4d",pTree_head->tr_data);
			 *palit=pTree_head;
		}
		else
		{
				if(pTree_head->tr_lc!=NULL)
				{
						delete_if(palit,pTree_head->tr_lc,data);
				}
				
				if(pTree_head->tr_rc!=NULL)
				{
						delete_if(palit,pTree_head->tr_rc,data);
				}
		}
}
int delete(pTree *pTree_head)
{
		int data;
		pTree palit=NULL;
		pTree paar=NULL;
		printf("请输入要删除的数\n");
		scanf("%d",&data);
		delete_if(&palit,*pTree_head,data);
		if(palit!=NULL)
		{
				printf("palit:%d\n",palit->tr_data);
				if(palit->tr_lc==NULL&&palit->tr_rc==NULL)
				{
						if(palit->tr_parent->tr_lc==palit)
						{
								palit->tr_parent->tr_lc=NULL;
						}
						if(palit->tr_parent->tr_rc==palit)
						{
								palit->tr_parent->tr_rc=NULL;
						}
				}


				if(palit->tr_lc!=NULL&&palit->tr_rc==NULL)
				{
						if(palit->tr_parent->tr_lc==palit)
						{
								palit->tr_parent->tr_lc=palit->tr_lc;
						}
						if(palit->tr_parent->tr_rc==palit)
						{
								palit->tr_parent->tr_rc=palit->tr_lc;
						}
				}
				if(palit->tr_lc==NULL&&palit->tr_rc!=NULL)
				{
						if(palit->tr_parent->tr_lc==palit)
						{
								palit->tr_parent->tr_lc=palit->tr_rc;
						}
						if(palit->tr_parent->tr_rc==palit)
						{
								palit->tr_parent->tr_rc=palit->tr_rc;
						}
				}


				if(palit->tr_lc!=NULL&&palit->tr_rc!=NULL&&
								palit!=*pTree_head)
				{
						
						if(palit->tr_parent->tr_lc==palit)
						{
								palit->tr_parent->tr_lc=palit->tr_lc;
								paar=palit->tr_lc;
								while(paar->tr_rc!=NULL)
								{
										paar=paar->tr_rc;
								}
								paar->tr_rc=palit->tr_rc;
						}
						if(palit->tr_parent->tr_rc==palit)
						{
								palit->tr_parent->tr_rc=palit->tr_lc;
								paar=palit->tr_lc;
								while(paar->tr_rc!=NULL)
								{
										paar=paar->tr_rc;
								}
								paar->tr_rc=palit->tr_rc;
						}
				}


				if(palit==(*pTree_head))
				{
						*pTree_head=palit->tr_lc;
						paar=palit->tr_lc;
						while(paar->tr_rc!=NULL)
						{
						paar=paar->tr_rc;
						}
						paar->tr_rc=palit->tr_rc;
				}
				
						if(palit!=NULL)
						{
								free(palit);
								palit=NULL;
						}
		}
		else
		{
				printf("没有要删除的数\n");
		}
}
