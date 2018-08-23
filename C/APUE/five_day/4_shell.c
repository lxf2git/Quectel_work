#include"../apue.h"


int main()
{
	puts("welcome to my shell");
	char cmd[256];
	for(;;)
	{
		printf("my#");//提示
		scanf("%[^\n]",cmd)//
		if(!strcmp(cmd,"furong"))
		{
			break;
		}
		if(strncmp(cmd,"cd",3)==0)//  cd hello
		{
			chdir(cmd+3);
			getcwd
		}
		else if()//cmd  strchr  判断是否需要设置环境变量
				//1 =   2 isvar()
		{
		
		}
		else
		{
			system(cmd);
		
		}

	}

	puts("thank you for using my shell");
}










