#include"main.h"
void read_file(pData pHead)
{
//		printf("%s\n",__FUNCTION__);
	
		FILE *fp;
		int ch;
//		char character;
		fp = fopen("a","r");
		if(fp == NULL)
		{
				perror("a");
				exit(-1);
		}
		while((ch=fgetc(fp)) != EOF)
		{
//				character = ch;
				create_struct(pHead,ch);
//				printf("%d %c\n",ch,ch);
		}
		fclose(fp);
		output_chain(pHead);
	

}
void create_struct(pData pHead,int ch)
{
//		printf("%s\n",__FUNCTION__);
		pData p;
		init_data(&p);
		p->data = ch;
		same_struct(pHead,p);
}
void same_struct(pData pHead,pData pInsert)
{
//		printf("%s\n",__FUNCTION__);
		pData pTemp = pHead->next;
		while(pTemp != pHead)
		{
				if(pTemp->data == pInsert->data)
				{
						pTemp->num+=1;
						free(pInsert);
						delete_chain(pHead,pTemp);
						insert_chain(pHead,pTemp);
						return;

				}
				pTemp = pTemp->next;
		}
		insert_chain(pHead,pInsert);
}
void insert_chain(pData pHead,pData pInsert)
{
//		printf("%s\n",__FUNCTION__);
		pData pTemp = pHead->next;
		while(pTemp != pHead)
		{
				if(pInsert->num < pTemp->num)
						break;
				pTemp = pTemp->next;
		}
		pInsert->next = pTemp;
		pInsert->prev = pTemp->prev;
		pTemp->prev->next = pInsert;
		pTemp->prev = pInsert;

}
void delete_chain(pData pHead,pData pDel)
{
//		printf("%s\n",__FUNCTION__);
		pDel->prev->next = pDel->next;
		pDel->next->prev = pDel->prev;
}
void init_data(pData *p)
{
//		printf("%s\n",__FUNCTION__);
		create_memory(p,sizeof(sData));
		(*p)->parent = NULL;
		(*p)->lc = NULL;
		(*p)->rc = NULL;
		(*p)->num = 1;
		(*p)->next = *p;
		(*p)->prev = *p;
		(*p)->data =-1;
		(*p)->sign = 3;
}
void create_memory(pData *p,int size)
{
//		printf("%s\n",__FUNCTION__);
		*p = malloc(size);
}
void output_chain(pData pHead)
{
		//		printf("%s\n",__FUNCTION__);
		pData pTemp = pHead->next;
		while(pTemp != pHead)
		{
				if(pTemp->data == -1)
						printf(" root   num:%d sign:%d\n",pTemp->num,pTemp->sign);
				else
						if(pTemp->data == 10)
								printf("char:\\n num:%d sign:%d\n",pTemp->num,pTemp->sign);
						else
								printf("char:%c  num:%d sign:%d\n",pTemp->data,pTemp->num,pTemp->sign);
				pTemp = pTemp->next;
		}

}




