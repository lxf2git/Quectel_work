#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int input_line(char a[100]);
//int str_space(char *a[100],int line);
//int str_length(char *a,int line);
int main()
{
		int i=0,j;
		int character,word=0;
		int line=0,length=0;
		char a[100];
		for(;;)
//		do
		{
//				a[0]='\0';
				scanf("%s",a);
				word++;
				length+=strlen(a);
				for(j=0;j<strlen(a);j++)
						if(a[j]=='.')
								line++;
				if(getchar()=='\n')
						if(getchar()=='\n')
							{
								length+=1;
								break;
							}

//				printf("%s\n",a);
//		printf("character:%d word:%d line:%d\n",c,word,line);

		}
//		while(a[0]!='\0');
//		space=str_space(a,line);
//		length=str_length(a,line);
//		character=length;
		
		printf("character:%d word:%d line:%d\n",length-line,word,line);
		return 0;
}
/*
int input_line(char a[])
{
		int length;
		int i;
		for(;;)
		{
				scanf("%s",a);
				i++;
				length=strlen(a);


		}
		return 0;
}

int str_space(char *a[100],int line)
{
		int i,j;
		int space=0;
		for(i=0;i<line;i++)
		{
				for(j=0;a[i][j]!='\0';j++)
						if(a[i][j]==' ')
								space++;
		}
		return space;


}
int str_length(char *a,int line)
{
		int i,j;
		int length=0;
		for(i=0;i<line;i++)
		{
				length+=strlen(a+i);
		}
		return length;
						
}*/
