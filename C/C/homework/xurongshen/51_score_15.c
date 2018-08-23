#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

typedef struct Student
{
	char *name;
	int math;
	int chinese;
	int eng;
	float avg;
}sStu;

void create_memory(void **p,int size);
void add_memory(void **p,int size);
int judge(char ch);
void input(sStu * ptr,int num);
void sort(sStu *ptr, int num);
void putout(sStu *ptr, int num);
void putout2(sStu *pstr);
void free1(sStu *p, int num);

void create_memory(void **p,int size)
{
	*p = malloc(size);
	bzero(*p, size);
	if(NULL == *p)
	{
		printf("malloc error!!\n");
		exit(-1);
	}
}

void add_memory(void **p,int size)
{
	*p = realloc(*p, size);
	if(NULL == *p)
	{
		printf("realloc error!!\n");
		exit(-1);
	}
}

int judge(char ch)
{
	if('N'==ch || 'n'==ch)
	{
		return 0;
	}
}

void putout(sStu *pt, int num)
{
	int i,sum=0,total=0;
	printf("putout----sum----befor!\n");
	for(i=0;i<num;i++)
	{
			printf("pt[%d].name:%s",i+1,pt[i].name);
	printf("putout----sum----center!\n");
			printf("pt[%d].math:%d",i+1,pt[i].math);
			printf("pt[%d].chinese:%d",i+1,pt[i].chinese);
			printf("pt[%d].eng:%d",i+1,pt[i].eng);
		sum	= ((pt+i)->math+(pt+i)->chinese+(pt+i)->eng);
		(pt+i)->avg = sum/3;
		total = total+sum;	
	//	printf("avg%d:%f\n",i+1,(pt+i)->avg);
	}
	printf("putout----sum----after!\n");

	printf("putout--->>aaa!\n");
	for(i=0;i<num;i++)
	{
		if(pt[i].math+pt[i].chinese+pt[i].eng < (total/num)*0.3)
		{
	printf("name:%8s math:%5d chinese:%5d eng:%5d avg:%5d 不及格\n",
					pt[i].name,pt[i].math, pt[i].chinese, pt[i].eng, pt[i].avg);
		}
		else
		{
	printf("name:%8s math:%5d chinese:%5d eng:%5d avg:%5d 及格\n",
					pt[i].name,pt[i].math, pt[i].chinese, pt[i].eng, pt[i].avg);
		}
	}
}

void input(sStu ** ptr,int num)
{
	int i,len,count=1;
	char ch;
	printf("please input the size of name:(suggest:20)");
	scanf("%d",&len);

	create_memory((void **)ptr,count*sizeof(sStu));
	for(i=0;;i++)
	{
		add_memory((void **)ptr,count*sizeof(sStu));
		create_memory((void **)((ptr+i)->name),len);

		printf("please input NO.%d student name:\n",i);
		scanf("%s",*(ptr+i)->name);
		printf("please input NO.%d student math:\n",i);
		scanf("%d",&(*ptr+i)->math);
		printf("please input NO.%d student chinese:\n",i);
		scanf("%d",&(*ptr+i)->chinese);
		printf("please input NO.%d student English:\n",i);
		scanf("%d",&(*ptr+i)->eng);
//		printf("please input NO.%d student avg:\n",i);
//		scanf("%.2f",&(ptr+i)->avg);
		if(num == count)
		{
			printf("are you quit(yes or no):\n");
			getchar();
			scanf("%c",&ch);
			if(0 == judge(ch))
			{
				break;
			}
		}
		count ++;
	}

}

void sort(sStu *ptr, int num)
{
	int i,k,j;
	sStu sa,*pa;
	printf("sort--->aa!\n");

	for(i=0;i<num-1;i++)
	{
		k=i;
		for(j=i+1;j<num;j++)
		{
			if((ptr[i].avg)>(ptr[j].avg))
			{
				k=j;
			}
		}
	printf("sort--->bb!\n");
		if(k != j)
		{
	printf("sort--->change--->aa!\n");
			sa = *(ptr+i);
		//	pa = ptr[i];
	printf("sort--->change--->bb!\n");
			*(ptr+i) = *(ptr+k);
	printf("sort--->change--->cc!\n");
			*(ptr+k) = sa;
	printf("sort--->change--->dd!\n");
		}
	}

	printf("sort----->>cc\n");
	int n;
	printf("num:%d\n",num);
	n = num*70/100;
	printf("n:%d\n",n);
	for(i=0;i<=n;i++)
	{
		printf("name:%8s avg:%5d 及格\n",ptr[i].name,ptr[i].avg);
	}

	printf("sort----->>bb\n");
	for(i=n+1;i<num;i++)
	{
	printf("name:%8s math:%5d chinese:%5d eng:%5d avg:%5d 不及格\n",
					ptr[i].name,ptr[i].math, ptr[i].chinese, ptr[i].eng, ptr[i].avg);
	}
}


void free1(sStu *p, int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		free((p+i)->name);
	}
	free(p);
}

int main()
{
	int num;
	sStu *ptr=NULL;
	printf("please input number of student:");
	scanf("%d",&num);

	input(&ptr,num);
	printf("main---->aaa!\n");
//	sort(ptr,num);
	printf("main---->bbb!\n");
//	free1(ptr, num);
	putout(ptr,num);
	printf("main---->ccc!\n");
	return 0;
}
