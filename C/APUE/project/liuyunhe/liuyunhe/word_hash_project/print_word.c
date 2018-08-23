#include"init.h"

void print_word(pMod pmod_head)
{
		int i,j;
		char print_word[20]={'\0'};
		printf("输入要查找的单词\n");
		scanf("%s",print_word);
        pCh palit;
		if(print_word[0]<='z'&&print_word[0]>='a')
		{
        	i=(print_word[0]-'a');
		}
		if(print_word[0]<='Z'&&print_word[0]>='A')
		{
        	i=(print_word[0]-'A');
		}
        j=strlen(print_word);
	    for(palit=pmod_head->mod[i]->and[j]->next;palit!=pmod_head->mod[i]->
			and[j];palit=palit->next)
	    {
                 if(strcmp(palit->ch,print_word)==0)
	             {
                       printf("word : %s,file : %d,time : %d \n",palit->ch,palit->word,palit->time);
                       
                 }
     	}

}
