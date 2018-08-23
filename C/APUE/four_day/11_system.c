#include"../apue.h"
int main()
{
	printf("hi---\n");
	if(access("./a.out",F_OK)==0)//检测文件是否存在
	{
		system("./a.out");
	
	}
	printf("goodbye-----\n");
	return 0;

}
