#include<stdio.h>
int main() 
{
	int i,j;
	char a[5]="acef",ch;
	printf("排序好的字符串:acef\n输入插入字符:");
	scanf("%c",&a[4]);
	   for(i=3;i>=0;i--)	  
		if((int)a[i+1]<(int)a[i])
		{		
            ch=a[i+1];
			a[i+1]=a[i];
			a[i]=ch;			
		}	   
		for(j=0;j<5;j++)
	printf("%c",a[j]);
return 0;
}
