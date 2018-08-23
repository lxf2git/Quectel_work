#include"apue.h"
#include"microblog.h"
int publish_blog(SUer_basic_info *data,int sockfd)
{
	char buf[1024];
	int option;
	int num;
	write(sockfd,data,sizeof(*data));
	space();
	printf("输入要发表的内容:");
	bzero(buf,sizeof(buf));
	//read(1,buf,sizeof(buf));
	scanf("%[^\n]",buf);
	getchar();
	num = strlen(buf)+1;
	write(sockfd,&num,sizeof(int));
	write(sockfd,buf,num);
	read(sockfd,&option,sizeof(int));
	if(option != 0)
	{
		space();
		printf("发表微博失败,请稍后重试\n");
		return -1;
	}
	space();
	printf("发表成功\n");
	return 0;
}

