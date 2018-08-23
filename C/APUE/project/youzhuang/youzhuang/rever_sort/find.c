#include"main.h"

void find(pMod hash)
{
		pWord phead=NULL,pword=NULL;
		char word[WORD_LEN];
		printf("请输入查找的单词:\n");
		scanf("%s",word);
		phead=hash->mod[word_mod(word)]->letter[word_letter(word)];
		pword=find_word(phead,word);
		if(pword!=NULL)
		{
				output_word(pword);
		}
		else
		{
				printf("没有这个单词!\n");
		}
}
void output_word(pWord pword)
{
		pLabel p=pword->label->next;
		printf("word:%s\n",pword->word);
		while(p!=NULL)
		{
				printf("file_no:%d num:%d\n",p->file_no,p->num);
				p=p->next;
		}
}
