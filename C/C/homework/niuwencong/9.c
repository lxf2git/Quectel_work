#include<stdio.h>
int main()
{
        int a,b=0,i,s;
	printf("你就告我你有几块钱：\n");
	scanf("%d",&a);
	s=a;
	for(i=1;;i++)
	{
		if(a==1&&b==0)
			break;
			if(a%2!=0)
			{
				if(b==0)
				{
					a=(a-1)/2;
					b=b+1;	
				
				}	
				else 
				{
					a=(a+1)/2;		
					b=0;
				}
			}
			else
			{
				a=a/2;					
	
			}
		s=s+a;


	}
	printf("你最多也就能喝%d瓶汽水，哈哈哈哈哈哈哈哈哈哈\n",s);	
return 0;
}
