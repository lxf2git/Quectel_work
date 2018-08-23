#include "../apue.h"
//ls -lix file/dir
//:表示选项后有参数 optarg:存放选项参数
int main(int argc, char **argv)
{
	int ret;
	char file_flage[4];

	memset(file_flage, 0, sizeof(file_flage));

	while(1)
	{
		ret=getopt(argc, argv, "lai");
		if(ret==-1)
		{
				printf("nothing.\n");
				printf("arg=%s\n", argv[optind]);
				break;
		}
		printf("ret=%c\n", ret);
		switch(ret)
		{
				case 'l':
				{
						//显示所有属性
						printf("all attr. arg=%s\n", optarg);
						strcat(file_flage, "l");
						break;
				}
				case 'a':
				{
						//显示隐藏文件
						printf("show hide file. arg=%s\n", optarg);
						strcat(file_flage, "a");
						break;
				}
				case 'i':
				{
						printf("show file inode.\n");
						strcat(file_flage, "i");
						break;
				}
				case '?':
				{
					printf("err.\n");
					break;
				}
				default:
				{
						printf("default.\n");
						break;
				}

		}
		//判断file_flage->l i 
		//show_all_attr();
		//show_inode();
		//show_all_file();

		//show_file_name;
		//ls -lia file
		//optind:argv下一个参数的下标
		printf("arg=%s\n", argv[optind]);

	}
}








