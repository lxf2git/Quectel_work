



#include"creat_hash_lib.h"

int creat_hash_lib(Pfirst pf_hash)
{
	int i=0, j=0;

	for (i=0; i<N; i++)
	{
		creat_memory((void**)&pf_hash->pword_one[i], sizeof(Ssec));
	}

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			creat_memory((void**)&pf_hash->pword_one[i]->pword_last[j], sizeof(Sword));

			pf_hash->pword_one[i]->pword_last[j]->prev = pf_hash->pword_one[i]->pword_last[j];
			pf_hash->pword_one[i]->pword_last[j]->next = pf_hash->pword_one[i]->pword_last[j];
		}
	}

}

int creat_memory(void ** q, int size)
{
	*q = malloc(size);

	if (NULL == *q)
	{
	printf("malloc fail\n");
   	return FALSE;  	
	}
	return TURE; 
}

int init_post_node(Ppost* p)
{
	creat_memory((void **)p, sizeof(Spost));
	
	(*p)->next = (*p);
	(*p)->prev = (*p);

	return TURE; 

}

int init_word_node(Pword* p)
{
	creat_memory((void**)p, sizeof(Sword));

	(*p)->next = (*p);
	(*p)->prev = (*p);
	
	return TURE; 

}

int hash1(char * word)
{
	if ((*word) >='a' && (*word)<='z')
		 return (*word-71); 
	if ((*word)>='A'  && (*word)<='Z')
		return (*word -65); 
}

int hash2(char * word)
{
	int ch;
	ch = word[strlen(word)];

	if ((ch) >='a' && (ch)<='z')
		 return (*word-71); 
	if ((ch)>='A'  && (ch)<='Z')
		return (*word -65); 
}


