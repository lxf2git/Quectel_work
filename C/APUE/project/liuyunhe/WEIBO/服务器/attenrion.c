#include"apue.h"
/*关注*/
int attenrion(struct message sMe,pUser pHead)
{
	char dest[1024];
	char a[1024];
	bzero(dest,sizeof(dest));
	read(sMe.sockfd,dest,sizeof(dest));  //要关注的id
	pUser ptmp_user,ptmp_dest;

	ptmp_user = pHead->next;
	while(strcmp(ptmp_user->id,sMe.userid)!=0)
	{
			if(ptmp_user == pHead)
			{
					bzero(a,sizeof(a));
					strcpy(a,"数据不存在");
					write(sMe.sockfd,a,strlen(a)+1);
					return 0;
			}
			ptmp_user = ptmp_user->next;
	}
	ptmp_dest = pHead->next;
	while(strcmp(ptmp_dest->id,dest)!=0)
	{
			if(ptmp_dest == pHead)
			{
					bzero(a,sizeof(a));
					strcpy(a,"数据不存在");
					write(sMe.sockfd,a,strlen(a)+1);
					return 0;
			}
		ptmp_dest = ptmp_dest->next;
	}
	pAttenrion patten_new;
	pFans pfans_new;
	init_pAtt(&patten_new);
	init_pFans(&pfans_new);

	strcat(patten_new->attenrion_id,ptmp_dest->id);
	strcat(patten_new->attenrion_name,ptmp_dest->name);

	strcat(pfans_new->fans_id,ptmp_user->id);
	strcat(pfans_new->fans_name,ptmp_user->name);

	ptmp_user->attenrion_Head->next->prev = patten_new;  //atten  head  chat
	patten_new->next = ptmp_user->attenrion_Head->next;
	ptmp_user->attenrion_Head->next = patten_new;
	patten_new->prev = ptmp_user->attenrion_Head;

	ptmp_dest->fans_Head->next->prev = pfans_new;  //fans  head chat
	pfans_new->next = ptmp_dest->fans_Head->next;
	pfans_new->prev = ptmp_dest->fans_Head;
	ptmp_dest->fans_Head->next = pfans_new;
	
	write_attenrion(sMe.userid,ptmp_user->attenrion_Head);/*刷新关注文件*/
	write_fans(dest,ptmp_dest->fans_Head);/*刷新粉丝文件*/

	bzero(a,sizeof(a));
	strcpy(a,"关注成功\n");
	write(sMe.sockfd,a,strlen(a)+1);
		
	return 0;
}
