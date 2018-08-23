#include"stack.h"
void swap(int *flag,int *tmpd)
{
		int	tmp;
		tmp = *flag;
		*flag = *tmpd;
		*tmpd = tmp;
}
int sort(int *parr,int low,int high)
{
		int *p = &parr[low];
		int flag;
		int a=0;
		flag = parr[low];
		while(low!=high)
		{
				if(a==0)
				{
						
						if(flag>parr[high])
						{
								swap(p,&parr[high]);
								p = &parr[high];
								low++;
								a = 1;
						}
						else
						{
								high--;
						}
				}
				else
				{
						if(flag<parr[low])
						{
								swap(p,&parr[low]);
								p = &parr[low];
								high--;
								a = 0;
						}
						else
						{
						low++;
						}
				}
		}
	  	return high;
}
#if 0
void quick_sort(int *parr,int low,int high)//当最高位和最低位相等时退出；
{
		int ret;
		ret = sort(parr,low,high);//调用函数
		if(ret+1<high)//当返回值小于最高位，结束条件是返回值等于高位；
		{
		  quick_sort(parr,ret+1,high);//往右走
		}
		if(low<ret-1)//当返回值大于最高位，结束条件是返回值等于低位；
		{
		  printf("low:%d\n",low);
		  quick_sort(parr,low,ret-1);//往左走
		}
}
#endif
#if 1
void quick_sort(int *parr,int low,int high)
{
		int ret;
		int re_back;
		push(skt,low);
		ret = sort(parr,low,high);
	//	push(skt,ret);
		while(skt->bottom[skt->top]==0)
		{
				while(ret+1<high)
				{
						push(skt,ret);
						ret = sort(parr,ret+1,high);
				}
				re_back = ret; 
				while(low<ret-1)
				{
						printf("back:%d \n",re_back);
					//	ret = sort(parr,low,re_back-1);
						printf("ret:%d\n",ret);
						ret = sort(parr,low,re_back-1);
					//	printf("arr[%d]:%d\n",parr[re_back-1],re_back-1);
						pop(skt,&re_back);
				}
		}
}
#endif
int init_room(int **arr)
{
		int count,i;
		printf("请输入需要输入的数据个数\n");
		scanf("%d",&count);
		get_memory((void **)arr,count*sizeof(int));
		printf("请输入数据\n");
		for(i=0;i<count;i++)
		{
				scanf("%d",(*arr)+i);
		}
		return count;
}
void print(int *arr,int count)
{
		int i;
		for(i=0;i<count;i++)
		{
				printf("%d ",arr[i]);
		}
		printf("\n");
}
int main()
{
		int count=0;
		int *arr=NULL;
		get_memory((void **)&skt,sizeof(sStack));
		get_memory((void **)&skt->bottom,SIZE*sizeof(int));
		skt->top = 0;
		count = init_room(&arr);
		quick_sort(arr,0,count-1);
		print(arr,count);
		return 0;
}
