#include<stdio.h>
int main()
{
	char c;	
	int word=0,line=0,character=0,i;	
   while((c=getchar())!='\n')
	{
		if(c==32||c==46)
				word++;
		if(c==46)
				line++;
        if((c>=65&&c<=90)||(c>=97&&c<=122))
			    character++;	
	}	
	printf("character=:%dword=:%dline=:%d\n",character,word,line);
return 0; 
}
