#include<stdlib.h>
#include<stdio.h>
#define N 4

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}sNode,*pNode;

void init_node(pNode *p);
void create_memory(void **p,int size);
void create_chain(pNode pHead);
void insert_node_behind(pNode pSrc, pNode pNew);
void cmp_del_node(pNode pHeadA,pNode pHeadB);
void cut_node(pNode *p);
void free_node(pNode *p);
void show_node(pNode pHead);
void distroy_chain(pNode *pHead);
int main()
{
    pNode pHeadA = NULL, pHeadB = NULL;

    init_node(&pHeadA);
    init_node(&pHeadB);
    
    create_chain(pHeadA);
    create_chain(pHeadB);
    show_node(pHeadA);
    show_node(pHeadB);


    cmp_del_node(pHeadA,pHeadB);

    show_node(pHeadA);
    show_node(pHeadB);

//    distroy_chain(&pHeadA);
 //   distroy_chain(&pHeadB);
    return 0;
}

void init_node(pNode *p)
{
    create_memory((void **)p,sizeof(sNode));
    (*p)->next = *p;
    (*p)->prev = *p;
}

void create_memory(void **p,int size)
{
    *p = malloc(size);
    if(NULL == *p)
    {
        printf("Malloc error\n");
        exit(-1);
    }
}

void create_chain(pNode pHead)
{
    int i;
    pNode pNew = NULL;
    printf("Input %d number(s)\n",N);
    for(i = 0; i < N; i++)
    {
        init_node(&pNew);

        scanf("%d",&pNew->data);
        insert_node_behind(pHead->prev, pNew);

    }
}

void insert_node_behind(pNode pSrc, pNode pNew)
{
    pNew->next = pSrc->next;
    pSrc->next->prev = pNew;

    pSrc->next = pNew;
    pNew->prev = pSrc;
}

void cmp_del_node(pNode pHeadA,pNode pHeadB)
{
    pNode pTempA=NULL, pTempB = NULL;
    int flg,record;
    if(pHeadA == pHeadA->next || pHeadB == pHeadB->next)
    {
        printf("compare Error,No Data\n");
        exit(-1);
    }
    for(pTempA = pHeadA; pTempA->next != pHeadA; pTempA = pTempA->next)
    {
        flg = 0;
        for(pTempB = pHeadB; pTempB->next != pHeadB; pTempB = pTempB->next)
        {
            if(pTempA->next->data == pTempB->next->data)
            {
                
                printf("here\n");       
                printf("pTemp:%p\n",pTempB);
                cut_node(&pTempB->next);
           //     cut_node(pTempB);   
                pTempB = pTempB->prev;
                flg = 1;
                exit(-1);
            }
        }
        if(1 == flg)
        {
 //           cut_node(&pTempA->next);
    
            flg = 0;

        }
    }
}

void cut_node(pNode *p)
{
    printf("(*p)->prev%p\n",(*p)->prev);

    (*p)->prev->next = (*p)->next;
    (*p)->next->prev = (*p)->prev;

    (*p)->next = *p;
    (*p)->prev = *p;
#if 0
    pNode pTemp = (*p)->prev;
    pTemp->next = (*p)->next;
    (*p)->next->prev = pTemp;

    (*p)->next = *p;
    (*p)->prev = *p;
#endif

//    free_node(p);
}
/*
void cut_node(pNode p)
{
    pNode pdel = p->next;

    p->next = pdel->next;
    pdel->next->prev = p;
    pdel->next = pdel;
    pdel->prev = pdel;
    free_node(&pdel);
}
*/
void free_node(pNode *p)
{
    if((*p != NULL))
    {
        free(*p);
        *p = NULL;
    }
}

void show_node(pNode pHead)
{
    if(pHead->next == pHead)
    {
        printf("No data\n");
        return ;
    }
    pNode pTemp = NULL;
    printf("The data is:");
    for(pTemp = pHead->next; pTemp != pHead; pTemp = pTemp->next)
    {
        printf("%d ",pTemp->data);
    }
    printf("\n");
}
/*
void distroy_chain(pNode *pHead)
{
    if((*pHead)->next == *pHead)
    {
        cut_node(pHead);
        return;
    }
    while((*pHead)->next != *pHead)
    {
        cut_node(&(*pHead)->next);
    }
//    cut_node(pHead);
}*/
