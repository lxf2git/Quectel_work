#include<stdio.h> 
#include<stdlib.h> 

void find_second_min(int **point,int col,int row)
{
	int c,r,se_min,min;
	min=**point;
	for(c=0;c<col;c++)
	{
		for(r=0;r<row;r++)
		{
			if(min>*(*(point+c)+r))
				min=*(*(point+c)+r);
		}
	}
	for(c=0;c<col;c++)
	{
		for(r=0;r<row;r++)
		{
			if(min==*(*(point+c)+r))
				*(*(point+c)+r)=90000000;
				break;
		}
	}
	se_min=**point;
	for(c=0;c<col;c++)
	{
		for(r=0;r<row;r++)
		{
			if(se_min>*(*(point+c)+r))
				se_min=*(*(point+c)+r);
		}
	}
	if(se_min==min)
		printf("如果您对结果感到意外也许您应该再参加一次高考。\n");
	printf("第二小的数是%d\n",se_min);
}
int main()
{
	int r,c,row,col,**point;
	printf("请输入数组的列数。");
	scanf("%d",&col);
	printf("请输入数组的行数。");
	scanf("%d",&row);
	point=(int**)malloc(col*sizeof(int*));
	for(r=0;r<row;r++)
	{
		*(point+r)=(int*)malloc(sizeof(int*));
	}
	printf("请输入数组元素。");
	for(c=0;c<col;c++)
	{
		for(r=0;r<row;r++)
		{
			scanf("%d",*(point+c)+r);
	//		printf("%d",*(*(point+c)+r));
		}
	}
	find_second_min(point,col,row);
	
}
