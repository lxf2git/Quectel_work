#include"delete.h"

int delete(pStu pHead, pStu (*pDelPosition)(pStu pNode,int age))
{
    int age;
    printf("which age do you want to delete:\n");
    scanf("%d",&age);
    pStu pDelNode;
    int i = 0;
    while(1)
    {
        
        pDelNode = (*pDelPosition)(pHead, age);
        if(NULL == pDelNode )
        {
            if(i != 0)
            {
                printf("%d datas has been delate.\n",i);
                return SUCCESSED;
                
            }else
            {
                printf("Not Found\n");
                return FAILE;
            }
        }


        delete_node(pHead,&pDelNode);
        i++;
        
    }
    return SUCCESSED;
}

pStu find_node_with_age(pStu pHead, int age)
{
    pStu pTemp = NULL;
    pTemp = pHead->next;
    while(pTemp != NULL)
    {
        
        if(age == pTemp->age)
        {
            return pTemp;
        }
        pTemp = pTemp->next;
    }
    return NULL;
}
pStu find_node_with_id(pStu pHead, int id)
{
    pStu pTemp = NULL;
    pTemp = pHead->next;
    while(pTemp != NULL)
    {
        if(id == pTemp->num)
        {
            return pTemp;
        }
        pTemp = pTemp->next;
    }
    return NULL;
}

void delete_node(pStu pHead, pStu *pDelNode)
{
    pStu pTemp;
    pTemp = pHead;
    if((*pDelNode) == pHead )
    {
        free_node(pDelNode);
        return ;
    }
    while(NULL != pTemp->next)
    {
        if (pTemp->next == (*pDelNode))
        {
            pTemp->next =(* pDelNode)->next;
            (*pDelNode)->next = NULL;
            free_node(pDelNode);
            return ;

        }
        pTemp = pTemp->next;
    }
    printf("error:%s",__FUNCTION__);

}
void free_node(pStu *pNode)
{
    if((*pNode) != NULL)
    {
        free(*pNode);
        *pNode = NULL;
    }
}

