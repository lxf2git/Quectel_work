#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char insert(char *p);


int main()
{
	char *p=NULL;
	p=(char *)malloc(10*sizeof(char));
	printf("please input str:\n");
	//scanf("%s",p);
	scanf("%s",p);
	insert(p);

}

char insert(char *p)
{
	int i,t,j=0,k=0;
	char ch[100];
	int count=0;
	t=strlen(p);
	printf("%d\n",t);
	printf("%s\n",p);
	for(i=0;i<100;i++)
	{
		if(i==0&&count==0)
		{
		ch[i]=p[i];
		i++;
		ch[i]='#';
		}
		else
		{
		ch[i]='#';
		if(i-k-1==2*count+1)
		{
			ch[i]=p[count+1];
			k=i;
			count=count+1;
		//printf("%s\n",ch);
		}
		}
		if(count==t-1)
		{
		ch[i+1]='\0';
		printf("%s\n",ch);
		break;
		}
	
	}
}













