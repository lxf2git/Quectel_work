#include"../apue.h"
//  ./client file_name pid
int main()
{
	if(argc!=3)
	{
		show_err("argc");
	}
	//发送文件名
	while(1)
	{
		sigqueue(pid,signo,&value);
	}
	//等待 接收文件内容或者出错信息 输出到屏幕
}
