#include<stdio.h>
int input();
void deal_char(int a);
void deal_turn();
int i;
char b[200]={};
int main()
{
		int a;
		a=input();
		deal_char(a);
		deal_turn();
		return 0;
}
int input()
{

		int a;
		printf("plese input type of int\n");
		scanf("%d",&a);
		return a;
}
void deal_char(int a)
{
		
		if(a<0)
		{
				printf("-");
				a=a*(-1);
		}
		for(i=0;a/10 != 0;i++)
		{
				b[i]=a%10+48;
				a=a/10;	
		}
		b[i]=a+48;
//		printf("%s",b);
}
void deal_turn()
{
		int j;
		char c[200]={};
		for(j=0;j<=i;j++)
		{
				c[j]=b[i-j];
		}
		c[j+1]='\0';
		printf("%s",c);

}
