#include<stdio.h>
#define N 100
#include<string.h>
int main()
{
	int i,j,c,g;	
	char a[N],b[N];
	long m,n,k;
	char ch;
	scanf("%s",a);
	m=strlen(a);
	scanf("%s",b);
	n=strlen(b);
	strcat(a,b);
	k=m+n;
	for(i=0;i<k-1;i++)
		for(j=i+1;j<k;j++)
			if(a[i]>a[j])
			{
				ch=a[i];
				a[i]=a[j];
				a[j]=ch;
			}
	for(g=0;g<k;g++)
		for(i=0;i<k;i++)				
			if(a[i]==a[i+1])
			{
				for(j=i;j<k;j++)	
				a[j] = a[j+1];
			}						
	for(i=0;i<k;i++)
			printf("%c",a[i]);	
return 0;		
}
