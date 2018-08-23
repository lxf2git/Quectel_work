#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fan(char *s,char *h)
{
	int i,m=0,n=0,k,j;
	j=strlen(s)/3;
	for(k=1;k<=j;k++)
	{
		for(i=strlen(s);i>=3*k+n;i--)
		{
			s[i+1]=s[i];
		}
			m=3*k+n;		
			s[m]=' ';	
			n++;
		
	}
	strcpy(h,s);
//	for(i=0;i<strlen(s);i++)
//	{
//		printf("%c",s[i]);
//	}
}

int main()
{
	int i,s;
	char *str_new=NULL;
	char str_old[1024]={0};
	printf("input:");
	for(i=0;;i++)
	{
		scanf("%c",&str_old[i]);
		if(str_old[i]==10)
		{
			str_old[i]=0;
			break;
		}
	}
	s=strlen(str_old)+strlen(str_old)/3+1;
	str_new=(char *)malloc(s*sizeof(char));
	if(str_new==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	fan(str_old,str_new);
	puts(str_new);
	if(str_new!=NULL)
	{
		free(str_new);
		str_new=NULL;
	}
	
	return 0;
}




