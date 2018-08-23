#include"print_chain.h"

void print_chain(pStu pHead)
{
    if(NULL == pHead->next)
    {
        printf("NO data\n");
        return ;
    }
    pStu pTemp = pHead->next;
    while(pTemp != NULL)
    {
        show_node(pTemp);
        pTemp = pTemp->next;
    }
}

void show_node(pStu pNode)
{
    printf("\n____________________\n");
    printf("|         |         |\n");
    printf("|ID:%4d  |Age:%4d |\n",pNode->num,pNode->age);
    printf("|_________|_________|\n");
}


