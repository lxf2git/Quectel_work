#include"function.h"
#define FUNSIZE 21

int function_of_chat(sData_package data,sSocks socket_structure ,pOnlineUser pHeadOnline)
{

    printf("socket_structure.paddr_send.sin_addr:%s\n",inet_ntoa(socket_structure.paddr_send.sin_addr));
    
    
    printf("进入选择功能\n");
    int (*function[FUNSIZE])(sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline);

/*
 *  功能
 * */
    function[LOGIN]     = login_account;            //登录
    function[REGISTER]  = register_account;         //注册
    function[ADDFRIEND] = add_friend;               //添加好友

    function[FRIENDRE]  = add_friend_reply;         //好友回复
    function[LEAVE]     = logout;                   // 注销登录 

    function[TELL_REQUES]      = retransmission; 
    //function[DELFRIEND] = del_friend;
    

    printf("data.mode:%d\n", data.mode);
    function[data.mode](data, socket_structure, pHeadOnline);
    printf(" 功能完成\n\n\n"); 
}


/*  文件系统

工作目录 .info

		onlineuser

		userinfo

		以用户名的文件夹
			friendList
			leaveRecord
			chatRecord


*/
