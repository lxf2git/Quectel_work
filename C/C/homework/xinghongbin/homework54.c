#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *copefile1(char**argv,char  *p,int b);
void pastefile2(char* str,char **argv,char  *p,int b);
int dealfun(char **argv);
char *a;
int main(int arge,char**argv)
{
		char *str;
		int b=1;
		b=dealfun(argv);
		str=copefile1(argv,"r",b);
		pastefile2(str,argv,a,b);
		return 0;

}

int dealfun(char **argv)
{
		a=malloc(2);
		while(*++argv != NULL && **argv == '-')
		{
				switch(*++*argv)
				{
						case 'a':
								a="a";
								return 0;
								
								
						default:
								break;		
				}

		}
		a="w";
		return 1;
}
char *copefile1(char**argv,char  *p,int b)
{
		FILE *fp;
		long length;
		char *str=NULL;
		int a;
		
		
		fp=fopen(argv[2-b],p);
		if(fp == NULL )
		{
				printf("file error\n");
				exit(-1);
		}
		fseek(fp,0,SEEK_END);
		length=ftell(fp);
		str=malloc(length+1);
		rewind(fp);
		if(str==NULL)
		{
				printf("memory error\n");
				exit(-1);
		}
		
		fread(str,1,(int)length,fp);
		fclose(fp);
		return str;
}
void pastefile2(char* str,char **argv,char  *p,int b)
{
		FILE *fp;
		char change;
		fp=fopen(argv[3-b],"r");

		if(fp != NULL &&b==1)
		{
				printf("cp: overwrite `%s'? \n",argv[3-b]);
				scanf("%c",&change);
				if(change =='n')
						exit(-1);
		}
		
		fp=fopen(argv[3-b],p);
		if(fp == NULL)
		{
				printf("file error\n");
				exit(-1);
		}
		fwrite(str,1,strlen(str),fp);
		fclose(fp);
}
