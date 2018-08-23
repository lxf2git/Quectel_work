#include "../apue.h"
union{
	int int_ret;
	void *point_int;
}return_ret;

int main()
{
	int chdir_ret;
	char str_shell[100], cmd[500];
	memset(str_shell, 0, sizeof(str_shell));
	
	system("clear");
	while(1){
		if (!strcmp(getcwd(NULL, 0), "/")){
			sprintf(str_shell, "[%s@myshell %s]# ", 
					getenv("LOGNAME"), strrchr(getcwd(NULL, 0), '/'));
		}
		else{
			sprintf(str_shell, "[%s@myshell %s]# ", 
					getenv("LOGNAME"), strrchr(getcwd(NULL, 0), '/')+1);
		}

		printf("%s", str_shell);
		memset(cmd, 0, sizeof(cmd));
		scanf("%[^\n]", cmd);
		getchar();
		
		if (!strcmp(cmd, "exit")){
			break;
		}
		else if (!strcmp(cmd, "clear")){
			system("clear");
		}
		else if (strstr(cmd, "cd") != NULL){
			return_ret.int_ret = chdir(strchr(cmd, ' ')+1);
			if (return_ret.int_ret < 0){
				perror("chdir");
			}
		}
		else if (!strcmp(cmd, "pwd")){
			printf("%s\n", getcwd(NULL, 0));
		}
		else{
			printf("myshell: %s: command not found\n", cmd);
		}
	}
	return 0;
}
