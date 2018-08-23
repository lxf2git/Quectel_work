#include "../apue.h"
#include "init.h"
#include "../microblog.h"


void *Search(int confd)
{
	int ret,num;
	int i=0;
	char *user_name[20];
	PUser_basic_info data;
	data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
	PUser_info s_data;
	PMicroblog s_node;
        init_microblog(&s_node);

	/*s_data = (PUser_info)malloc(sizeof(SUser_info));
	s_data->microblog = (PMicroblog)malloc(sizeof(SMicroblog)); 
	s_data->s_user_basic_info = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
	s_data->s_microblog->s_comment = (PComment)malloc(sizeof(SComment));
	bzero(&data,sizeof(SUer_basic_info));*/
	ret = read(confd,data->s_nick_name,strlen(data->s_nick_name));
	if(ret<0)
	{
		perror("search_read");
		exit(-1);
	}
		s_data = find_nick(data->s_nick_name);//获取用户名
		//s_node = s_data->next;
		write(confd,&s_data->friend_num,sizeof(int ));//发送好友个数
		write(confd,&s_data->fanc_num,sizeof(int ));//发送粉丝个数
		s_node = s_data->s_microblog->next;
		while(s_node!=s_data->s_microblog)
		{
			write(confd,s_node->s_text,1024*10);//发送微博内容
			write(confd,&s_node->s_praise,sizeof(int ));//发送赞
			s_node = s_node->next;
		
		}
		ret = 0;
		write(confd,&ret,sizeof(int ));//微博发送完毕
		read(confd,&num,sizeof(int ));
		if(num<0)
		{
			return;
		}
		s_node = s_data->s_microblog->next;

		for(i=0;i<num;i++)
		{
			s_node = s_node->next;
		}
		Comment_micorblog(confd,s_node->s_comment);//发表评论
		
	//write(confd,&ret,sizeof(int ));//发完通知
	

	//Attention(confd,s_data->s_fanc);

	//查看是否已关注


	/*ret = read(confd,data->s_user_name,sizeof(SUer_basic_info->s_user_name));
	if(ret<0)
	{
		perror("search_read");
		exit(-1);
	}
	//是否加关注

	if(num==1)
	{
		Add_fanc(PUser_info puihead,data->s_user_name);//加关注
	}
	else
	{
		del_fanc(PUser_info puihead,data->s_user_name);//取消关注
	}

	//Send_information(s_data);*/
	close(confd);
EXIT :
	close(confd);
	return SUC;

}
