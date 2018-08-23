#include"apue.h"

void init_pFans(pFans *pnew)/*粉丝开空间*/
{
		*pnew = malloc(sizeof(sFans));
		bzero((*pnew)->fans_id,sizeof((*pnew)->fans_id));
		bzero((*pnew)->fans_name,sizeof((*pnew)->fans_name));
		(*pnew)->next = (*pnew);
		(*pnew)->prev = (*pnew);
}
void init_pAtt(pAttenrion *pnew)/*关注开空间*/
{
		*pnew = malloc(sizeof(sAttenrion));
		bzero((*pnew)->attenrion_id,sizeof((*pnew)->attenrion_id));
		bzero((*pnew)->attenrion_name,sizeof((*pnew)->attenrion_name));
		(*pnew)->next = (*pnew);
		(*pnew)->prev = (*pnew);

}
void init_pComment(pComment *pnew)/*评论开空间*/
{ 
	*pnew = malloc(sizeof(sComment));
	bzero((*pnew)->comment_content,sizeof((*pnew)->comment_content));					/*评论人的id*/
	bzero((*pnew)->content_name,sizeof((*pnew)->content_name));
	bzero((*pnew)->content_id,sizeof((*pnew)->content_id));			/*评论人名字*/
	(*pnew)->next = (*pnew);
	(*pnew)->prev = (*pnew);
}


void init_pPublish(pPublish *pnew) /*发微博*/
{
		*pnew = malloc(sizeof(sPublish));
		(*pnew)->number = 0;
		(*pnew)->praise = 0;
		bzero((*pnew)->content,sizeof((*pnew)->content));
		
		init_pComment(&(*pnew)->comment_Head);
		(*pnew)->next = (*pnew);
		(*pnew)->prev = (*pnew);
}

void init_pUser(pUser *pnew)/*用户开空间*/
{
		*pnew = malloc(sizeof(sUser));
		if(NULL == *pnew)
		{
				printf("malloc sUser");
				exit(-1);
		}
		bzero((*pnew)->id,sizeof((*pnew)->id));
		bzero((*pnew)->password,sizeof((*pnew)->password));
		bzero((*pnew)->name,sizeof((*pnew)->name));
//		printf("^^^\n");
		init_pFans(&(*pnew)->fans_Head);
//		printf("^^^\n");
		init_pAtt(&(*pnew)->attenrion_Head);
//		printf("^^^\n");
		init_pPublish(&(*pnew)->publish_Head);
//		printf("^^^\n");
		(*pnew)->next = (*pnew);
		(*pnew)->prev = (*pnew);
}
