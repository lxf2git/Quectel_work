#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

void create_memory(char**ptr, int size)
{
	*ptr = (char *)malloc(size);
	if(NULL == *ptr)
	{
		printf("ptr malloc error!\n");
		exit(-1);
	}
}

void put_in(char *p)
{
	
	printf("please input string:");
	scanf("%s",p);
}

char * linked(char *p1,char *p2, int flag)
{
	
	switch(flag)
	{
		case 1:return strcat(p1,p2);break;
		case 0:return strcat(p2,p1);break;
		default:
			  // p1 = "(null)";
			//	strcpy(p1,NULL);
				p1 = NULL;
			   return p1;break;
	}
}

int main()
{
	char * arr1=NULL;
	char *arr2=NULL;
	char * brr=NULL;
	int flag;

	create_memory(&arr1, N);
	create_memory(&arr2, N);
	create_memory(&brr, N);

//	puts(arr1);
	put_in(arr1);
	put_in(arr2);

	puts(arr1);
	puts(arr2);
	printf("please input the value of flag:(0:b linked back a,1:a linked back b,other:default!\n");
	scanf("%d",&flag);

	brr = linked(arr1, arr2, flag);

	puts(arr1);
	puts(arr2);
//	puts(brr);
	printf("%s",brr);
	return 0;
}
