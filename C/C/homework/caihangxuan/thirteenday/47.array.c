#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define N 100

int cmp(int n,char *p[],char *copy[])
{
	int nub=0,nub_=0,revert=0,i=0;
	char *tmp;
	for(;nub<n;nub++)
	{
		for(;nub_<n;nub_++)
		{
//			printf("%s %s\n",p[nub],p[nub_]);
			revert=strcmp(*(p+nub),*(p+nub_));
//			printf("nub:%s nub_:%s\n",p[nub],p[nub_]);
			if(revert<0)
			{
				tmp=*(copy+nub);
				printf("%s\n",tmp);
				*(copy+nub)=*(p+nub_);
				*(copy+nub_)=tmp;
			}
		}
	}
	nub=n-1;
	for(;nub>=0;nub--)
		printf("%s\n",copy[nub]);
}
int cat(int n,char *p[],char *copy[])
{
	int size_nu,nub=0,size,new_size;
	for(;nub<n;nub++)
	{
		size=strlen(p[nub]);
		if(size%2!=0)
			new_size=1+size;
		else
			new_size=size;
		new_size=new_size/2;
		for(size_nu=0;size_nu<new_size;size_nu++)
		{
			*(*(p+nub)+size_nu)=*(*(p+nub)+--size);
//			printf("last:%c\n",*(*(p+nub)+size_nu));
//			printf("last:%c\n",*(p+size_nu)[nub]);
//			printf("last:%c\n",*(p[nub]+size_nu));
		}
		*(*(p+nub)+size_nu)='\0';
	}
	for(nub=0;nub<n;nub++)
		printf("分割为：%s\n",p[nub]);
	cmp(n,p,copy);
}
int main()
{
	int n,nub=0;
	printf("您要输入几个字符串？\n");
	scanf("%d",&n);
	char *p[n],*copy[n];
	for(;nub<n;nub++)
	{
		p[nub]=(char*)malloc(N*sizeof(char));
	        copy[nub]=(char*)malloc(N*sizeof(char));
	}
	printf("请输入字符串。\n");
	for(nub=0;nub<n;nub++)
		scanf("%s",p[nub]);
/*	for(nub=0;nub<n;nub++)
		printf("%s\n",p[nub]);*/
	for(nub=0;nub<n;nub++)
	        strcpy(copy[nub],p[nub]);
	cat(n,p,copy);
}
