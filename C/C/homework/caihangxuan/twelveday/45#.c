#include<stdio.h> 

int main()
{
	char arr[100]={};
	int nu=0;
	printf("请输入字符串\n");
	for(;;nu++)
	{	
		scanf("%c",&arr[nu]);
		if(arr[nu]=='\n')
			break;
		if(arr[nu]=='#')
		{
			for(;;)
			{
				scanf("%c",&arr[nu]);
				if(arr[nu]=='#'||arr[nu]=='\n')	
					break;
			}
		n--;
		}
	}
	arr[nu]='\0';
	printf("%s\n",arr);
}
