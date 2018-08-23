#include<stdio.h>
void statistic(char string[100]);

int main()
{
	char string[100]={};
	printf("please input the string:\n");
	gets(string);
	statistic(string);


	return 0;
}
void statistic(char string[100])
{
	int i;int a;
	int character=0,word=0,line=0;
	for(i=0;i<100;i++)
	{	a=string[i];
		if( (a>=65&&a<=90) || (a>=97&&a<=122))
			character++;
		else if(a==46)
			{
				line++;
				word++;
			}

			else if(a==32)
				word++;
		if(a==10)
		  break;
	}

	printf("character:%d\n",character);
	printf("line:%d\n",line);
	printf("word:%d\n",word);

	
}

