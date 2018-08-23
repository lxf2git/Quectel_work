#include"save.h"

int char_deal(char c)
{
	if(c<='m')
	{
		if(c<='Z')
		{
				if(c<='M')
					return 0;
				else
					return 1;
		}
		else
			return 2;
	}
	else
		return 3;

}

int char_deal_again(char c)
{
	if(c<='m')
	{
		if(c<='Z')
		{
			if(c<='M')
					return c-'A';
			else
					return c-'M'-1;
		}
		else
			return c-'a';
	}
	else
		return c-'m'-1;
}

void same_name_strcat(pSword pshead,int fileno,int where)
{
		pshead->num++;
		pSword pnew;
		init_same_word(&pnew);
		pnew->file_no = fileno;
		pnew->where = where;
		//pnew->num = pshead->num;
		//找相同文件
		pSword ptmp = pshead->next;
		while(ptmp!=pshead)
		{
				if(ptmp->file_no==pnew->file_no)
				{
						ptmp->num++;
						pnew->num++;
				}
				ptmp = ptmp->next;
		}

		//尾插
		pnew->next = pshead;
		pnew->prev = pshead->prev;
		pshead->prev->next = pnew;
		pshead->prev = pnew;
}

void there_word(pWord save_word,int fileno,int where,char *p)
{
	//遍历所有name查找是否有相同的，有则存入该name下，无则存入该name右
	
	//printf("%s 是第 %d 个文件的第 %d 个单词.\n",p,fileno,where);
	pWord ptmp = save_word;
	while(ptmp->next!=save_word)
	{
		if(strcmp(ptmp->next->wsave,p)==0)//如果有相同的名字
		{
			same_name_strcat(ptmp->next->same_words,fileno,where);
			return ;
		}
		ptmp = ptmp->next;
	}
	//如果没有相同的名字，则添加新名字
	pWord pnew;
	init_word(&pnew);
	int i=0;
	do
	{
		pnew->wsave[i]=p[i];
		i++;
	}while(p[i-1]!='\0');//添加完新名字，就用尾插插到链上
	
		pnew->next = save_word;
		pnew->prev = save_word->prev;
		save_word->prev->next = pnew;
		save_word->prev = pnew;

}

void deal_second(pSec psave_sec,int fileno,int where,char *p)
{
	int i;
	for(i=0;i<13;i++)
	{
		if(i==char_deal_again(p[0]))
		{
			there_word(psave_sec->dword[i],fileno,where,p);
			return ;
		}
	}
}

void save_to_chain(pFirst pfirst,int fileno,int where,char *p)
{
		int i;
		for(i=0;i<4;i++)
		{
				if(i==char_deal(p[0]))
				{
					deal_second(pfirst->dsecond[i],fileno,where,p);
					return ;
				}
		}
}
