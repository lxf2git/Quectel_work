#include<stdio.h>
#include<string.h>
void input(char a[]);
int main()
{
    char str[100]={0};
	input(str);
	puts(str);
    return 0;
}
void input(char a[])
{
	char ch;
	int i,j;
    gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='c')
		{
			for(j=i;j<strlen(a);j++) //将‘c’后面字母向前移位 
			{
			  a[j]=a[j+1];
			}
		    i--;    //再次循环
		}
	
	
	}


}
