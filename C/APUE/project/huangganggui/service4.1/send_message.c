#include"function.h"

int retransmission(sData_package bufData,sSocks Sockfd,pOnlineUser pOnlineHead)//转发
{

    int ret ,fd;
    pOnlineUser pTemp = NULL;
    pTemp = search_user_by_id(pOnlineHead, bufData.dest_user);

    if (NULL != pTemp)
    {
        if (ONLINE == pTemp->state)
        {

        printf("用户在线\n");

        strcpy(bufData.destAddr, pTemp->userIp);

        Sockfd.paddr_send.sin_family = AF_INET;
        Sockfd.paddr_send.sin_addr.s_addr = inet_addr(pTemp->userIp);
        Sockfd.paddr_send.sin_port = htons(8888);

            printf("正在向%s发送消息\n", inet_ntoa(Sockfd.paddr_send.sin_addr));
        sendto(Sockfd.sockfd_send,&bufData,sizeof(bufData),0,(struct sockaddr*)&Sockfd.paddr_send,Sockfd.len);
        
        printf("sent successful\n");
        }else
        {
            /*用户不在线， 将消息存到目的用户 离线信息中 
             * 在该用户登录后，将离线信息发给用户
             */
            printf("User Not Online\n");
            
            ret = chdir(pTemp->userId);
            if (ret < 0)
            {
                printf("chdir:%s", pTemp->userId);
                perror("chdir");
                return ;
            }else
            {
                fd = open("leaveRecord", O_WRONLY|O_APPEND);
                if (fd < 0)
                {
                    perror("open leaveRecord");
                    chdir("../");
                    return ;
                }

                write(fd, &bufData,sizeof(sData_package));
                close(fd);

            }

            chdir("../");

            
        }
    }else
    {
        printf("user %s not found\n", bufData.dest_user);
    }
}
