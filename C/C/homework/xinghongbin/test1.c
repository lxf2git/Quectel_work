#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
		int length,i;
		char *new;
		new=(char *)malloc(20);
		char *old;
		old=(char *)malloc(20);

		scanf("%s",old);

		length=strlen(old);
		for(i=0;i<length;i++)
		{
				new[i]=old[i];
		}
		printf("%s\n",new);

}
