#include"../apue.h"
int main()
{
	putenv("USER4=u5");

	char *str = getenv("USER4");
	if(NULL==str)
	{
		show_err("getenv");
	}
	printf("%s",str);	
	//system("echo $USER");	
	return 0;

}
