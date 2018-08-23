#include"del.h"
int Delete(pStu phead,pStu (*pDelPosition)(pStu pNode,int age))
{
		int n,i;
		char ch;
		pStu ptmp=phead;
		i = ZERO;
		printf("pleaae input think delete age \n");
		scanf("%d",&n);
		while(getchar()!='\n');
		while(ptmp->next != phead)
		{    
				pStu pDel = (*pDelPosition)(phead,n);
                if(pDel  == NULL)
				{
					if(i != ZERO)
					{
						printf("not again find people\n");
					}
					else
					{
						printf("not find people\n");
						
					}
					return;
				}
				while(1)
				{
						if(pDel->next != phead)
						{


								printf("Do you sure delete y/n?\n");
								scanf("%c",&ch);
								while(getchar()!='\n');
								if(ch == 'y')
								{
										i++;
										ptmp = pDel->next;
										delete_list(pDel);
										break;
								}
								else 
								{		
										if(ch == 'n')

										{
												ptmp = ptmp->next;
												break;
										}
										else 
										{
												printf("sure error please again\n");
										}
								}

						}
						else
						{
								printf("not find people\n");	
								return;
						}
				}
		}
		if(i != ZERO)
		{
			printf("not again find people\n");
		}
		else 
		{
			printf("not find people \n");
		
		}
}
pStu DelPosition(pStu pNode,int age)
{
		pStu pdel=pNode;
		while(pdel->next != pNode)
		{
				if(pdel->next->age == age)
				{
						printf("id:%d age:%d \n",pdel->next->num,pdel->next->age);
						return pdel;
				}
				pdel = pdel->next;
		}
		return NULL;
}
void delete_list(pStu pdel)
{
		pStu ptmp = pdel->next;
		pdel->next = ptmp->next;
		ptmp ->next = NULL;
		my_free(&ptmp);
}
void my_free(pStu *p)
{
		if(*p != NULL)
		{
				free(*p);
				*p = NULL;
		}
}
