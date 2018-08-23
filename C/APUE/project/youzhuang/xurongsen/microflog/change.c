#include"init.h"

int change(PUser_info *puse)
{
	PUser_info plook = phead_use_info;
	plook = plook->next;
	int len;
	while(plook->s_user_basic_info.s_id == 0 
					&& ((len = strlen(plook->s_user_basic_info.s_user_name))!=0))
	{
		if(plook->s_user_basic_info.s_user_name == (*puse)->s_user_basic_info.s_user_name)
		{
			(*puse)->s_user_basic_info = plook->s_user_basic_info;
			(*puse)->s_friend = plook->s_friend;
			(*puse)->s_fanc = plook->s_fanc;
			(*puse)->s_microblog = plook->s_microblog;
			(*puse)->friend_num = plook->friend_num;
			(*puse)->fanc_num = plook->fanc_num;
			return SUC;
		}
	}
	return FAIL;
}
