#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
		int i;
		char stc[]="ABCD1234efgh";
		char dest;
		int len=strlen(stc);
		for(i=0;i<(len/2);i++)
		{
				dest=stc[i];
				stc[i]=stc[len-i-1];
				stc[len-i-1]=dest;
		}
		printf("%s\n",stc);
}
