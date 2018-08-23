#include<stdio.h>
int main()
{
 char a;
 int b=0,z=0,k=0,s=0,q=0,i=0;
 	printf("请输入一串字符\n");
  
 while(a!='\n')
   {
		   scanf("%c",&a);
		   b++;
		   if(a>='a'&&a<='z'||a>='A'&&a<='Z')
				   z++;
		   else if(a==32)
				   k++;
		   else if(a>='0'&&a<='9')
				   s++;
		   i=b-z-k-s;
   	
   }
  
 	printf("字母；%d空格；%d数字；%d其他；%d",z,k,s,i);
	return 0;
}
