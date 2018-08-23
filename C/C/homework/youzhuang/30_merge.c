#include<stdio.h>
#include<string.h>

#define N 100

void sort(char ch[]);
void del(char ch[]);

int main()
{
		char ch1[N], ch2[N];
		printf ("请输入字符串1:\n");
		scanf ("%s", ch1);
		printf ("请输入字符串2:\n");
		scanf ("%s", ch2);
		sort(ch1);
		sort(ch2);
		strcat(ch1,ch2);
		sort(ch1);
		del(ch1);
		printf("%s\n",ch1);
		return 0;
}

void sort(char ch[])
{
		int i, j;
		char t;
		for (i = 0; i < strlen(ch); i++)
		{
				for (j = i; j < strlen(ch); j++)
				{
						if (ch[i] > ch[j])
						{
								t = ch[i];
								ch[i] = ch[j];
								ch[j] = t;
						}
				}
		}
}
void del(char ch[])
{
		int i, j, k, n=0;
		while(1)
		{
				n=0;
				for (i = 0; i < strlen(ch); i++)
				{
						for (j = i+1; j < strlen(ch); j++)
						{
								if (ch[i] == ch[j])
								{
										for(k=j;k<strlen(ch);k++)
										{
												ch[k]=ch[k+1];
										}
										n++;
								}
						printf("%d ",n);
						}
						printf("%d ",n);
				}
				printf("\n");
				if(n==0)
				{
						break;
				}
		}
}
