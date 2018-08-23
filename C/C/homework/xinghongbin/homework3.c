#include<stdio.h>
main()
{
		int a,b;
		char c;
		printf("input a?b\n");
		while(scanf("%d%c%d",&a,&c,&b)==3)                       //少于三个推出
		{
			switch(c)
			{
					case '+': printf("%d+%d=%d\n",a,b,a+b);break;	
					case '-': printf("%d-%d=%d\n",a,b,a-b);break;
					case '*': printf("%d*%d=%d\n",a,b,a*b);break;
					case '/': printf("%d/%d=%d\n",a,b,a/b);break;
					default : printf("error"); break;
			}
			printf("input a?b\n");
        }
}
