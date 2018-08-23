#include<stdio.h>
int main()
{
		int e=0,n=0,m=0,d=0;
		char a;
while(a!=10)
{
 scanf("%c",&a);
		 if((a>=65&&a<=90)||(a>=97&&a<=122))
 			 e++;
		 else if(a>=48&&a<=57)
				 n++;
		 else if(a==32)
				 m++;
		 else
		  
		  d++;
		  
}
  printf("%d\n",e);
  printf("%d\n",n);
  printf("%d\n",m);
  printf("%d\n",d);
}
