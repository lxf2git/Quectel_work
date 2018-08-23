#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char *p,int l);
void output(char *p,int l);
void creat_memory(char **p,int *l);
int main()
{
	char *str=NULL;
	int len;
	creat_memory((char **)&str,&len);
	input(str,len);
	output(str,len);

	return 0;
}

void output(char *p,int l)
{
	int n,k,i,m;
	char *pt1=(char *)malloc(l*sizeof(char));
	k=strlen(p)-1;
	n=1;
	m=1;
	while(k!=0)
	{	
		for(i=0;i<k;i++)
		{
			*(pt1+i)=*(p+(m-1)*(m-1)+m+i);
		}
		*(pt1+i)=0;
//		printf("pt:%s\n",pt1);
		for(i=0;i<n;i++)
		{
			*(p+(m-1)*(m-1)+m+i)='#';
//			printf("pbf:%s ptfor:%s\n",p,pt1);
		}
		*(p+(m-1)*(m-1)+m+i)=0;
//		printf("pbf:%s pt1:%s\n",p,pt1);
		strcat(p,pt1);
//		printf("paf:%s\n",p);
		n=n+2;
		m++;
		k--;
	}
	printf("Str:\n%s\n",p);
}

void input(char *p,int l)
{
	printf("put in :\n");
	scanf("%s",p);
	*(p+l)=0;
}

void creat_memory(char **p,int *l)
{
	printf("Len:\n");
	scanf("%d",l);
	*p=(char *)malloc(((*l-1)*(*l-1)+*l+1)*sizeof(char *));
	if(p==NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}
