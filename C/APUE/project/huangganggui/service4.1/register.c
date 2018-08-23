#include "function.h"

int register_account( sData_package data, sSocks socket_structure,pOnlineUser pOnlineHead)
{
    char userId[USERIDSIZE] = {0};
    strcpy(userId,data.dorinform.loginInformation.userId);
    printf("准备注册：%s\n",userId);

    if (NULL == search_user_by_id(pOnlineHead, userId))  //  id没有被注册
    {
        pOnlineUser pNew = NULL;
        create_memory((void **)&pNew, sizeof(sOnlineUser));
        init_online_node(pNew);

        strcpy(pNew->userId, userId);
        strcpy(pNew->passwd, data.dorinform.loginInformation.passwd);
        bzero(pNew->userIp, USERIPSIZE);

        pNew->vip = NOTVIP;
        pNew->balance = 0;
        pNew->state = OFFLINE;

        insert_user_to_chain(pOnlineHead, pNew);

        data.mode = REGISTERSUCCEED;
        strcpy(data.dorinform.data,"register successfully!\n") ;    /*  注册成功  */
        printf("%s register successfully\n", userId);
        
        show_all_user(pOnlineHead);

        create_file_systerm(pNew);



    }else           //  id已经被注册
    {
        data.mode = REGISTERERROR;
        strcpy(data.dorinform.data,"user has exist!\n") ;    /*  注册成功  */
        printf("%s register faild,it has been registed\n", userId);
    }
    send_info_to_client(data,socket_structure);



    printf("        注册信息已经发送\n");
    return 0;
}

void create_file_systerm(pOnlineUser pNode)
{
    /*
     *  为此用户创建文件夹 文件夹内有 
     *
     *  1.好友列表文件
     *  2.聊天记录文件
     *  3.离线消息文件
     *
     * */
    mkdir(pNode->userId,0777);
    chdir(pNode->userId);

    system("touch friendList");
    system("touch chatRecord");
    system("touch leaveRecord");

    chdir("../");
}

pOnlineUser search_user_by_id(pOnlineUser pHead, char *userId)
{
    pOnlineUser pTemp = NULL;

    for(pTemp = pHead->next; pTemp != pHead ;pTemp = pTemp->next)
    {
        
        printf("comparing %s,%s",pTemp->userId, userId);
        if (0 == strcmp(pTemp->userId, userId))
        {   
            printf("相同\n");
            return pTemp;   //找到用户
        }
        printf("不相同\n");
    }

    return NULL;
}



void send_info_to_client(sData_package data, sSocks socket_structure)
{
    
    int ret;
    printf("        正在回发信息\n");
    printf("        端口号:%d\n",ntohs(socket_structure.paddr_send.sin_port));
    printf("        IP");

    puts(inet_ntoa(socket_structure.paddr_send.sin_addr));

    ret = sendto(socket_structure.sockfd_send, 
            &data, 
            sizeof(data),
            0,
            (struct sockaddr *)&socket_structure.paddr_send,
            sizeof(struct sockaddr_in));

    if (ret < 0)
    {
        perror("sendto");
        exit(-1);
    }

    printf("        信息发送成功\n");
}

void init_online_node(pOnlineUser pNode)
{

    if (NULL == pNode)
    {
        printf("%s err\n", __FUNCTION__);
        exit(-1);
    }
    pNode->prev = pNode;
    pNode->next = pNode;
}

void create_memory(void **p, int size)
{
    *p = malloc(size);
    if (NULL == *p)
    {
        printf("malloc error\n");
        exit(-1);
    }
    return;
}

void free_memory(void **p)
{
    if (NULL != *p)
    {
        free(*p);
        *p = NULL;
    }
    return ;
}

void insert_user_to_chain(pOnlineUser pHead, pOnlineUser pNew)
{
    
    printf("inserting\n");
    pNew->prev = pHead->prev;
    pHead->prev->next = pNew;

    pNew->next = pHead;
    pHead->prev = pNew;
    

}


