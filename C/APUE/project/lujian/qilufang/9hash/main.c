#include"main.h"
int main()
{
	int i,j;
	int arr[]={15,20,12,41,15,74,35};
	pMod hash;
	hash=malloc(sizeof(sMod));
	for(i=0;i<5;i++)
	{
		hash->mod[i]=malloc(sizeof(sAnd));
		for(j=0;j<8;j++)
		{
			init_data(&(hash->mod[i]->an[j]),sizeof(sData));
		}
	}
	distribute(hash,arr,7);
	output(hash);
}
