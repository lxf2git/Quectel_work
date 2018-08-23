

#include"index_word.h"

int index_word(Pfirst pf_hash)
{
	char word[256];
	int h1, h2;
	Pword re_same_word =NULL;
	printf("please index word \n"); 
	gets(word);
	puts(word);
	h1 = hash1(word);
	h2 = hash2(word);
	if ((re_same_word = find_same_word(pf_hash->pword_one[h1]->pword_last[h2], word)) !=NULL)
	{
		print_post_list(re_same_word->phead_post);

		return TURE;  
	}
	
	else
	{
		printf("no such this word in these file appear\n"); 

		return FALSE;  
	}


}

int print_post_list(Ppost phead)
{
	Ppost ptravl = phead;

	while(ptravl->next != phead)
	{
		printf("(file_id:%d  ,word_f:%d ) \n",
					   	ptravl->next->file_id, ptravl->next->word_f); 

		ptravl = ptravl->next;
	}

	return TURE; 	
}
