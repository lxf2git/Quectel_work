#include"apue.h"
/*发微博*/
int send_webo(struct message sMe,pUser pHead)
{
	char buf[1024];
	read(sMe.sockfd,buf,sizeof(buf));
	pPublish pnew;
	init_pPublish(&pnew);
	strcat(pnew->content,buf);
	pUser ptmp = pHead->next;
	while(strcmp(ptmp->id,sMe.userid)!=0)
	{
		ptmp = ptmp->next;
	}
	pPublish pbmp = ptmp->publish_Head;
	pnew->number = pbmp->next->number + 1;
	pnew->next = pbmp->next;
	pnew->prev = pbmp;
	pbmp->next->prev = pnew;
	pbmp->next = pnew;
	char a[1024]={"ok   \n"};
	write(sMe.sockfd,a,sizeof(a));

	write_publish(sMe.userid,pnew);/*写入文件*/
	
	return 0;
}
