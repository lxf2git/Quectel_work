#include<stdio.h>
#include<string.h>
#define N 100
#define M 500
char reorder(char arr[])
{
	char m;
	int i,j,x;
	printf("请输入字符串:");
	gets(arr);
	x=strlen(arr);
	for(i=0;i<x;i++)
		for(j=0;j<x-1;j++)
		if(arr[j]>arr[j+1]){
			m=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=m;
	}
	return arr[N];
}


char reorder1(char arr[])
{
	char m;
	int i,j,x;
	x=strlen(arr);
	for(i=0;i<x;i++)
		for(j=0;j<x-1;j++)
		if(arr[j]>arr[j+1]){
			m=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=m;
	}
	return arr[N];
}

#if 0 
char combine(char a[],char b[])
{
	strcat(a,b);
	return a[M];
}

#endif
#if 0
char clean(char c[])
{
	int i,j;
	char d[M];
	for(i=0;i<M;i++)
		for(j=0;j<M;j++){
			if(c[i]!=c[j])
				d[j]=c[i];
		}
	return d[M];
}
#endif
char clean(char a[])
{
	int i,j,x,k;
	x=strlen(a);
	for(i=0;i<x;i++)
		for(j=0;j<x;j++)
			if(a[j]==a[j+1]){
					for(k=j;k<x;k++)
						a[k]=a[k+1];
			}
	
		return a[M];
}


int main()
{
	char a[M],b[N];
	a[M]=reorder(a);
	printf("排序后字符串a:%s\n",a);
	b[N]=reorder(b);
	printf("排序后字符串b;%s\n",b);
	//c[M]=combine(a,b);
	strcat(a,b);
	a[M]=reorder1(a);
	printf("合并排序后字符串c:%s\n",a);
	a[M]=clean(a);
	printf("去掉重复字符后字符串c:%s\n",a);
	return 0;
}
