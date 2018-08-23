#include"apue.h"

int comment(struct message sMe,pComment comment_Head)
{
	char buf[1024]={"\0"};
	read(sMe.sockfd,buf,sizeof(buf));  //评论要说的话
	printf("评论：%s\n",buf);
	pComment pnew;
	init_pComment(&pnew);
	strcpy(pnew->content_id,sMe.userid);
	strcpy(pnew->comment_content,buf);

	pnew->next = comment_Head->next;
	comment_Head->next->prev = pnew;
	comment_Head->next = pnew;
	pnew->prev = comment_Head;

	return 0;
}
