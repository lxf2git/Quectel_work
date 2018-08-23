#include<stdio.h>
#include<string.h>
int judge_str(char str[])
{
		int i,m;
		int N=strlen(str);
		int j=N-1;
		for(i=0;i<N;i++)
		{
				if(str[i]==str[j])
				{
						j--;
						if(i==N/2)
						{
								m=0;
								break;
						}


				}
				else
				{
						m=-1;
						break;
				}
		}
		return m;
}

int main()
{
		int m;
		char string[100];
		gets(string);
		m=judge_str(string);
		printf("%d",m);
}
