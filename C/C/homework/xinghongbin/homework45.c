#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void create_memory(char **p);
int str_input(char *p);
int find_a(char *p);
int find_b(char *p,int j);
void del_str(char *p);
int main()
{
		char *p;
		create_memory(&p);
		str_input(p);
		del_str(p);
		
}

void create_memory(char **p)
{
		int size;
		printf("input size for str\n");
		scanf("%s",&size);
		*p=(char *)malloc(size);
}
int str_input(char *p)
{
		printf("input str\n");
		scanf("%s",p);
}

int find_a(char *p)
{
		int i;
		int length=strlen(p);
		for(i=0;i<length;i++)
				if(p[i]=='#')
						return i;
		return -1;
}
int find_b(char *p,int j)
{
		int i;
		int length=strlen(p);
		for(i=j+1;i<length;i++)
				if(p[i]=='#')
						return i;
		return -1;

}

void del_str(char *p)
{
		int pro,beh;
		int offset;
		int i;
		int length=strlen(p);
		while(1)
		{
				pro=find_a(p);
				if(pro<0)
						break;
				beh=find_b(p,pro);
				if(beh<0)
						break;
				offset=beh-pro+1;

						for(i=pro;i <= length-offset;i++)
								p[i]=p[i+offset];
						p[i]='\0';
		}
		printf("%s\n",p);

}	

