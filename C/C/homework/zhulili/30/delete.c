#include"delete.h"
#define N 4

void delete(char arr[])
{
	int i,j,g,x;
	for(j=0;j<2*N;j++)
	for(i=0;i<2*N;i++)
		if(arr[i]==arr[i+1])
			for(g=i;g<2*N;g++)
				arr[g]=arr[g+1];
	printf("删除相同字符后的字符串：%s\n",arr);
}

