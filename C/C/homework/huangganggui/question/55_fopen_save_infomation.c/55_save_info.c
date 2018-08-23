#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

typedef struct Stu
{
    int id;
    char *pname;
    char gender;
    int age;
    
}sStu;

void create_pname(sStu *s);
void create_memory(void **p,int n);
void input(sStu *s);
void op_write_file(sStu *s);
void free_memory(void **p);
void op_read_file(void);
void output(sStu *s,int n);

int main()
{
    int i;
    sStu *s = NULL;
    create_memory((void **)&s,N*sizeof(sStu));

    for(i = 0; i < N; i++)
    {
        create_memory((void**)&s[i].pname, 20*sizeof(char));
    }

    input(s);
    op_write_file(s);
    
    for(i = 0; i < N; i++)
    {
        free_memory((void **)&s[i].pname);
    }
    free_memory((void **)&s);
    op_read_file();

    return 0;
}

void create_pname(sStu *s)
{
    int i;
    for(i = 0; i < N; i++)
    {
        create_memory((void **)&s[i].pname,20*sizeof(char));
    }
}

void create_memory(void **p,int n)
{
    *p = (void *)malloc(n);
    if(NULL == *p )
    {
        printf("Malloc Error!\n");
        exit(-1);
    }
}

void input(sStu *s)
{
    int i;

    for(i = 0; i < N; i++)
    {
        printf("input id name gender age\n");
        scanf("%d%s", &s[i].id, s[i].pname);
        getchar();
        scanf("%c%d", &s[i].gender, &s[i].age);

    }
}

void op_write_file(sStu *s)
{
    FILE *fp = NULL;
    int i = 0;
    fp = fopen("student_info","w");
    if(NULL == fp)
    {
        printf("Fopen Error!\n");
        exit(-1);
    }
    fwrite(s,sizeof(sStu), N, fp);

    for(i = 0; i < N; i++)
    {
        fwrite(s[i].pname, 20, 1, fp);
    }
    fclose(fp);
    
}

void free_memory(void **p)
{
    if(*p != NULL)
    {
        free(*p);
        *p = NULL;  
    }
}
 void op_read_file(void)
 {
    FILE *fp = NULL;
    int n,i;

    fp = fopen("student_info","a+");
    if(NULL == fp)
    {
        printf("Fopen Error\n");
        exit(-1);
    }
    n = ftell(fp);
    sStu *s ;
    create_memory((void **)&s,N*sizeof(sStu));
    for(i = 0; i < N; i++)
    {
    
        create_memory((void**)&s[i].pname, 20*sizeof(char));

    }

    
    
    fread(s,sizeof(sStu), N, fp);
    for(i = 0; i < N; i++)
    {
        fread(s[i].pname, 20, 1, fp);
    }
    
    
    fclose(fp);

    output(s,N);
    for(i = 0; i < N; i++)
    {
        free_memory((void **)&s[i].pname);
    }
    free_memory((void **)&s);

 }

 void output(sStu *s,int n)
 {
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nID:%d\n",s[i].id);
        printf("Name:%s\n",s[i].pname);
        printf("Gender:%c\n",s[i].gender);
        printf("Age:%d\n",s[i].age);
    }
 }
