#include<stdio.h>

int main()
{
//----------------5.人民币兑换-----------

		int i,j,k;
		int one=1,two=2,five=5;
		int money=100;
		int count=0;
		for(i=0;i<=money/one;i++)
		{
				for(j=0;j<=money/two;j++)
				{
						for(k=0;k<=money/five;k++)
						{
								if(i*one+j*two+k*five==money)
								{
										printf("%d*%d+%d*%d+%d*%d=%d\n",i,one,j,two,k,five,money);
										count++;
								}
						}
				}
		}
		printf("一共有%d种兑换方法\n",count);

//--------------6.分钟显示--------------
/*
		float hour,minute,second;
		printf("请输入时间:\n");
		scanf("%f%f%f",&hour,&minute,&second);
		printf("等于%.3f分钟\n",hour*60+minute+second/60);
		
*/
//--------------7.字符串统计------------
/*
		char ch;
		int word=0,space=0,number=0,other=0;
		printf("请输入字符:\n");
		ch=getchar();
		while(ch!=10)
		{
				if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
				{
						word++;
				}
				else if(ch>='0'&&ch<='9')
				{
						number++;
				}
				else if(ch==' ')
				{
						space++;
				}
				else
				{
						other++;
				}
				ch=getchar();
		}
		printf("字母数:%d  空格数:%d  数字数:%d  其他:%d\n",word,space,number,other);
*/
//-----------8.100米自由落下-------------
/*
		float high=100,count=100;
		int i;
		for(i=2;i<=10;i++)
		{
				count+=high;
				high/=2;
				printf("%d次落地共经过%f米\n第%d次反弹%f米\n",i,count,i,high/2);
		}
*/
//-----------------9.汽水----------------
/*
		int money=20,n=0;
		int i;
		for(i=1;i<=money;i++)
		{
				n++;
				if(n%2==0)
				{
						n++;
				}
		}
		printf("20元最多可以喝到%d瓶汽水\n",n);
*/
		return 0;
}
