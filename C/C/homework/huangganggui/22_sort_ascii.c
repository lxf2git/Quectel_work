#include<stdio.h>
#include<string.h>
int main()
{
	char str[500] = "abcdefg";
	char strcp[500];
	int i = 0;
	int temp=0;
	char ch;
	puts(str);
	printf("input a chatacter expect '~'(input '~'to exit)\n");
	while( ch=getchar() )
	{	
	
		temp = 0;
		if(ch == '~')
			break;
		if(ch != 10)
		{
			strcpy(strcp,str);
			for(i=0;i != strlen(str);i++)
			{
				if(ch <= str[i])
				{
					temp = i;
		//			printf("%d\n",i);
					break;

				}
				
			}
			if(i != strlen(str))
			{
				strcp[i] = ch;
				
				for(i=temp;i <= strlen(str) ;i++)
				{
//					printf()
					strcp[i+1] = str[i];

				}
			}
			else
			{
				strcp[i+1]=0;
				strcp[i]=ch;
			}

		strcpy(str,strcp);
		puts(str);
		}
	}
	
	return 0;
}
