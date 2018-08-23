#include"main.h"

int main()
{
		pMem memory_phead = NULL;
		pMem free_phead = NULL;
		pRec rec_phead = NULL;
		create_rec_node(&rec_phead);
		create_mem_node(&memory_phead);
		create_mem_node(&free_phead);
		create_mem_chain(memory_phead);
		menu(memory_phead, free_phead, rec_phead);
		unload_mem_chain(&memory_phead);
		unload_mem_chain(&free_phead);
		unload_rec_chain(&rec_phead);
		return 0;
}

void menu(pMem memory_phead, pMem free_phead, pRec rec_phead)
{
		int function;
		while(1)
		{
				printf("1、apply   ");
				printf("2、free   ");
				printf("3、print   ");
				printf("4、exit\n");
				scanf("%d", &function);
				switch(function)
				{
						case APPLY:
								apply(memory_phead, free_phead, rec_phead);
								break;
						case FREE:
								free_(memory_phead, free_phead, rec_phead);
								break;
						case PRINT:
								print_(memory_phead, free_phead);
								break;
						case EXIT:
								return;
								break;
						default:
								break;
				}
		}
}

void print_(pMem memory_phead, pMem free_phead)
{
		printf("memory:\n");
		output_mem_chain(memory_phead);
		printf("free:\n");
		output_mem_chain(free_phead);
}

void apply(pMem memory_phead, pMem free_phead, pRec rec_phead)
{
		pRec newrec=NULL;
		pMem max=find_max(memory_phead);
		pMem pnew=NULL, equal=NULL;
		int mem, i=0;   //memory  申请的内存空间
		printf("please input memory:\n");
		scanf("%d", &mem);
		if(mem>memory_phead->mem_size)
		{
				printf("beyond scope!\n");
				return;
		}
		create_rec_node(&newrec);
		create_memory((void **)&newrec->pdata, 10*sizeof(sRec));
		while(mem>0)
		{
				equal=find_equal(memory_phead, mem);
				if(equal!=NULL)
				{
						exchange(free_phead, equal, find_size_insert);
						memory_phead->mem_size-=mem;
						newrec->pdata[i]=equal;
						insert_rec_chain(rec_phead, newrec);
						mem=0;
						break;
				}
				if(mem<max->mem_size)
				{
						create_mem_node(&pnew);
						pnew->index = max->index;
						pnew->mem_size = mem;
						max->mem_size -= mem;
						insert_mem_chain(free_phead, find_size_insert, pnew);
						memory_phead->mem_size -= mem;
						newrec->pdata[i] = pnew;
						insert_rec_chain(rec_phead, newrec);
						mem = 0;
						break;
				}
				else
				{
						exchange(free_phead, max, find_size_insert);
						mem -= max->mem_size;
						memory_phead->mem_size -= max->mem_size;
						newrec->pdata[i] = max;
						insert_rec_chain(rec_phead, newrec);
						max = find_max(memory_phead);
				}
				i++;
		}
		 
}

void exchange(pMem dest, pMem node,pMem (*pfun)(pMem phead, pMem pnew))
{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		insert_mem_chain(dest, pfun, node);
}

pMem find_equal(pMem phead, int mem)
{
		pMem equal = NULL;
		pMem p = phead->next;
		while(p!=phead)
		{
				if(p->mem_size==mem)
				{
						equal=p;
				}
				p=p->next;
		}
		return equal;
}

pMem find_max(pMem phead)
{
		pMem max = phead->next;
		pMem p = phead->next;
		while(p!=phead)
		{
				if(p->mem_size>max->mem_size)
				{
						max = p;
				}
				p=p->next;
		}
		return max;
}

void free_(pMem memory_phead, pMem free_phead, pRec rec_phead)
{
		int num, i=0;
		pMem pmem=NULL;
		pRec p=rec_phead;
		printf("please input number:\n");
		scanf("%d", &num);
		while(num>0)
		{
				p=p->next;
				num--;
		}
		if(p->pdata[0]==NULL)
		{
				printf("free error!\n");
		}
		while(p->pdata[i]!=NULL)
		{
				pmem=find_mem_index(memory_phead, p->pdata[i]->index);
				if(pmem==NULL)
				{
						exchange(memory_phead, p->pdata[i], find_index_insert);
				}
				else
				{
						pmem->mem_size += p->pdata[i]->mem_size;
						delete_mem_node(p->pdata[i]);
				}
				i++;
		}
		p->pdata[0]=NULL;
}

pMem find_mem_index(pMem memory_phead, int num)
{
		pMem p = memory_phead->next;
		while(p!=memory_phead)
		{
				if(p->index==num)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}

pRec find_free_node(pRec rec_phead, int num)
{
		pRec p = rec_phead;
		while(num>0)
		{
				p=p->next;
				num--;
		}
		return p;
}
