#include<stdio.h>
#include<stdlib.h>
void kongjian(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}
void min_2(int  **p,int x,int y)
{
	int min_1,min_2=p[0][0],i,j,m=0,n=0;
	for(i=0;i<x;i++)
			for(j=0;j<y;j++){
				if(p[i][j]<p[m][n]){
				m=i;
				n=j;
				}
			}
	p[m][n]=-1;
	for(i=0;i<x;i++)
			for(j=0;j<y;j++){
					if(min_2>p[i][j]&&p[i][j]!=-1)
							min_2=p[i][j];
			}
	printf("输入的数组中第二小的数为:%d\n",min_2);

}
int main()
{
	int **p=NULL;
	int i,j,x,y;
	printf("请输入行列数，逗号隔开:\n");
	scanf("%d,%d",&x,&y);
	kongjian((void **)&p,x*sizeof(int*));
	for(i=0;i<x;i++)
			kongjian((void **)p+i,y*sizeof(int));
	printf("请输入一个二维数组:\n");
	for(i=0;i<x;i++)
			for(j=0;j<y;j++)
					scanf("%d",*(p+i)+j);
	min_2(p,x,y);
	return 0; 
}
