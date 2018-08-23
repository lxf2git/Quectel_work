#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
	char *name;
	int math;
	int yw;
	int english;

};
int tj(struct Student *p,int);
void show(struct Student *p,int,int);

int main()
{
	int i,allcj,n;
	printf("please input the number of student:");
	scanf("%d",&n);
	struct Student s[n];
	struct Student *p=s;
	for(i=0;i<n;i++)
	{
		(p+i)->name=(char *)malloc(20*sizeof(char));
		printf("please input student's name math(s) yw(s) english(s):");
		scanf("%s",(p+i)->name);
		getchar();
		scanf("%d%d%d",&(p+i)->math,&(p+i)->yw,&(p+i)->english);
	}
	allcj=tj(p,n);
	show(p,allcj,n);	

}

int tj(struct Student *p,int n)
{
	int i,a,b,c,d;
	int mathcj,ywcj,englishcj,allcj;
	for(i=0;i<n;i++)
	{
		a+=(p+i)->math;
		b+=(p+i)->yw;
		c+=(p+i)->english;
	}
	allcj=(a+b+c)/n;
	return allcj;
}

void show(struct Student *p,int allcj,int n)
{
	int i;
	int j[n];
	for(i=0;i<n;i++)
	{
		j[i]=(p+i)->math+(p+i)->yw+(p+i)->english;
		if(j[i]*10/allcj<=3)
		{
			printf("name:%s,math:%d,yw:%d,english:%d\n",(p+i)->name,(p+i)->math,(p+i)->yw,(p+i)->english);

		}
	}
	


}
