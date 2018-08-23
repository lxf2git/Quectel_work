#include"read.h"

void read_data(pMod phead,char *p)
{
	FILE *fp;
	char ch;
	int a=0;
	char word[L];
	char pattern[256];
	glob_t globres;
	int i,j;
	sprintf(pattern,"%s/*.c",p);
	glob(pattern,0,0,&globres);
	//printf("%d\n",globres.gl_pathc);
#if 1
	for(i=0;i<globres.gl_pathc;i++)
	{
		fp=fopen(globres.gl_pathv[i],"r");
		j=0;
		while(!feof(fp))
		{
			ch=fgetc(fp);
			if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
			{
				word[j]=ch;
				j++;
			}
			else
			{
				word[j]='\0';
				if(word[0]!='\0')
				{
					hash(word,i,phead);
				}
				j=0;
			}
		}
		fclose(fp);
	}
#endif
}

