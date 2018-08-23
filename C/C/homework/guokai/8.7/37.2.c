#include<stdio.h>
char *mystrcmp(char *dest,char *src)
{			
		int i,j,x,*p;
		char *a;
		 p=&x;
	for(i=0;i<20;i++)
			if(*(dest+i)==*(src+i))
			{
					continue;
					x=0;
			}
			else	
			{		
				j=i;
				x = *(dest+j)-*(src+j);
				break;
			}
			a=(char*)p;
			return a;			
}
int main()
{	
	char str1[20]="hello";
	char str2[20]="world";
	char *p= mystrcmp(str1,str2);
	printf("%d\n",*p);	
return 0; 
}

