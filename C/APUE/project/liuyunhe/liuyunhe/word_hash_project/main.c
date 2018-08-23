#include"main.h"
#include<glob.h>

int main(int argc,char *argv[])//  /home
{
  int i=0,j=0;
     int l=0,END;
     pMod pmod_head;
	 pCh palit;
     gmod_memoty(&pmod_head);
     mod_and_data(pmod_head);
     FILE *fp;
     char pattern[256];
     glob_t globres;
     char ch[100]={'\0'};
     sprintf(pattern,"%s/*.txt",argv[1]);//   /home/*  
  
      glob(pattern,0,0,&globres);
 
     for(i=0;i<globres.gl_pathc;i++)//   0  1  2
     {
        write(0,globres.gl_pathv[i],strlen(globres.gl_pathv[i]));

	 
		fp = fopen(globres.gl_pathv[i],"r+");
		fseek(fp,0,SEEK_END);
		END=ftell(fp);
		fseek(fp,0,SEEK_SET);
		while(l!=END)
		{
			char ch[2]={'\0'};
			char word[20]={'\0'};
			j=0;
			do
			{ 
				fread(ch,1,1,fp);
				if(ch[0]>='a'&&ch[0]<='z'||ch[0]>='A'&&ch[0]<='Z')
				{
						printf("%c\n",ch[0]);
						word[j]=ch[0];
						j++;			
				}

			}while(ch[0]>='a'&&ch[0]<='z'||ch[0]>='A'&&ch[0]<='Z');
			if(word[0]!='\0')
			{
				hash_word(pmod_head,word,i);
			printf("word  %s,,l %d\n",word,l);
			}
			l=ftell(fp);
	//		printf("word  %s,,l %d\n",word,l);
		}
     }
		print_word(pmod_head);
		printf("****END****\n");
}
