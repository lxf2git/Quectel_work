#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void creat_memory(void **p,int size)
{
		*p=malloc(size);
}

int main()
{
		char *a;
		char *b;
		int flag;
		int n;
		printf("输入字符串长度\n");
		scanf("%d",&n);
		creat_memory((void **)&a,n*sizeof(char));
		//printf("%p",a);
		printf("输入字符串a\n");
		getchar();
		gets(a);
		creat_memory((void **)&b,n*sizeof(char));
		printf("输入字符串b\n");
		gets(b);
		printf("输入标志\n");
		scanf("%d",&flag);
		switch(flag)
		{
				case 0:
				strcat(a,b);
				printf("%s\n",a);
				break;

				case 1:
				strcat(b,a);
				printf("%s\n",b);
				break;
				
				default:
				a=NULL;
				printf("%p\n",a);
				break;

		}
		free(a);
		free(b);
		return 0;

}

