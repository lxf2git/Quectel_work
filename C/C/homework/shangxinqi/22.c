#include<stdio.h>
#include<string.h>

int main()
{
	int i,j=0;
	char ch,str[20]="aeimz";
	printf("输入一个字符\n");
	scanf("%c",&ch);
for(i=0;i<8;i++)
{
	if(ch <=str[i] )
		{
			j+=1;
			str[i+1]=str[i];
			str[i]=ch;
		}	
		if(j>0)
				break;
}
puts(str);
return 0;
}
