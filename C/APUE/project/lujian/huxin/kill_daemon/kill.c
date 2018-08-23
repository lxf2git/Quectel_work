#include"apue.h"

int main(int argc,char** argv)
{
		if(argc != 3)
		{
				printf("%s -sig pid \n",argv[0]);
				return -1;
		}
		pid_t pid;
		int sig = 0;
		char *pidp;
		char buf[10];
		memset(buf,0,sizeof(buf));
		pidp = strrchr(argv[1],'-');
		if(pidp != NULL)
		{
				sig = atoi((pidp+1));
		}
		else
		{
				if(strcmp(argv[1],"SIGHUP")==0)
				{
						sig = 1;
				}
				else
						if(strcmp(argv[1],"SIGINT")==0)
						{
								sig = 2;
						}
						else
								if(strcmp(argv[1],"SIGQUIT")==0)
								{
										sig = 3;
								}
								else
										if(strcmp(argv[1],"SIGILL")==0)
										{
												sig = 4;
										}
										else
												if(strcmp(argv[1],"SIGABRT")==0)
												{
														sig = 6;
												}
												else
														if(strcmp(argv[1],"SIGFPE")==0)
														{
																sig = 8;
														}
														else
																if(strcmp(argv[1],"SIGKILL")==0)
																{
																		sig = 9;
																}
																else
																		if(strcmp(argv[1],"SIGUSR1")==0)
																		{
																				sig = 10;
																		}
																		else
																				if(strcmp(argv[1],"SIGSEGV")==0)
																				{
																						sig = 11;
																				}
																				else
																						if(strcmp(argv[1],"SIGPIPE")==0)
																						{
																								sig = 13;
																						}
																						else
																								if(strcmp(argv[1],"SIGALRM")==0)
																								{
																										sig = 14;
																								}
																								else
																										if(strcmp(argv[1],"SIGTERM")==0)
																										{
																												sig = 15;
																										}
																										else
																										{
																												printf("input error \n");
																												exit(-1);
																										}
		}
		pid = atoi(argv[2]);
		kill(pid,sig);
}
