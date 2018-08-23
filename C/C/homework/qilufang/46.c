#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
void change(char *prt_1,int m,int len);
/*********开空间函数*************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_ERROR!\n");
		exit(-1);
	}	
}
/*********主函数*******************/
int main()
{
	int nb=0,len=0;
	char *ptr;
	puts("input a string:");
	getmemory((void **)&ptr,N*sizeof(char)); //为字符串开空间
	gets(ptr);
	len=strlen(ptr);
	printf("输入将字符串后移的位数：\n");
	scanf("%d",&nb);
	change(ptr,nb,len);
	printf("%s\n",ptr);
	if(ptr!=NULL)							//清空间
	{
		free(ptr);
		ptr=NULL;
	}
	return 0;

}
/************调换函数**************************/
void change(char *ptr_1,int m,int len)
{
	char *ptr_2=NULL;
	int j=0,i,k,n;
	getmemory((void **)&ptr_2,(m+1)*sizeof(char));
	for(i=len-m;i<len;i++)
	{
		*(ptr_2+j)=*(ptr_1+i);        //将ptr——1的后m位赋值给ptr——2
		j++;
	}
	for(n=N-1;n>=0&&*(ptr_1+n) != '0';n--)				//将ptr——1后移m位
	{
		*(ptr_1+m+n)=*(ptr_1+n);
	}
	for(k=0;k<m;k++)				//ptr——2赋值给ptr——1的前m位
	{
		*(ptr_1+k)=*(ptr_2+k);
	}
	bzero(ptr_1+len,m);				//将ptr——1的后m位清零
	free(ptr_2);
}
