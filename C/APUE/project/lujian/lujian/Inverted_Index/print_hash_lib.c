
#include"print_hash_lib.h"


int print_hash_lib(Pfirst pf_hash)
{
	
	int i=0, j=0;

	for (i=0; i<N; i++)
	{
		if(i<=25)
		{
		printf("===========%c ===========\n",i+65); 
		}
		else
		{
		printf("===========%c ===========\n",i+71); 
		}
		for (j=0; j<N; j++)
		{	
			print_word(pf_hash->pword_one[i]->pword_last[j]);
		}
	}

}

int print_word(Pword phead)
{
	Pword ptravl = phead; 	

	while(ptravl->next != phead)
	{
			printf("%-s\n", ptravl->next->word);
		   	ptravl = ptravl->next;	
	}

	return TURE; 
}
