#include"./function.h"

int login_account(sData_package data, sSocks socket_structure, pOnlineUser pOnlineHead)
{
    pOnlineUser pTemp = NULL ;
    char *userId = data.dorinform.loginInformation.userId;
    char *userIp = data.sourceAddr;
    char *passwd = data.dorinform.loginInformation.passwd;

    printf("searching %s\n", userId);
    pTemp = search_user_by_id(pOnlineHead,userId);

    if (NULL != pTemp) //用户存在
    {   
        /*  检测密码  */
        if (0 == strcmp(passwd, pTemp->passwd))// 密码正确
        {
            /*  检测是否在线  */
            if(OFFLINE == pTemp->state) //没有在线
            {
                data.mode = LOGINSUCCEED;
                strcpy(data.dorinform.data,"login successfully!\n") ;    /*  登录成功  */
                send_info_to_client(data, socket_structure);
                puts("login successful");
                pTemp->state = ONLINE;
                strcpy(pTemp->userIp, userIp);

                send_friendList( data, socket_structure, pOnlineHead);
                send_leaveRecord( data, socket_structure, pOnlineHead);

            }else
            {
                data.mode = LOGINERROR;                             //登录失败 
                strcpy(data.dorinform.data,"you have logined at other place!\n") ;   //密码错误
                send_info_to_client(data, socket_structure);
                puts("has logined");
            }

        }else                   //密码错误
        {
            data.mode = LOGINERROR;                             //登录失败 
            strcpy(data.dorinform.data,"Password error!\n") ;   //密码错误
            send_info_to_client(data, socket_structure);
            puts("passwd error");
        }

    }else //没有找到此用户
    {
        data.mode = LOGINERROR;                             //登录失败 
        strcpy(data.dorinform.data,"User not exist\n") ;   //密码错误
        send_info_to_client(data, socket_structure);
        puts("user not exist");
    }


    return 0;
}
void send_friendList(sData_package data, sSocks socket_structure, pOnlineUser pOnlineHead)
{
    int ret;
    
    int friendfd;
    char idtemp[USERIDSIZE];


    ret = chdir(data.src_user);
    if (ret < 0)
    {
        printf("chidr err :%s", data.src_user);
        perror("chdir");
        exit(-1);
    }

    friendfd = open("friendList",O_RDONLY);
    if (friendfd < 0)
    {
        printf("open friendList error\n");
        perror("open");
        exit(-1);
    }
    printf("sending frined list.\n");
    while(1)
    {
        ret = read(friendfd, data.dest_user, USERIDSIZE);

        if(ret < 0)
        {
            perror("read");
            close(friendfd);
            exit(-1);
        }

        if (0 == ret)
        {
            printf("Friend list sent finish\n");
            break;
        }

        data.mode = FRIENDLIST;

        send_info_to_client(data,socket_structure);

    }

    close(friendfd);

    chdir("../");
}

void send_leaveRecord(sData_package data, sSocks socket_structure, pOnlineUser pOnlineHead)
{
    int recordfd, ret;
    sData_package dataTemp;
    bzero(&dataTemp,sizeof(sData_package));

    ret = chdir(data.src_user);
    if (ret < 0)
    {
        printf("chidr err :%s", data.src_user);
        perror("chdir");
        exit(-1);
    }

    recordfd = open("leaveRecord",O_RDONLY);
    if (recordfd < 0)
    {
        printf("open leaveRecord error\n");
        perror("open");
        exit(-1);
    }
    printf("sending leaving message.\n");
    while(1)
    {
        ret = read(recordfd, &dataTemp, sizeof(sData_package));

        if(ret < 0)
        {
            perror("read");
            close(recordfd);
            exit(-1);
        }

        if (0 == ret)
        {
            printf("Friend list sent finish\n");
            break;
        }

        send_info_to_client(dataTemp,socket_structure);



    }

    close(recordfd);

    recordfd = open("leaveRecord", O_RDWR|O_TRUNC);
    if (recordfd < 0)
    {
        perror("trunc leaveRecord");
        return;
    }

    close(recordfd);

    chdir("../");

}

