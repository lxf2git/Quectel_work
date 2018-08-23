#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	char ch;
	for(;ch!='/';)
	{
			scanf("%c",&ch);
			if((64<ch&&ch<91)||(96<ch&&ch<123))
					a++;
			else if(47<ch&&ch<58)
					b++;
			else if(ch==32)
					c++;
			     else 
				    d++;	
	}
	printf("字母数:%d\n",a);
	printf("数字数:%d\n",b);
	printf("空格数:%d\n",c);
	printf("其他数:%d\n",d);
	return 0;
}
