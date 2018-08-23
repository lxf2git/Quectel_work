#include"search.h"

void hash(char *p,int i,pMod phash)
{
	pWord pnew=NULL;
	init_word(&pnew,sizeof(sWord));
	strcpy(pnew->word,p);
	pnew->label->file_no=i+1;
	pnew->label->num=1;
	pWord phead=NULL;
	if(p[0]>='A'&&p[0]<='Z')
	{
		//printf("[%d %d %s]",strlen(p),p[0]-'A',pnew->word);
		phead=phash->mod[strlen(p)%10]->and_[p[0]-'A'];
	}
	else if(p[0]>='a'&&p[0]<='z')
	{
		//printf("[%d %d %s]",strlen(p),p[0]-'a',pnew->word);
		phead=phash->mod[strlen(p)%10]->and_[p[0]-'a'];
	}
	insert(phead,pnew);
}

int insert(pWord phead,pWord pnew)
{
	if(phead==NULL||pnew==NULL)
	{
		printf("insert error\n");
		return FULL;
	}
	pWord p=NULL;
	pLabel p1=NULL;
	for(p=phead->next;p!=NULL;p=p->next)
	{
		if(strcmp(pnew->word,p->word)==0)
		{
			for(p1=p->label->next;p1!=p->label;p1=p1->next)
			{
				if(p1->file_no==pnew->label->file_no)
				{
					p1->num++;
					return SUC;
				}
			}
			pnew->label->next=p->label->next;
			p->label->next=pnew->label;
			return SUC;
		}
	}
	pnew->next=phead->next;
	phead->next=pnew;
	return SUC;
}
