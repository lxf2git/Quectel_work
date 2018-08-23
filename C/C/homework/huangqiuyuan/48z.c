#include<stdio.h>
#include<stdlib.h>
int i;
void double_t(int *p)
{
	int print;
	print=*(p+i)*2;
	printf("%d ",print);
		if(print=='\0')
			exit(-1);
}
int main()
{

	int *p=NULL;
	printf("输入几个整数");
	for(i=0;;i++)
	{
		p=malloc(50*sizeof(int));
		scanf("%d",p+i);
			double_t(p);
			if(*(p+i)=='\n')
				break;
	}



return 0;

}
