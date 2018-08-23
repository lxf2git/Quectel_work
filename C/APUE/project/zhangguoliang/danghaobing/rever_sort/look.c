#include"look.h"


void look_same_tip(pSword pshead)
{
	printf("sum:%d\n",pshead->num);
	//遍历每个相同单词
	pSword ptmp = pshead;
	int ftmp = 0;
	while(ptmp->next!=pshead)
	{
		if(ptmp->next->file_no!=ftmp)
		{
				printf("(%d;%d;",ptmp->next->file_no,ptmp->next->num+1);
				ftmp=ptmp->next->file_no;
		}
		printf("<%d>",ptmp->next->where);
		ptmp = ptmp->next;
		if(ftmp!=ptmp->next->file_no)
				printf(") ");
	}
	printf("\n");
}

void look_word(pWord look_last,char *p)
{
		pWord ptmp = look_last;//遍历所有不同单词，查找是否有相同
		while(ptmp->next!=look_last)
		{
			if(strcmp(ptmp->next->wsave,p)==0)
			{
					printf("word found!\n");
					look_same_tip(ptmp->next->same_words);
					return ;
			}
			ptmp = ptmp->next;
		}
		printf("not found this word!\n");
}

void look_second(pSec plook_sec,char *p)
{
	int i;
	for(i=0;i<13;i++)
	{
			if(i==char_deal_again(p[0]))
			{
					look_word(plook_sec->dword[i],p);
					return ;
			}
	}
}

void look(pFirst pfirst)
{
		printf("please input word.\n");
		char lname[20];
		scanf("%s",lname);
		int i;
		for(i=0;i<4;i++)
		{
				if(i==char_deal(lname[0]))
				{
					look_second(pfirst->dsecond[i],lname);
					return ;
				}
		}
}
