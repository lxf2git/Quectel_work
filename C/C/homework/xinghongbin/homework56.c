#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int choose(char **argv,void(**p)(int,int));
int numa(char **argv,int i);
int numb(char **argv,int i);
void myadd(int a,int b);
void mysud(int a,int b);
void myadv(int a,int b);
void mydiv(int a,int b);
int main(int argc,char**argv)
{
		void(*p)(int,int);
		int a,b,i;
		i=choose(argv,&p);	
		a=numa(argv,i);
		b=numb(argv,i);
		
		if((b==0) && (p==mydiv))
		{
				printf("error div\n");
				exit(-1);
		}
		p(a,b);
		
}

int choose(char **argv,void(**p)(int,int))
{
		int i;
		if(argv[1] != NULL)
				for(i=0;i<strlen(argv[1]);i++)
				{
						int a=0;
						switch(argv[1][i])
						{
								case'+':
										a=1;
										*p=myadd;
										break;
								case'-':
										a=1;
										*p=mysud;
										break;
								case'*':
										a=1;
										*p=myadv;
										break;
								case'/':

										a=1;
										*p=mydiv;
										break;
								default:
										break;		
						}
						if(a == 1)
								break;
				}
		return i;

}
int numa(char **argv,int i)
{
		int a=0,b=0;
		int k,j;
		k=i;
		for(i=k-1;i>=0;i--)
		{
				argv[1][i]-=48;
				for(j=i;j<k-1;j++)
				{
						argv[1][i]*=10;
				}
				a+=argv[1][i];

		}
		printf("%d\n",a);

		return a;


}

int numb(char **argv,int i)
{
		int a=0,b=0;
		int k,j;
		k=i;
		for(i=k+1;i<strlen(argv[1]);i++)
		{
				argv[1][i]-=48;
				for(j=i;j>k+1;j--)	
						argv[1][i]*=10;
				b+=argv[1][i];


		}
		
		printf("%d\n",b);
		return b;

}
void myadd(int a,int b)
{
		printf("%d\n",a+b);
}
void mysud(int a,int b)
{
		printf("%d\n",a-b);
}
void myadv(int a,int b)
{
		printf("%d\n",a*b);
}
void mydiv(int a,int b)
{
		printf("%d\n",a/b);
}
