#include<stdio.h>
#include<string.h>
void input(char *a);
void str_rank(char *a);
void str_deal(char *a);
int main()
{
		char a[100],b[100];
		input(a);
		input(b);
		str_rank(a);
		str_rank(b);
		strcat(a,b);
		str_rank(a);
		printf("%s\n",a);
		str_deal(a);
		printf("%s\n",a);
}
void input(char *a)
{
		scanf("%s",a);
}
void str_rank(char *a)
{
		int i,j;
		char temp;
		for(i=0;i<strlen(a);i++)
		{
				for(j=i;j<strlen(a);j++)
						if(a[i]>a[j])
						{
								temp=a[i];
								a[i]=a[j];
								a[j]=temp;

						}

		}

}
void str_deal(char *a)
{
		int i,j,k;
		for(i=0;i<strlen(a);i++)
				for(j=i+1;j<strlen(a);j++)
						if(a[i]==a[j])
						{
								for(k=j;k<strlen(a);k++)
								a[k]=a[k+1];
								j--;
								
						}
}
