#include<stdio.h>
#include<string.h>
void input(char a[]);
void sort(int n,char a[]);
void delete(char str_a[]);
int main()
{
	int n;
    char str_a[100];
	char str_b[100];
	input(str_a);
	input(str_b);
	strcat(str_a,str_b);
	puts(str_a);
	delete(str_a);
	return 0;
}
void input(char a[])
{ 
	int n;
	printf("please input in : \n");
	gets(a);
	n=strlen(a);
	sort(n,a);
}
void sort(int n,char a[])
{
	int i,j;
	char t;
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-1-j;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
   puts(a);	
}
void delete(char str_a[])
{
	int i,j,n,k=0;
	char ch1,ch2;
    char str_c[100];
	for(i=0;i<strlen(str_a);i++)
	{ 
        ch1 = str_a[i];
		n=0;
		for(j=0;j<strlen(str_a);j++)
		{
				ch2 = str_a[j];
				if(ch1==ch2)
				{
				  n++;
                }
		}
        if(n==1)
		{
			str_c[k] = ch1;
			k++;
		}		
	}
	str_c[k]='\0';
	n=strlen(str_c);
   sort(n,str_c);
}




