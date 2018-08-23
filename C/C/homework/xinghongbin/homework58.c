#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		int i,j;
		char a[]="ABCD1234efgh";
		char *str;
		char *str1=a;
		int length=strlen(a);
		str=(char *)malloc((length+1)*sizeof(char));
		for(i=0,j=length-1;j>=0;i++,j--)
				*(str+i)=*(str1+j);
		*(str+i)='\0';
		printf("%s\n",str);

		return 0;
}
