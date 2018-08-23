#include"function.h"
#define FUNSIZE 50

int function_of_chat(sData_package data,sSocks socket_structure ,pOnlineUser pHeadOnline)
{

    printf("socket_structure.paddr_send.sin_addr:%s\n",inet_ntoa(socket_structure.paddr_send.sin_addr));
    
    
    printf("进入选择功能\n");
    int (*function[FUNSIZE])(sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline) = {NULL};

/*
 *  功能
 * */
    

    function[LOGIN]     = login_account;            //登录
    function[REGISTER]  = register_account;         //注册
    function[ADDFRIEND] = add_friend;               //添加好友

    function[FRIENDRE]  = add_friend_reply;         //好友回复
    function[LEAVE]     = logout;                   // 注销登录 

    function[TELL_REQUES]      = retransmission; 
    function[FILE_REQUES]      = retransmission; 
    function[REQUES_EXIT]      = retransmission;
    function[HEAD]             = retransmission;

    //function[DELFRIEND] = del_friend;
    

    
    printf("data.mode:%d\n", data.mode);

    if (NULL != function[data.mode] )
    {
        function[data.mode](data, socket_structure, pHeadOnline);
        printf(" 功能完成\n\n\n"); 
    }else
    {
        printf("  function err\n");
    }
}



