#include"../../apue.h"
typedef struct
{
	char name[20];
	int age;
	double weight;
}Person;

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		show_err("argc");
	}
	Person x;	
	int fd;
	fd = open(argv[1],O_RDONLY);	
	if(fd<0)
	{
		show_err("open");
	}
#if 0
	if(read(fd,&x,sizeof(x))!=sizeof(x))
	{
		show_err("read");
	}

	printf("read:%d %s %lf\n",x.age,x.name,x.weight);
	close(fd);
	unlink("pipe");
#endif
	return 0;

}

