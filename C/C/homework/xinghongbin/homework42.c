#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void creat_memory(char **a,int size);
void input(char *a);
void deal(char *a);
int main()
{
		char *a;
		creat_memory(&a,100);
		input(a);
		deal(a);

}

void creat_memory(char **a,int size)
{
		*a=malloc(size);
}
void input(char *a)
{
		int i;
		for(i=0;;i++)
		{
				scanf("%c",a+i);
				if(*(a+i)=='.')
						break;
		}
		*(a+i)='.';
		*(a+i+1)='\0';
		printf("%s\n",a);
}
void deal(char *a)
{
		int max=0,mid=0,s=0;;
		int i,j=0;
		int length=strlen(a);
		printf("%d\n",length);
		for(i=0;i<=length;i++)
				if(*(a+i) == ' '||*(a+i) == '.')
				{
						*(a+i)='\0';
						mid=strlen(a+s)+1;
						s=s+mid;
//						printf("mid:%d\n",mid);
						if(max<mid)
								max=mid;
						
				}
//		printf("%d\n",max);
		s=0;
		for(i=0;i<=length;i++)
		{
				mid=strlen(a+s)+1;
				if(mid==max)
						printf("%s\n",a+s);
				s=s+mid;
		}


}

