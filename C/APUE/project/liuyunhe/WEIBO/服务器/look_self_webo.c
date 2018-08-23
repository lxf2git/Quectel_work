#include"apue.h"
/*查看某人围博*/
int look_self_webo(struct message sMe,pUser pHead)
{
	char ch;
	int n=1;
	char a[1024]={"\0"};
	char buf[2048]={"\0"};
	char dest[1024]={"\n"};
	read(sMe.sockfd,dest,sizeof(dest)); //传来name或id
	
	pUser ptmp = pHead->next;
	while(strcmp(ptmp->id,dest)!=0)
	{
		ptmp = ptmp->next;
		if(ptmp == pHead)
		{
			break;
		}
	}
	if(ptmp == pHead)
	{
			ptmp = ptmp->next;
			while(strcmp(ptmp->name,dest)!=0)
			{
					ptmp = ptmp->next;
			}
	}
	pPublish pPub = ptmp->publish_Head;
	while(ch!='0')
	{
		strcat(buf,"The   ");
		strcat(buf,pPub->next->content);
		strcat(buf,"\n");
		write(sMe.sockfd,buf,sizeof(buf));  //第一条微博
		read(sMe.sockfd,&ch,sizeof(&ch));  //选择信息（1,2,0）
		if(ch == '1')
		{
			comment(sMe,pPub->comment_Head);//评论
			break;
		}
		n++;
		if(pPub->next == ptmp->publish_Head)
		{
			strcat(a,"no have webo. \n");
			write(sMe.sockfd,a,sizeof(a));//微博到头了
			break;
		}
	}

	return 0;
}
