#include"apue.h"
/*关注列表*/
int look_atten(struct message sMe,pUser pHead)
{
		char buf[1024]={"\0"};
		int n=0;
		pUser ptmp = pHead->next;
		while(strcmp(ptmp->id,sMe.userid)!=0)
		{
				ptmp=ptmp->next;
		}
		pAttenrion pAtten = ptmp->attenrion_Head;
		while(pAtten->next!=ptmp->attenrion_Head)
		{
			strcat(buf,pAtten->next->attenrion_id);
			strcat(buf,"  ");
			strcat(buf,pAtten->next->attenrion_name);
			strcat(buf,"  ");
			n++;
			if(n==4)
			{
				n=0;
				strcat(buf,"\n");
			}
			pAtten = pAtten->next;
		}
		write(sMe.sockfd,buf,strlen(buf)+1);

	
	return 0;
}
