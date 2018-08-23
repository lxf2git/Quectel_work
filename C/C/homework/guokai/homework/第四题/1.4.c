#include<stdio.h>
int main()
{
printf("请输入运算表达式\n");
int data1,data2;
char op;
scanf("%d%c%d",&data1,&op,&data2);
switch(op)
      {
	      case '+': 
				 
				  printf("%d\n",data1+data2);
				  break;
		  case '-':
				 
		          printf("%d\n",data1-data2);
		          break;
		  case '*': 
				
		          printf("%d\n",data1*data2);
				  break;
		  case '/':
		
		          printf("%d\n",data1/data2);		 
				  break; 
	  }
}		
