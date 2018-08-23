#include<stdio.h>
void input(char str[]);	
void count_chara(char str[]);
void count_word(char str[]);
void count_line(char str[]);

int n=0;
int main()
{
	char str[100]={0};
  	printf("please input in : \n");
	input(str);
	count_chara(str);
	count_word(str);
	count_line(str);
	return 0;
}
void input(char str[])
{
	char ch;
    do
	{
	 str[n]=getchar();
	 ch=str[n];
	 n++;
	}while(ch!='/');
	puts(str);
    printf("%d\n",n);	
}
void count_chara(char str[])
{
	int i,j=0;
	char ch;
	for(i=0;i<n;i++)
	{
	 	ch=str[i];
			if(ch>=65&&90>=ch||ch>=97&&122>=ch)
				j++;	
	}
    printf("character = %d\n",j);

}
void count_word(char str[])
{
   int i,j=0;
   char ch;
   for(i=0;i<n;i++)
   {
   	   ch=str[i]; 
       if(ch==' '||ch=='.')
	   {
	   		j++;
	   }
   }
   printf("word = %d\n",j);

}

void count_line(char str[])
{
   int i,j=0;
   char ch;
   for(i=0;i<n;i++)
   {
   	   ch=str[i]; 
       if(ch=='.')
	   {
	   		j++;
	   }
   }
   printf("line = %d\n",j);
}
