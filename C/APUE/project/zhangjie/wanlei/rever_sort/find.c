#include"find.h"

void find(pMod phash)
{
	printf("please input you want to search the word\n");
	char word[L];
	scanf("%s",word);
	pWord phead=NULL;
	if(word[0]>='A'&&word[0]<='Z')
	{
		phead=phash->mod[strlen(word)]->and_[word[0]-'A'];
	}
	else if(word[0]>='a'&&word[0]<='z')
	{
		phead=phash->mod[strlen(word)]->and_[word[0]-'a'];
	}
	else
	{
		printf("input error\n");
	}
	print(phead,word);
}

void print(pWord phead,char *p)
{
	pWord p1=NULL;
	pLabel p2=NULL;
	int i=0;
	for(p1=phead->next;p1!=NULL;p1=p1->next)
	{
		if(strcmp(p1->word,p)==0)
		{
			for(p2=p1->label->next;p2!=p1->label;p2=p2->next)
			{
				printf("file:%d num:%d ",p2->file_no,p2->num);
				i++;
			}
		}
	}
	if(i==0)
	{
		printf("not found\n");
	}
	else
	{
		printf("\n");
	}
}
