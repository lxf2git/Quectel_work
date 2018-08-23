#include"../apue.h"
#define N 10
int charNum;
int con;
int stop;
void sig_fun(int sig);
void get_orgstr(char *orgStr);

int main()
{
//	atexit(_lush());
	ssize_t ret;
	char orgStr[N+2] = {};
	int i,pid;
	char inCh;
	signal(SIGALRM,sig_fun);
	alarm(12);
		for(;;)
		{
			get_orgstr(orgStr);
			printf("原句子: %s\n",orgStr);
			printf("请输入: ");
			fflush(NULL);
			//printf("wait2\n");
			system("stty raw");
			for(i=0;i<N;i++)
			{
				scanf("%c",&inCh);
//				fflush(NULL);
				if(inCh == 10)
				{
					break;
				}
				if(inCh == orgStr[i])
				{
					charNum++;
				}
			}
			system("stty cooked");
			printf("\n");	
		}

	return 0;
}
void get_orgstr(char *orgStr)
{
	int i;
	bzero(orgStr,N+1);
	srand(time(NULL));
	for(i=0;i<N;i++)
	{		
		orgStr[i] = rand()%26+97;
//		printf("%d\n",orgStr[i]);
	}
}

void sig_fun(int sig)
{
	switch(sig)
	{
		case SIGALRM:
				{
					system("stty cooked");
					printf("\n输入正确字符数:%d\n",charNum);
					exit(0);
					break;
				}
		default:break;
	}
}
