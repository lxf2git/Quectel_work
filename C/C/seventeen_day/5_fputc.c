#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
 *char *fgets(char *s, int size, FILE *stream);
s:读出来的内容存放的位置
size:最多读多大
stream:文件流指针
注意：读出1行后会自动加上'\0' 所以：每次读出的最大长度：size-1

int fputs(const char *s, FILE *stream);
功能：向文件中写一行
s:要写的内容
stream：文件流指针
 注意：写一行时 不包括字符串结束符'\0'

 int fgetc(FILE *stream);
 int feof(FILE *stream);
int fputc(int c, FILE *stream);


 * */
int main()
{
	int ch = 97;	
	FILE *fp = fopen("b.txt","a");	
	if(NULL==fp)
	{
		printf("fopen error");
		exit(-1);
	}
	

	fputc(ch,fp);
	fclose(fp);
	return 0;

}
