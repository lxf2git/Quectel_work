#include<stdio.h>
#include<stdlib.h>
#define R 2
#define C 3
void arr_max_output(int **p);
void arr_input(int **p);
void creat_memory(void **p,int size);
void arr_free(void **p);
int main()
{
		int i,j;
		int **p=NULL;
		creat_memory((void **)&p,R);
		for(i=0;i<R;i++)
				creat_memory((void **)p+i,C);
		arr_input(p);
		arr_max_output(p);
		for(i=0;i<R;i++)
				arr_free((void **)p+i);
		arr_free((void **)&p);
		printf("free over\n");
		return 0;

}
void creat_memory(void **p,int size)
{
		*p=malloc(size*sizeof(int));
		if(*p==NULL)
				printf("error\n");
}

void arr_input(int **p)
{
		int i,j;
		for(i=0;i<R;i++)
				for(j=0;j<C;j++)
						scanf("%d",*(p+i)+j);

}

void arr_max_output(int **p)
{
		int i,j;
		int min;
		for(i=0;i<R;i++)
				for(j=0;j<C;j++)
						if(**p>*(*(p+i)+j))
								**p=*(*(p+i)+j);
		for(i=0;i<R;i++)
				for(j=0;j<C;j++)
						if(i>0||j>0)
							if(*(*p+1)>*(*(p+i)+j))
									*(*p+1)=*(*(p+i)+j);

		printf("min:%d\n",*(*p+1));

}
void arr_free(void **p)
{
		free(*p);
		*p=NULL;

}
