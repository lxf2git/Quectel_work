#include<stdio.h>
#include<string.h>
int main()
{
	char c[500]={};
	char ch[500]={};
	int a,tmp;
	int i,j,k,m,n;
       for(m=0;m<500;m++)
	{
	printf("please  input  char\n");
	gets(c);
        strcpy(c, strcat( c,ch));
	a=strlen(c);
	for(i=0;i<a-1;i++)
	{
		for(j=i+1;j<a;j++)
		{
			if(c[i]>c[j])
			{
				tmp=c[j];
				c[j]=c[i];
				c[i]=tmp;
			}
		}
	}
	printf("%s\n",c);
	strcpy( ch, c);
	
	}
	return 0;
}
