#include"search.h"
int search(pStu pHead, int (*pFun_Search[2])(pStu pHead,int num))
{
    int i;
    int num;
    printf("How do you want to search: \n");
    printf("0 by ID\n");
    printf("1 by Age\n");
    scanf("%d",&i);
    if(i != 0 && i != 1)
    {
        printf("Input error\n");
        return FAILE;
    }
    printf("Input The Value\n");
    scanf("%d",&num);
    pFun_Search[i](pHead,num);
    /*here !*/
    return SUCCESSED;
}
int search_by_id_print(pStu pHead,int num)
{
    pStu pTemp;
    pTemp = pHead->next;
    if(NULL == pTemp)
    {
        printf("there is no data\n");
        return FAILE;
    }
    while(pTemp != NULL)
    {
        if(pTemp->num == num)
        {
            show_node(pTemp);
            return SUCCESSED;
        }
        pTemp = pTemp->next;
    }
}

int search_by_age_print(pStu pHead,int num)
{
    pStu pTemp;
    pTemp = pHead->next;
    if(NULL == pTemp)
    {
        printf("there is no data\n");
        return FAILE;
    }
    int i = 0;
    while(pTemp != NULL)
    {
        if(pTemp->age == num)
        {
            show_node(pTemp);
            i++;
        }
        pTemp = pTemp->next;
    }
    if(0 == i)
    {
        printf("Not Found\n");
        return FAILE;
    }else
    {
        return SUCCESSED;
    }

}
