#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char delete(char *p);



int main()
{
	char *p=NULL;
	printf("please input str:");
	p=(char *)malloc(100*sizeof(char));
	scanf("%s",p);
	delete(p);
}

char delete(char *p)
{
	int i,t;
	char str[100];
	int j;
	t=strlen(p);
	printf("%s\n",p);
	printf("%d\n",t);
	for(i=0;i<t;i++)
	{
		if(p[i]=='#')
		{
			p[i]='\0';
			for(j=i+1;j<t;j++)
			{
				if(p[j]=='#')
				{
				strcat(p+i,p+j+1);
				}

			}
			i=i-1;
		}
	}

	printf("%s\n",p);

}
