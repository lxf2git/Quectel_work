#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Publish_microblog(int confd)
{
		printf("发表微博\n");
		int ret,len;
		PUser_basic_info data;
		PUser_info s_node;
		PMicroblog s_microblog;
		data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));

		init_microblog(&s_microblog);

		ret = read(confd,data,sizeof(SUer_basic_info));
		s_node = find_user_name(data->s_user_name);
		read(confd, &len, sizeof(int));
		ret = read(confd,s_microblog->s_text,len);
		printf("microblog:%s\n",s_microblog->s_text);
		printf("zan:%d\n",s_microblog->s_praise);
		if(ret<0)
		{
				perror("publish read");
		}	
		ret = add_back_blog(s_node->s_microblog,s_microblog);


		if(ret = SUC)
		{
				write(confd,&ret,sizeof(int ));
		}
		else
		{
				write(confd,&ret,sizeof(int ));
		}
		close(confd);
}
