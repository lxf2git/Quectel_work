#include"../../apue.h"

typedef struct
{
	char name[20];
	int age;
	double weight;
}Person;
int main()
{
	int fd;	
	mkfifo("pipe",0644);
	fd = open("pipe",O_WRONLY);	
	puts("打开成功");
	printf("please input name,age,weight\n");
	Person x;
	scanf("%s%d%lf",x.name,&x.age,&x.weight);
	write(fd,&x,sizeof(x));
	close(fd);
	return 0;
}

