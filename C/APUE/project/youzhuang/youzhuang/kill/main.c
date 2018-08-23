#include"main.h"

int main(int argc, char **argv)
{
		int pid,signal;
		pid=atoi(argv[2]);
		signal=atoi(argv[1]+1);
		kill(pid,signal);
		return 0;
}
