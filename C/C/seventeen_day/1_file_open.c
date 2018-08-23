#include<stdio.h>
#include<string.h>

//文件操作:字节流或者二进制流
/*打开文件---读写操作---关闭
 *#include <stdio.h>
FILE *fopen(const char *path, const char *mode);
path:打开文件的路径（相对/绝对）
mode：
	w+:以读写的方式打开 会清空打开的文件 如果文件文件不存在 则创建该文件
	w:以写方式打开  会清空打开文件 如果文件不存在 则创建该文件
	r:以读的方式打开 文件必须存在
	r+：以读写方式打开 文件必须存在
	a：以追加方式打开 如果文件不存在则创建
	a+：以读和追加方式打开 如果文件不存在 则创建

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
ptr:从stream读出的内容 存放的位置
size:每次读多大
nmemb:读多少次
stream:从哪个文件流读
返回值：成功读的次数

size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);

ptr:要写入stream的内容 存放的位置
size:每次写多大
nmemb:写多少次
stream:往哪个文件流写
返回值：成功写的次数

int fclose(FILE *fp);
fp:要关闭的文件流指针 

void rewind(FILE *stream); 
功能:把文件指针移到文件开始 

int fseek(FILE *stream, long offset, int whence)
stream:流文件指针
offset:相对于whence的偏移量
whence:
SEEK_SET:文件开始
SEEK_CUR:当前位置
SEEK_END:文件末尾

long ftell(FILE *stream);
功能：返回当前文件的读写位置
 */
int main()
{
	char ptr[20] = "mygod";	
	char buf[20]={};
	FILE * fp;
	long l;
	size_t n,m;	
	fp  = fopen("b.txt","w+");	
	if(NULL==fp)
	{
		printf("fopen error\n");
		exit(-1);
	}
	
	n = fwrite(ptr,1,strlen(ptr),fp);
	printf("n:%u\n",n);
/*
	fclose(fp);
	fp  = fopen("b.txt","r+");	
	*/
	// 1、rewind(fp);
	
/*	2、
	fseek(fp,-1,SEEK_END);//d
	fseek(fp,-3,SEEK_CUR);
	3、fseek(fp,0,SEEK_SET);
	*/
	l = ftell(fp);
	printf("l:%ld\n",l);
	fseek(fp,-l,SEEK_CUR);
	//mygod
	m = fread(buf,strlen(ptr),1,fp);
	printf("buf:%s\n",buf);
	return 0;

}
