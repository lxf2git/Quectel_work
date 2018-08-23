#include<stdio.h>
#include<string.h>
void judge(int n,char *p,int l,char *q);
int main()
{
	int n,l;
	char str_a[100];
	char str_b[100];
	printf("please input str_a : \n");
	gets(str_a);
	printf("please input str_b : \n");
	gets(str_b);
    n = strlen(str_a);
	l = strlen(str_b);
	judge(n,str_a,l,str_b);
	return 0;
}
void judge(int n,char *p,int l,char *q)
{
	 int i,j,x=0,y,k=0;
	char ch,ch1;
	char str_c[100];
	
	for(i = 0;i < n;p++,i++)
	{
		ch = *p;
		for(j = 0;j<l;q++,j++)
		{
			ch1 = *q;
		    if(ch == ch1) 
			{
				k = 0;
				for(;*p == *q&&*q!='\0'&&*p!='\0';)
				{
					p++;
					q++;
				    k++;
				}
				p=p-k;
				q=q-k;
			}	
		    if(k>x)
			{
				for(y=0;y<k;y++,p++)
				{
				   str_c[y]=*p;
				}
			    x=k;
				p=p-k;
			}
		}
		q=q-l;	
	}
	str_c[x]='\0';
    puts(str_c);
}
