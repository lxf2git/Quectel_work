#include<stdio.h> 
#include<stdlib.h>
int main() 
{
		char a[100]={};
		int i;
		for(i=0;;i++)
		{
				scanf("%c",&a[i]);
				if(a[i]=='\n')
					{a[i]='\0';
					break;}
				if(a[i]=='#')
				{
						for(;;)
						{
							scanf("%c",&a[i]);
							if(a[i]=='#')
							{
									i--;
									break;
							}
							if(a[i]=='\n')
							{
									a[i]='\0';
									puts(a);
									exit(0);
							}
						}	
				}
		}
		puts(a);
}
