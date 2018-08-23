#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

void create_memory(char ** prr, int size)
{
	*prr = (char *)malloc(size);
	if(NULL == *prr)
	{
		printf("prr malloc error!\n");
		exit(-1);
	}

}

void in_put(char *p, int n)
{
	int i,j,count=1;
	int num=0,max=0;
	int a[N]={},len;
	for(i=0;i<N;i++)
	{
		scanf("%c",(p+i));
		num++;
		if('.' == *(p+i))
		{
			num--;
			len = num;
			break;
		}
	}
	printf("len:%d\n",len);
	num=0;
	for(i=0;i<len+1;i++)
	{
		num++;
		if((' ' == *(p+i)) || ('.' == *(p+i)))
		{
		//	num = 0;
			if(num > max)
			{
			max =num-1;
			a[0]= i-max;
			num=0;
			}
			num = 0;
		}
		if((' ' == *(p+i)) || ('.' == *(p+i)))
		{
			if(num == max)
			{
				count++;
				a[count-1]=i-max;
				a[count]='\0';
			}
		}

		if('.' == *(p+i))
		{
			printf("max:%d\n",max-1);
			*(p+i+1) = '\0';
			break;
		}
	}
//				printf("in--->max:%d\n",max);
	printf("long:");
	for(j=0;j<count;j++)
	{
	for(i=0;i<max;i++)
		{
			printf("%c",*(p+a[j]+i));
		}
	}
	printf("\n");
}

int main()
{
	char * p=NULL;
	int size=0;
	printf("please input strings length:");
	scanf("%d",&size);
	create_memory(&p,size);

	in_put(p, size);
//	puts(p);
	return 0;
}
