#include"print.h"
void print(pStu pHead)
{
        pStu p=pHead->next;
        while(p!=NULL)
        {   
               p->stu_print(p);
               p=p->next;
		}   
}
