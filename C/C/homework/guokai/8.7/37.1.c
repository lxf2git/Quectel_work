#include<stdio.h>
char *mystrcat(char *dest,char *src)
{
		int i,j;
		for(i=0;i<20;i++)
			if(*(dest+i)=='\0')
			{		
				j=i;
	 			for(i=j;i<20;i++)
				{
				*(dest+i)=*src;
				    src++;
				}
			}
return dest;
}

int main()
{
	char str1[20]="hello";
 	char str2[20]="world";
	char *p =mystrcat(str1,str2);
	printf("%s\n",p);	
return 0;
}
