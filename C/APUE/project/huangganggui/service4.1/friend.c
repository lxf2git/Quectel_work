#include"./function.h"

int add_friend(sData_package data, sSocks socket_structure,pOnlineUser pOnlineHead)
{
    char *userId = data.dest_user;
    pOnlineUser pTemp = NULL;

    pTemp = search_user_by_id(pOnlineHead,userId);

    if (NULL == pTemp)  //  用户不存在  
    {   
        printf("user not found\n");
        data.mode = SERVICE_REPLY;

        strcpy(data.dorinform.data,"Users not exist.\n");


        send_info_to_client(data, socket_structure);

    }else // 用户存在
    {

        /*  向目标用户发送添加好友请求  */
        printf("sending addfriend request\n")   ; 

        retransmission(data, socket_structure, pOnlineHead);
        printf("sent successful \n");
    }
}

int add_friend_reply(sData_package data, sSocks socket_structure,pOnlineUser pHeadOnline)
{
    int fd;

    printf("replying\n");

    if ('y' == data.dorinform.data[0])
    {
        /*dest*/
        chdir(data.dest_user);
        write_to_friend_list(data.src_user);
        chdir("../");

        /*src*/
        chdir(data.src_user);
        write_to_friend_list(data.dest_user);
        chdir("../");


        /*send to 发起者*/
        sData_package dest = data;
        strcpy(dest.dest_user , data.src_user);
        strcpy(dest.src_user , data.dest_user);
        

        strcpy(dest.sourceAddr, data.destAddr );
        strcpy(dest.destAddr, data.sourceAddr);

        dest.mode = FRIENDLIST;
        
        printf ("\n");
        printf ("send to dest\n");

        printf("IP:%s\n", data.destAddr);

        socket_structure.paddr_send.sin_addr.s_addr = inet_addr(data.destAddr);
        send_info_to_client(dest, socket_structure);

        printf("sent successful\n");

        /*send to 受邀者*/ 
        sData_package src = data;




        src.mode = FRIENDLIST;
        printf("send to src\n");
        printf("IP:%s\n", data.sourceAddr);
        socket_structure.paddr_send.sin_addr.s_addr = inet_addr(data.sourceAddr);
        send_info_to_client(src, socket_structure);
        printf("sent successful\n");

    }


}

int write_to_friend_list(char userId[10])
{
    int fd = open("friendList", O_WRONLY|O_APPEND);
    if (fd < 0)
    {
        perror("open");
        exit(-1);
    }
    write(fd, userId, 10 );
    close(fd);
}

