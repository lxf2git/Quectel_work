#include<stdio.h>
#include<string.h>
int main()
{
		int char_s;
		int i,j;
		char ch,ch1,str[20]={0},str1[10]={0};
		printf("请输入一串字符(小于10位):\n");
		gets(str);
		char_s = strlen(str);

		for(i=0;i<char_s;i++)
		{
				for(j=i;j<char_s;j++)
				//printf("%d\n",strlen(str));
				if(str[i]>str[j])
				{
						ch = str[i];
						str[i] = str[j];
						str[j] = ch;
				}

		}

	//	printf("***********");
	//puts(str);
		printf("请输入一串字符(小于10位):\n");
		gets(str1);
		char_s=strlen(strcat(str,str1));
	//	char_s = strlen(str);  
		for(i=0;i<char_s;i++)
		{
				for(j=i;j<char_s;j++)			
		//printf("%d\n",strlen(str));
				if(str[i]>str[j])
				{
						ch = str[i];
						str[i] = str[j];
						str[j] = ch;
				}

		}
	puts(str);


}
