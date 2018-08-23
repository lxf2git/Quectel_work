#include<stdio.h>
void abc(char ch,int number,int line);
int main()
{
	int nu,ln;
	char ch;
	printf("please input in ask : \n");
	scanf("%c%d%d",&ch,&nu,&ln);
    abc(ch,nu,ln);	
	return 0;
}
void abc(char ch,int number,int line)
{
	int i,j;
	for(i=0;i<line;i++)
	{
		for(j=0;j<number;j++)
		{
			printf("%c",ch);
		}
		printf("\n");
	   
	}


}
