
#include"read_word.h"

int read_word(FILE* fp, Pfirst pf_hash, int file_id)
{
		int ch = 0;
		int i=0;
		char word[LEN];
		bzero(word,sizeof(word));

		while(ch !=EOF)
		{
				while((ch = fgetc(fp)) !=EOF)
				{	
						if ((judge_ch(ch)) && (i<=0))
						{
								continue;
						}
						else if((judge_ch(ch)) && (i>0))
						{		
								break;
						}
						else
								word[i++] = ch;
				}
				word[i]='\0';
				if (strlen(word)>=1)
				{
				i =0;
				add_hash_lib(word, pf_hash, file_id);
				}
		}
}

int judge_ch(char ch)
{
	return (!((ch>='a' && ch<='z')||(ch >='A' &&ch <='Z'))); 
}

int add_hash_lib(char* word, Pfirst pf_hash, int file_id)
{
	int h1,h2;
	static int id =0;
	Pword pnew =NULL, ptail =NULL;
	Pword re_same_word = NULL;
	Ppost re_same_post =NULL;

	h1 = hash1(word);
	h2 = hash2(word);

	if ((re_same_word = find_same_word(pf_hash->pword_one[h1]->pword_last[h2], word)) == NULL)
	{
			init_word_node(&pnew);
			init_post_node(&pnew->phead_post);

			pnew->word_id = ++id;
			strcpy(pnew->word, word);

			write_post_info(pnew->phead_post, file_id);

			ptail = find_word_ptail(pf_hash->pword_one[h1]->pword_last[h2]);

			add_word_back(ptail, pnew);
	}
	else
	{
		if ((re_same_post = find_same_post_file_id(re_same_word->phead_post, file_id)) == NULL)
		{
			write_post_info(re_same_word->phead_post, file_id);
		}
		else
		{
			(re_same_post->word_f)++;
		}

	}
}

Ppost find_same_post_file_id(Ppost phead, int file_id)
{

		Ppost ptravl =phead;

		while(ptravl->next != phead)
		{
			if (ptravl->next->file_id == file_id)
			{
				return ptravl->next; 
			}
				ptravl = ptravl->next;
		}
	
		return NULL;  
}

Pword find_same_word(Pword phead, char* word)
{
		Pword ptravl =phead;

		while(ptravl->next != phead)
		{
			if (strcmp(ptravl->next->word, word)==0)
			{
				return ptravl->next; 
			}
			ptravl = ptravl->next;
		}
	
		return NULL;  
}
int write_post_info(Ppost phead_post, int file_id)
{
	Ppost pnew=NULL, ptail=NULL;
	init_post_node(&pnew);
	pnew->file_id = file_id;
	pnew->word_f =1;
	ptail = find_post_ptail(phead_post);
	add_post_back(ptail, pnew);
	return TURE; 
}

Ppost find_post_ptail(Ppost phead)
{
	Ppost ptravl = phead;
	while(ptravl->next !=phead)
	{
		ptravl = ptravl->next;
	}
	return ptravl; 
}


Pword find_word_ptail(Pword phead)
{
	Pword ptravl = phead;
	
	while(ptravl->next !=phead)
	{
		ptravl = ptravl->next;
	}
	
	return ptravl; 
}

int add_post_back(Ppost pos, Ppost pin)
{
	if (NULL == pos || NULL == pin)
	{
		return FALSE;  
	}
	
	pin->prev =pos;
	pin->next =pos->next;
	
	pos->next->prev =pin;
	pos->next =pin;
	
	return TURE; 
}

int add_word_back(Pword pos, Pword pin)
{
	if (NULL == pos || NULL == pin)
	{
		return FALSE;  
	}
	
	pin->prev =pos;
	pin->next =pos->next;
	
	pos->next->prev =pin;
	pos->next =pin;
	
	return TURE; 
}

