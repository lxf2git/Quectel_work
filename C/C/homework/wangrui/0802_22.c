#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int n,i,j,k;
	char ch;
	char str[N]={};
	char str2[N]={};
	for(n=0;n<N;n++)
	{
		scanf("%c",&ch);
		getchar();
		for(i=0;i<N;i++)
		{
			if(ch < str[i])
			{
				for(j=i,k=0;j<N;j++,k++)
				{
					str2[k]=str[j];
					str[j]='\0';
				}
				str[i]=ch;
				printf("%s\n",strcat(str,str2));
				break;
			}
			if(str[i]=='\0')
			{
				str[i]=ch;
				printf("%s\n",str);
				break;
			}
		}
	}
	return 0;
}
