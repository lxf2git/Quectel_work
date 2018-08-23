//  ./exe /root/1.c

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("%s file_name\n",argv[0]);
		exit(-1);
	}	

	//打开文件
	FILE *fp = fopen(argv[1],"r");
	if(NULL==fp)
	{
		printf("fopen err\n");
	}
/*
	//循环读取每个字符
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	printf("**%d**",ch);
	*/
	long file_len;
	char ch;
	fseek(fp,0,SEEK_END);//morning
	fseek(fp,-1,SEEK_END);
	ch = fgetc(fp);
	printf("==%d==\n",ch);
	file_len = ftell(fp);
	printf("%ld",file_len);
	return 0;

}
