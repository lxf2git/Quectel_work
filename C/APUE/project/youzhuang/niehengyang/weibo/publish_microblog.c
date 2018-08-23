#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Publish_microblog(int confd)
{
	int ret;
	PUser_basic_info data;
	PUser_info s_data,s_node;
	PMicroblog s_microblog;
	init_microblog(&s_microblog);
	data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
	//init_user_info(&s_data);
	//init_microblog(&s_data->s_microblog);
	/*s_data = (PUser_info)malloc(sizeof(SUser_info));
	s_data->microblog = (PMicroblog)malloc(sizeof(SMicroblog));
	s_data->s_user_basic_info = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
	s_data->s_microblog->s_comment = (PComment)malloc(sizeof(SComment));
	bzero(&data,sizeof(SUer_basic_info));
	bzero(&s_data,sizeof(SUser_info));*/
	//s_microblog->s_text = (char *)malloc(sizeof(1024*1024));
	ret = read(confd,data,sizeof(SUer_basic_info));
	s_node = find_user_name(data->s_user_name);
	ret = read(confd,s_microblog->s_text,1024*10);
	if(ret<0)
	{
		perror("publish read");
		exit(-1);
	}	
	ret = add(9,(void **)&s_node,(void **)&s_microblog,add_back_blog);
	
	//s_data = find(data.s_user_name, data.s_passwd,data.&s_id,data.s_nick_name);
	
	 if(ret = SUC)
        {
                write(confd,&ret,sizeof(int ));
        }
        else
        {
                write(confd,&ret,sizeof(int ));
        }
	
	

}
