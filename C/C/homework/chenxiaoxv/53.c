#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
	char *pname;
	int score;
}sStu,*pStu;

typedef struct Class
{
	sStu *stu_stu;
}sStuCla,*pStuCla;

typedef struct School
{
	sStuCla *stu_cla;
}sStuSch,*pStuSch;

void fan3(struct Student *p,int f)
{
	int i;
	for(i=0;i<f;i++)
	{
		p[i].pname=(char *)malloc(100*sizeof(char ));
	
		if(p[i].pname == NULL)
		{
			printf("error");
			exit(-1);
		}
	}
	for(i=0;i<f;i++)
	{	
		printf("input name score:\n");
		scanf("%s%d",p[i].pname,&p[i].score);
	}
}


int fan2(struct Class *p)
{
	int i,n;
	printf("班级人数:\n");
	scanf("%d",&n);
	p->stu_stu=(struct Student *)malloc(n*sizeof(struct Student));
	if(p->stu_stu==NULL)
	{
		printf("error");
		exit(-1);
	}
	for(i=0;i<n;i++)
	{
 	 	fan3(p[i].stu_stu,n);
	}
	return n;
}
int fan1(struct School *p)
{
	int i,m;
	printf("班级数:\n");
	scanf("%d",&m);
	p->stu_cla = (struct Class *)malloc(m*sizeof(struct Class));
	if(p->stu_cla==NULL)
	{
		printf("error");
		exit(-1);
	}
	for(i=0;i<m;i++)
	{
 	 	fan2(p[i].stu_cla);
	}
	
	return m;
}

void show(struct School *p,int i,int x,int v)
{
	int d,sum=0,r,h,k,g=0,f;
	float s=0.0,j=0.0,t;
	for(k=0;k<i;k++)
	{
		for(f=0;f<x;f++)
		{
			for(d=0;d<v;d++)
			{
				sum=sum+((p[i].stu_cla)->stu_stu)->score;
				s=sum/v;
				printf("学校:%d 班级:%d 平均成绩:%d",k,f,s);
			}
			g=g+sum;
		}
        j=g/x;
		printf("学校平均成绩:%d",j);
	}
}
/*void fang(struct *p)
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}*/

int main()
{	
	int k,f,i,w;
	int j,q,l,p;
	printf("学校个数:\n");
	scanf("%d",&q);
	struct School *a;
	a=(struct School *)malloc(q*sizeof(struct School));
	if(a==NULL)
	{
		printf("error");
		exit(-1);
	}
	for(w=0;w<q;w++)
	{
		
	for(i=1;i<q;i++)
	{
		l = fan1(a);
 		for(j=0;j<l;j++)
   		{
		     show(a,w,i,j);	
		}
	}	
	}
	for(k=0;k<q;k++)
	{
		for(f=0;f<l;f++)
		{
			for(i=0;i<j;i++)
			{
				if(a[k].stu_cla[f].stu_stu[i].pname!=NULL)
				{
					free(a[k].stu_cla[f].stu_stu[i].pname);
					a[k].stu_cla[f].stu_stu[i].pname=NULL;
				}
			if(fang(a[k].stu_cla[f].stu_stu[i])!=NULL)
			{
				free(a[k].stu_cla[f].stu_stu[i]);
				a[k].stu_cla[f].stu_stu[i]=NULL;
			}
	
			}
		if(fang(a[k].stu_cla[f])!=NULL)
		{
			free(a[k].stu_cla[f]);
			a[k].stu_cla[f]=NULL;	
		}

		}
	if(fang(a[k])!=NULL)
	{
	free(fang(a[k]));
	a=NULL;
		
	}
	}
	return 0;
}




