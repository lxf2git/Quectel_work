
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
typedef struct student
{
		char * name;
		int age;
		char gender;
}*pStu;
void put_file(pStu p);
void disk(pStu p);
struct student *getmemory();
void input(pStu p);
void creatememory(void **p,int size);
void get_file(pStu p);
void output(pStu p);
int main()
{
		pStu p=NULL;
		p=getmemory();

		input(p);
		put_file(p);

		get_file(p);
		output(p);
		return 0;
		

}
void creatememory(void **p,int size)
{
		*p=malloc(size);
		if(*p==NULL)
		{
				printf("memroy error\n");
				exit(-1);
		}
}
struct student *getmemory()
{
		int i;
		pStu p=	NULL;
		creatememory((void**)&p,N*sizeof(struct student));
		for(i=0;i<N;i++,p++)
				creatememory((void **)&p->name,2);
		p-=	N;
		return p;
}
void input(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
		{
				printf("name age gender\n");
				scanf("%s%d",p->name,&p->age);
				getchar();
				scanf("%c",&p->gender);
		}



}
/*
void disk(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
				form( p);
}*/
void put_file(pStu p)
{
		int i;
		FILE *fp;
		fp=fopen("a","a");
		if(fp==NULL)
		{
				printf("file error \n");
				exit(-1);
		}
//		fseek(fp,0,SEEK_SET);
		for(i=0;i<N;i++)
				fwrite(p+i,1,sizeof(struct student),fp);
//		fwrite("\n",1,1,fp);
		fclose(fp);

}
void get_file(pStu p)
{
		int i;
		FILE *fp;
		fp=fopen("a","r");
		if(fp== NULL)
		{
				printf("file error\n");
				exit;
		}
		for(i=0;i<N;i++)
				fread(p+i,1,sizeof(struct student),fp);
		fclose(fp);

}
void output(pStu p)
{
		int i;
		for(i=0;i<N;i++,p++)
				if((i%2 == 0)||(i==10))
					printf("%s %d %c\n",p->name,p->age,p->gender);
}
