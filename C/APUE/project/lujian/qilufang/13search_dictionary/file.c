#include"main.h"
int file_get(char **all_file,char *argv)
{
		int i;
		char pattern[256];
		glob_t globres;
		sprintf(pattern,"%s/*.c",argv);
		glob(pattern,0,0,&globres);
		for(i=0;i<globres.gl_pathc;i++)
		{
			all_file[i]=globres.gl_pathv[i];
		}		
		return globres.gl_pathc;
}
void file_open(pMod hash,int file_nb,char **file_name,int word_nb)
{
	FILE *fp;
	char *arr[file_nb];
	int i;
	for(i=0;i<file_nb;i++)
	{
		arr[i]=malloc(sizeof(char)*1024);
	}
	for(i=0;i<file_nb;i++)
	{
		fp=fopen(file_name[i],"r");
		while(!feof(fp))
		{
			fread(arr[i],1024*sizeof(char),1,fp);		
		}
	}
	word_cmp(hash,arr,file_nb,word_nb);
	fclose(fp);	
}
void word_cmp(pMod hash,char **arr,int file_nb,int word_nb)
{
	char data[N];
	int i,j;
	for(i=0;i<file_nb;i++)
	{
		for(j=0;j<word_nb;j++)
		{
			strcpy(data,hash->mod[i]->an[j]->word);
			hash->mod[i]->an[j]->nb=word_cmp_1(data,arr[i]);
		}
	}
}
int word_cmp_1(char *data,char *arr)
{
	int len_arr=strlen(arr),len_data=strlen(data);
	int i=0,j=0,nb=0;
	while(i<len_arr)
	{
		j=0;
		if(*(arr+i)==*(data+j)&&len_data==1&&(*(arr+1+i)==' '||*(arr+1+i)==','
			||*(arr+1+i)=='.'))
		{
			nb++;
		}
		if(*(arr+i)==*(data+j)&&len_data!=1)
		{
			while(*(arr+i)!=' '&&j<len_data)
			{
				i++; j++;
				if(*(arr+i)!=*(data+j))
				{
					break;
				}
				if(j==len_data-1&&(*(arr+1+i)==' '||*(arr+1+i)==','
					||*(arr+1+i)=='.'))
				{
					nb++;	
				}
			}
		}
		i++;	
	}
	return nb;
}
