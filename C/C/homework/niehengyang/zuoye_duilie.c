#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
        char data;
        struct tree *lc;
        struct tree *rc;
}sTree,*pTree;

typedef struct queue
{
        pTree arr[50];
        int pw;
        int pr;
}sQueue,*pQueue;

void init_queue(pQueue *q)
{
	(*q)=(pQueue)malloc(sizeof(pTree));
	(*q)->pw=0;
	(*q)->pr=0;
}

void push_queue(pQueue queue,pTree ptmp)
{
	queue->arr[queue->pw]=ptmp;
	queue->pw++;
}

void pop_queue(pQueue queue,pTree *pop_data)
{
	*pop_data=queue->arr[queue->pr];
	queue->pr++;
}
void create_memory(pTree *p)
{
        *p=(pTree)malloc(sizeof(sTree));
        if(*p==NULL)
        {
        printf("create error!\n");
        exit(-1);
        }
        (*p)->lc=NULL;
        (*p)->rc=NULL;
}

 void create_tree(pTree *root)
{
        char ch;
        scanf("%c",&ch);
        getchar();
        if(ch==' ')
        {
                *root=NULL;
        }
        else
        {
                create_memory(root);
                (*root)->data=ch;
                create_tree(&(*root)->lc);
                create_tree(&(*root)->rc);
        }
}

        

void show_tree(pQueue queue,pTree root)
{
        pTree ptmp=root;
        pTree pdata;
        //printf("%c",ptmp->data);
	push_queue(queue,ptmp);
        while(queue->pw!=queue->pr)
        {
                pop_queue(queue,&pdata);
                ptmp=pdata;
                printf("%c ",ptmp->data);
                if(ptmp->lc!=NULL)
                {
                push_queue(queue,ptmp->lc);
                }
                if(ptmp->rc!=NULL)
                {
                push_queue(queue,ptmp->rc);
                }
        }
}

int main()
{
        pTree root;
        pQueue queue;
        init_queue(&queue);
        printf("please intput chain:\n");
        create_tree(&root);
        if(root==NULL)
        {
        printf("null tree!\n");
        exit(-1);
        }
       show_tree(queue,root);
	printf("\n");
}






















