#include"rev_sort.h"

int main(int argc,char *argv[])
{
	char pattern[256] = {};
	glob_t globres;
	pMod pmod = NULL;
	int i;
	FILE *fp;
	init_mod(&pmod);
	sprintf(pattern,"%s/*.c",argv[1]);
	glob(pattern,0,0,&globres);
	for(i=0;i<globres.gl_pathc;i++)
	{
		fp = fopen(globres.gl_pathv[i],"r");
		if(fp == NULL)
		{
			printf("fopen error\n");
			exit(-1);
		}
		creat_hash_list(fp,globres.gl_pathv[i],pmod);
		fclose(fp);
		fp = NULL;
	}
	search_word(pmod);
//	print(pmod);
	return 0;
}

void search_word(pMod pmod)
{
	int len,i,j;
	char iword[256]={};
	pWord pHead = NULL;
	printf("want search word:\n");
	scanf("%s",iword);
	len = strlen(iword);
	iword[len] = 0;	//避免干扰
	i = (int)(iword[0]+iword[len-1]-194)%26;
	j = len%10;
	pHead = pmod->mod[i]->_and[j];
	print_data(pHead,iword);	//输出data
}
void print_data(pWord pHead,char *iword)
{
	pWord ptmp = NULL;
	pData pdh = NULL;
	pData pdt = NULL;
	int con = 0;
	for(ptmp = pHead->next;ptmp != pHead;ptmp = ptmp->next)
	{
		if(0 == strcmp(ptmp->chword,iword))
		{
			con = 1;
			pdh = ptmp->data;
			for(pdt = pdh->next;pdt != pdh;pdt = pdt->next)
			{
				printf("%s	Hz:%d\n",pdt->file_name,pdt->num);
			}
		}
	}
	if(con == 0)
	{
		printf("not have word\n");
	}
}

void print(pMod pmod)
{
	int i,j;
	for(i=0;i<26;i++)
	{
		for(j=0;j<10;j++)
		{
			if(pmod->mod[i]->_and[j]->next !=pmod->mod[i]->_and[j])
			{
				print2(pmod->mod[i]->_and[j]);
			}
		}
	}
}
void print2(pWord phead)
{
	pWord ptmp = NULL;
	pData pdh = NULL;
	pData pdt = NULL;
	for(ptmp = phead->next;ptmp!=phead;ptmp = ptmp->next)
	{
		printf("%s\n",ptmp->chword);
		pdh = ptmp->data;
		for(pdt = pdh->next;pdt != pdh;pdt = pdt->next)
		{
			printf("%s	Hz:%d\n",pdt->file_name,pdt->num);
		}
	}
}
