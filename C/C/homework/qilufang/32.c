#include<stdio.h>
#include<string.h>
#define N 10
void total(char a1[N],char a2[N],int a,int b);
int same(int nb[N]);
void output(char a[N],int id,int nb);

int main()
{	
	char str_1[N]={'\0'};
	char str_2[N]={'\0'};
	printf("输入一个字符串a：\n");
	gets(str_1);
	printf("输入一个字符串b：\n");
	gets(str_2);
	total(str_1,str_2,strlen(str_1),strlen(str_2));
	return 0;

}
void total(char a1[N],char a2[N],int a,int b)
{
	int d=0,i,j,k,c;
	int same_id[N]={0};
	int same_nb[N]={0};
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(a1[i]==a2[j])
			{
				d++;
				same_id[d]=i; 
				for(k=1;k<20;k++)
				{
					i++; 
					j++;
					same_nb[d]=k;
					if(a1[i]!=a2[j])
					break;
				}
			}
		}
	}
//	printf("same_id[2]:%dsame_nb[2]%d/n",same_id[2],same_nb[2]);
	c=same(same_nb);
	output(a1,same_id[c],same_nb[c]);
}
int same(int nb[N])
{
	int i,a=0,b=0;
	for(i=1;i<N;i++)
	{
		if(nb[i]>a)
		{
			a=nb[i];
			b=i;
		}
	}
//	printf("d:%d\n",b);
	return b;
}
void output(char a[N],int id,int nb)
{
	int i;
	printf("输出最大公共字串:\n");
	for(i=id;i<id+nb;i++)
	{		
		printf("%c",a[i]);	
	}
	printf("\n");
}
