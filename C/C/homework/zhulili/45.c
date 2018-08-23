#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create_memory(char **q,int size)
{
		*q = (char *)malloc(size);
		if(NULL==*q)
		{
			printf("malloc error");
			exit(-1);
		}
}

int main()
{
		char *p;
		char *po;
		int size;
		int i,j,n,m;
		int k=0;
		int a[50];
		printf("请输入空间大小：\n");
		scanf("%d",&size);
		create_memory(&p,size);
		create_memory(&po,size);
		printf("请输入字符串：\n");
		scanf("%s",p);
		n = strlen(p);
		for(i=0;i<n;i++)
		{
			do{
				if(*(p+k)=='#')
				{
					for(;;)
					{
						k++;
						if(*(p+k)=='#')
						{
							k++;
							break;
						}
						if(k>n)
							break;
					}
				}	
				
			}while(*(p+k)=='#');
		*(po+i) = *(p+k);
		k++;
		}
		printf("ssss:%s ",po);
		return 0;
}
