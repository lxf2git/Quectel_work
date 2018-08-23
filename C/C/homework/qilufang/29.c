#include<stdio.h>
#include<string.h>
void count_char(char a[],int nb);
void count_line(char a[],int nb);
void count_word(char a[],int nb);

int main()
{
	int b;
	char string[100]={'\0'};
	gets(string);
	b=strlen(string);
	count_char(string,b);
	count_word(string,b);
	count_line(string,b);
	return 0;

}
void count_char(char a[],int nb)
{
	int i,nb_char=0;
	for(i=0;i<nb;i++)
	{
		if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
		{
			nb_char++;
		}
	}
	printf("nb_char:%d\n",nb_char);
}	
void count_word(char a[],int nb)
{
	int i,nb_word=0;
	for(i=0;i<nb;i++)
	{
		if(a[i]==32)
		{
			nb_word++;
		}
	}
	printf("nb_word:%d\n",nb_word);
}	
void count_line(char a[],int nb)
{
	int i,nb_line=0;
	for(i=0;i<nb;i++)
	{
		if(a[i]==46)
		{
			nb_line++;
		}
	}
	printf("nb_line:%d\n",nb_line);
}	
	
