#include<stdio.h>
#include<string.h>

#define N 10
int main()
{
	int i=0,j=0,x=0,y=0,n=0,len=0,max_len=0,flag=0,
		str1_len,str2_len;	
	char str1[N]={0};
	char str2[N]={0};

	printf("please input two string\n");
	do
	{
		str1[i++] = getchar();
	}while(str1[i-1]!='\n');
	str1[i-1] = '\0';

	i=0;
	do
	{
		str2[i++] = getchar();
	}while(str2[i-1]!='\n');
	str2[i-1] = '\0';
	
	str1_len = strlen(str1);
	str2_len = strlen(str2);
	printf("**%d %d\n",str1_len,str2_len);

	for(i=0;i<str1_len;i++)
	{
		for(j=0;j<str2_len;j++)
		{
			len = 0;
			x = i;
			y = j;
			while(str1[x]==str2[y]&&x<str1_len&&y<str2_len)
			{
				x++;
				y++;
				len++;
			}
			if(max_len<len)
			{
				flag = i;
				max_len = len;
			}
		}
	}

	for(i=flag;i<flag+max_len;i++)
	{
		printf("%c",str1[i]);
	}
	printf("\n");

	return 0;

}
