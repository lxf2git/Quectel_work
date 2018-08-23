#include<stdio.h> 
#include<string.h> 
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int id=1,times=0,number=10;
	for(;;id++)
	{
		if(a[id-1]!=0)
		{
			if(number==1)
				break;
			times++;
			if(times==3)
			{
				a[id-1]='\0';
				number--;
				times=0;
				printf("我杀了%d号\n",id);
			}
			if(id>=10)
			id=0;	
		}
	}
	printf("最后只剩下");
	for(id=0;id<10;id++)
	printf("%c ",a[id]);
}
