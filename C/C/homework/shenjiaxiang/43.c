#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k=0,n;
	char str1[100],str2[100];
	printf("请输入a字符串：\n");
	gets(str1);
	n=strlen(str1);
	for(i=0;i<n-1;i++)
	{
		*(str2+k)=*(str1+i);
		k++;
	/*	if(i==(n-1))
		break;*/
		for(j=1;j<=2*i+1;j++,k++)
		{
			*(str2+k)='#';
		}
	}	
		*(str2+k)=*(str1+i);
		k++;
		*(str2+k)='\0';
	puts(str2);
}
