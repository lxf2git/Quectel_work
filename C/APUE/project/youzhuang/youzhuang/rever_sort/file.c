#include"main.h"

void file(pMod hash)
{
		char ch[256];
		glob_t globres;
		printf("请输入文件路径:\n");
		scanf("%s",ch);
		if(judge_way(ch)==SUB)
		{
				sprintf(ch,"%s/*.c",ch);
		}
		glob(ch,0,0,&globres);
		read_file(hash,globres);
}

int judge_way(char ch[])
{
		int i=0;
		while(ch[i]!='\0')
		{
				if(ch[i]=='.')
				{
						return EMPTY;
				}
				i++;
		}
		return SUB;
}

void read_file(pMod hash,glob_t globres)
{
		char word[WORD_LEN];
		char ch;
		FILE *fp=NULL;
		int i,j=0;
		for(i=0;i<globres.gl_pathc;i++)
		{
				fp=fopen(globres.gl_pathv[i],"r");
				while(!feof(fp))
				{
						ch=fgetc(fp);
						if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
						{
								word[j]=ch;
								j++;
						}
						else
						{
								word[j]='\0';
								insert_hash(hash,word,i);
								j=0;
						}
				}
				fclose(fp);
		}
}

void insert_hash(pMod hash,char word[],int i)
{
		pWord phead=NULL,pword=NULL;
		pLabel plabel=NULL;
		if(word[0]!='\0')
		{
				phead=hash->mod[word_mod(word)]->letter[word_letter(word)];
				pword=find_word(phead,word);
				if(NULL==pword)
				{
						init_word_list(&pword);
						insert_word(phead,pword);
						copy_word(&pword->word,word);
				}
				plabel=find_label(pword->label,i+1);
				if(NULL==plabel)
				{
						init_label_list(&plabel);
						insert_label(pword->label,plabel);
				}
				plabel->file_no=i+1;
				plabel->num++;
		}
}

void copy_word(char **dest,char src[])
{
		create_memory((void **)dest,strlen(src)+1);
		strcpy(*dest,src);
}

pLabel find_label(pLabel phead,int file_no)
{
		pLabel p=phead->next;
		while(p!=NULL)
		{
				if(p->file_no==file_no)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}

pWord find_word(pWord phead,char word[])
{
		pWord p=phead->next;
		while(p!=phead)
		{
				if(strcmp(p->word,word)==0)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}

int word_mod(char word[])
{
		int i,num=0;
		for(i=0;i<strlen(word);i++)
		{
				num+=word[i];
		}
		return num%ROW;
}

int word_letter(char word[])
{
		if(word[0]>'Z')
		{
				return word[0]-97;
		}
		else
		{
				return word[0]-65;
		}
}
