#include<stdio.h>
#include<string.h>
#define N 100

void input(char str1[N],char str2[N]);
void cpr(char s1[N],char s2[N]);

int main()
{
	char str_1[N]={};
	char str_2[N]={};

	input(str_1,str_2);
	cpr(str_1,str_2);
	return 0;
}

void input(char str1[N],char str2[N])
{
	printf("string_1:\n");
	scanf("%s",str1);
	printf("string_2:\n");
	scanf("%s",str2);
}

void cpr(char s1[N],char s2[N])
{	
	int s_1, s_2;
	int i,j,m,n,k,p,c;
	char xxx[N]={};
	s_1=strlen(s1);
	s_2=strlen(s2);

	p=0;
	for(i=0;i<s_1;i++)
	{
		for(j=0;j<s_2;j++)
		{	
			m=i;
			n=j;
			k=0;
			while(s1[m]==s2[n])
			{
				if(s1[m]==0||s2[n]==0)break;
				m++;
				n++;
				k++;
			}
//			printf("while %d %d %d\n",i,j,k);
			if(k>p)
			{	
//			printf("if %d %d %d\n",i,j,k);
//				c=0;
				p=k;
				for(m=i,c=0;c<k;c++)
				{
					xxx[c]=s1[m];
					m++;
				}
			}
		}
	}
	printf("%s\n",xxx);
}
