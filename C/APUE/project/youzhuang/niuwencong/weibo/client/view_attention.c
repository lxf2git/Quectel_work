#include"apue.h"
#include"microblog.h"

void view_attention(SUer_basic_info *data,int sockfd)
{
	char nick_name[20];
	int i = 0;
	char ch[20];
	write(sockfd,data->s_user_name,sizeof(data->s_user_name));
	while(1)
	{
		bzero(nick_name,sizeof(nick_name));
		read(sockfd,nick_name,sizeof(nick_name));
		if(nick_name[0] == 0)
		{
			if(0 == i)
			{
				space();
				printf("** 您尚无关注任何人 **\n");
			}
			break;
			printf("\n\n");
		}
		else
		{
		i++;
		space();
		printf("** No.%d   %s\n",i,nick_name);	
		}
		
	}
	space();
	printf("**  返回主页 **");
	scanf("%[^\n]",ch);
	getchar();
	return;
}
