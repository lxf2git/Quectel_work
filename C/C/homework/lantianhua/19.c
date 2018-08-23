#include<stdio.h>

int main()
{
	int a[10];
	int i,j;
	int m;
	int b=0,c;
	printf("please input a[10]:\n");
	for(i=0;i<10;i++)
	{

		scanf("%d",&a[i]);

	}
	printf("please input a number:\n");
	scanf("%d",&m);
	for(j=0;j<9;j++)
	{
              
	 	if(a[j]==m)
             {
			b=j;c=1;
			printf("%d\n",b);
			break;


             } else{ printf("sorry,not found!\n");
                    break;}
	  }
          return 0;   
}
