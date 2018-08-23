#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fan(char *p)
{
		int i=0,j=0,z=1,k=0,h=0;
		if(strlen(p)==1)
		{
				printf("%s",p);
		}
		else
		{
				k=0;
				for(j=0;j<strlen(p)-1;j++,k++)
				{
					z=(2*k)+1;
					for(i=strlen(p);i>j;i--)
					{
						p[i+z]=p[i];
					}
					for(h=1;h<=z;h++)
					{  
						p[h+j]='#';
					} 
					j += z;
				}
		
				for(i=0;i<strlen(p);i++)
				{
						printf("%c",p[i]);
				}


		}
}
 int main()
 {

 	char *a=NULL;
	a = (char *)malloc(100*sizeof(char));
	printf("input:");
	scanf("%s",a);		
	fan(a);
 	return 0;
 }




