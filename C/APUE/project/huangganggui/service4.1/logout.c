#include"function.h"

int logout( sData_package data, sSocks socket_structure,pOnlineUser pOnlineHead)
{
    
    pOnlineUser pTemp = NULL;

    pTemp = search_user_by_id(pOnlineHead, data.src_user);
    if (NULL != pTemp)
    {
        pTemp->state = OFFLINE;
        printf("本次登录IP：%s\n", pTemp->userIp);
        bzero(pTemp->userIp, USERIPSIZE);

    }else
    {
        printf("not found %s \n", data.src_user);
    }
    
    show_all_user(pOnlineHead);

    write_all_user(pOnlineHead, "./userinfo");
}

void write_all_user(const pOnlineUser pHead, const char *pathname)
{
    int fd, ret;
    fd = open(pathname, O_WRONLY|O_TRUNC);
    if (fd < 0)
    {
        perror("open");
        exit(-1);
    }
    
    pOnlineUser pTemp = NULL ;

    for(pTemp = pHead->next; pTemp != pHead; pTemp = pTemp->next)
    {
        write(fd, pTemp, sizeof(sOnlineUser));
        printf("writing %s\n", pTemp->userId);
    }
}

int show_all_user(pOnlineUser pHead)
{
    if (NULL != pHead)
    {
        printf("All user:\n");
        pOnlineUser pTemp = NULL;

        for(pTemp = pHead->next; pTemp != pHead; pTemp = pTemp->next)
        {
            printf("ID:%s  stat:%s  %s\n",
                    pTemp->userId, 
                    (pTemp->state == ONLINE)?"Online  Ip: ":"OffLIne ",
                    pTemp->userIp);

        }
        printf("end\n");


    }
}


void distory_chain(pOnlineUser pHead)
{
    pOnlineUser pTemp = NULL;
    if (NULL != pHead)
    {
        for(pTemp = pHead->next; pTemp != pHead; pTemp= pHead->next)
        {
            pHead->next = pTemp->next;
            pTemp->next->prev = pHead;

            pTemp->next = pTemp;
            pTemp->prev = pTemp;

            free_memory((void **)&pTemp);
        }

    }
}





