#include<stdio.h>
#include<string.h> 
char first_list[100]={" "}, second_list[100]={" "},thired_list[128]={" "},recon_f,recon_s;
int i,n,s,times=0,size_f,size_s;    //size_f为第一数列的数量 size_s为第二数列的数量
void convert()         //将数列第一次排序，i为方first——list的下标，而n为second——list下标
{
	for(times;times<100;times++)
	{
		i=size_f-1;
		for(;i>=1;i--)
		{
			if(first_list[i]<first_list[i-1])
			{
				recon_f=first_list[i];
				first_list[i]=first_list[i-1];
				first_list[i-1]=recon_f;
			}
		}
		n=size_s-1;
		for(;n>=1;n--)
		{
			if(second_list[n]<second_list[n-1])
			{
				recon_s=second_list[n];
				second_list[n]=second_list[n-1];
				second_list[n-1]=recon_s;
			}
		}
	}
}
void convert2()           //将数列综合排序覆盖重复的字符。
{
	for(s=0;s<128;s++)
	{
		printf("外s:%d",s);
		for(;i>=0;i--)
		{	
			printf("# %d %d\n",s,first_list[i]);
			if(s==first_list[i])
			{
				thired_list[s]=first_list[i];
				printf("%c",thired_list[s]);
				printf("1");
			}
		}
		for(;n>=0;n--)
		{
			printf("@ %d %d\n",s,first_list[n]);
			if(s==second_list[n])
			{
				thired_list[s]=second_list[n];
				printf("%c",thired_list[s]);
				printf("2");
			}
		}
	}
}
int main()
{
	printf("请输入第一个字符串");
	scanf("%s",first_list);
	printf("请输入第二个字符串");
	scanf("%s",second_list);
	size_f=(int)strlen(first_list);
	size_s=(int)strlen(second_list);
	convert();
	printf("第一个数列为%s\n第二个数列为%s\n",first_list,second_list);
	i=size_f-1;n=size_s-1;
	convert2();
	printf("综合为");
	for(s=0;s<128;s++)
	{
	if(thired_list[s]!=0)
	printf("%c",thired_list[s]);
	}
	printf("\n");
}
