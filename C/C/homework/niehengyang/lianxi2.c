#include<stdio.h>
int main()
{
	int a,b,c;
	int n,i,m=0,g;
	printf("请输入年，月，日:\n");
	scanf("%d,%d,%d",&a,&b,&c);
	 if(a%100==0)
        {
                if(a%400==0)
                {
                printf("%d是润年\n",a);
		n=1;
                }
                else
		{
                printf("%d不是润年\n",a);
		n=0;
		}
        }
        else
        if(a%4==0)
        {
        printf("%d是润年\n",a);
	n=1;
        }
                                                 
	  else
	{
        printf("%d不是润年\n",a);
	n=0;
	}
	for(g=1;g<b;g++)
	{
		m=m+31;
	if(n==1&&g==2)
		m=m-2;
	if(n==0&&g==2)
		m=m-3;
	if(g==4||g==6||g==9||g==11)
		m=m-1;

	}	
	printf("你输入的%d年%d月%d日是%d的第%d天\n",a,b,c,a,c+m);

}
