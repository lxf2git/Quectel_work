#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
char move(char *point,int nu)
{
	char *arr;
	int size,up,down=0;
	size=strlen(point);
	up=size-nu;
	arr=(char*)malloc(size*sizeof(char));
	strcpy(arr,point+up);
	*(point+up)='\0';
//	printf("%s\n",arr);
	strcat(arr,point);
	printf("%s\n",arr);
	
}

int main()
{
	int nu;
	char arr[100]={};
	printf("请输入数组。");
	scanf("%s",arr);
	printf("您想移动几位哪？");
	scanf("%d",&nu);
	move(arr,nu);
}
