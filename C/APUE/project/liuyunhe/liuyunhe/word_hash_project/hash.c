#include"init.h"

int gand_memoty(pAnd *pf)
{
		*pf=malloc(sizeof(sAnd));
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}
}

int gmod_memoty(pMod *pf)
{
		*pf=malloc(sizeof(sMod));
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}

}

int great_memoty(pCh *pf)
{
		*pf=malloc(sizeof(sCh));
		(*pf)->next=(*pf);
		(*pf)->prev=(*pf);
		if(NULL==(*pf))
		{
				printf("sorry \n");
				exit -1;
		}
}

void mod_and_data(pMod pmod_head)
{
		int i,j;
		for(i=0;i<26;i++)
		{
				pAnd pand_new;
				gand_memoty(&pand_new);
				pmod_head->mod[i]=pand_new;
				for(j=1;j<=10;j++)
				{
						pCh pch_head;
						great_memoty(&pch_head);
						pmod_head->mod[i]->and[j]=pch_head;
				}
		}
}

void hash_word(pMod pmod_head,char *ch,int ww)
{
		int i,j;
//		printf("ch  %s\n",ch);
		pCh palit;
		if(ch[0]<='z'&&ch[0]>='a')
		{
			i=(ch[0]-'a');
		}
		if(ch[0]<='Z'&&ch[0]>='A')
		{
			i=(ch[0]-'A');
		}
		j=strlen(ch);
		if(j>10)
		{
				j=10;
		}
	//	printf("i:%dj:%d",i,j);
		for(palit=pmod_head->mod[i]->and[j]->next;palit!=pmod_head->mod[i]->and[j];palit=palit->next)
		{
				if(strcmp(palit->ch,ch)==0&&palit->word==ww)
				{
						
						
						palit->time+=1;
						return;
						
				}
		}
		pCh pch_new;
		great_memoty(&pch_new);
		strcpy(pch_new->ch,ch);
		pch_new->time=1;
		pch_new->word=ww;
		palit->next->prev=pch_new;
		pch_new->next=palit->next;
		pch_new->prev=palit;
		palit->next=pch_new;
//		printf("palit->next  %s\n",palit->next->ch);
}
