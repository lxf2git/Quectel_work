#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct People
{
	char *name;
	int age;
};
void show(struct People *p,int  n);

int main()
{
	int i,n;
	printf("please input the number of people:\n");
	scanf("%d",&n);
	struct People arr[n];	
	struct People *p=arr;
	for(i=0;i<n;i++)
	{
		(p+i)->name=(char *)malloc(20*sizeof(char));
		printf("please input name age:\n");
		scanf("%s",(p+i)->name);
		getchar();
		scanf("%d",&(p+i)->age); 
	}
	show(p,n);
}

void show(struct People *p,int n)
{
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if((p+j)->age<(p+i)->age)
		{
			j=i;
			
		}

	}
	printf("name:%s,age:%d\n",(p+j)->name,(p+j)->age);

}
