#include"../apue.h"

int main()
{
		puts("************************");
		char cmd[256];
		char shall[100];
		char pathName[100]=" ~";
		char *ppath = pathName;
		char before_path[100];
		memset(before_path,0,sizeof(before_path));
		memset(cmd,0,sizeof(cmd));
		memset(shall,0,sizeof(shall));

		strcpy(shall,"[");
		strcat(shall,getenv("USERNAME"));
		strcat(shall,"@");
		strcat(shall,getenv("HOSTNAME"));

		for(;;)
		{
				printf("%s ",shall);
				printf("%s",ppath+1);
				printf("]");
				if(strcmp(getenv("USERNAME"),"root")==0)
				{
						printf("# ");
				}
				else
				{
						printf("$ ");
				}

				gets(cmd);
				if(!strcmp(cmd,"baibai"))
				{
					break;
				}
				if(strncmp(cmd,"cd",2)==0)
				{
						if(strncmp(cmd,"cd /",3)==0)
						{
								if(strncmp(cmd+3,"-",1)==0)
								{
										chdir(before_path);
										strcpy(before_path,pathName);
										memset(pathName,0,sizeof(pathName));
										getcwd(pathName,sizeof(pathName));
										ppath = strrchr(pathName,'/');
										memset(cmd,0,sizeof(cmd));
								}
								else
										if(strncmp(cmd+3,"..",2)==0)
										{
												strcpy(before_path,pathName);
												chdir("..");
												getcwd(pathName,sizeof(pathName));
												ppath = strrchr(pathName,'/');
												memset(cmd,0,sizeof(cmd));
										}
										else
										{
												chdir(cmd+3);
												strcpy(before_path,pathName);
												memset(pathName,0,sizeof(pathName));
												getcwd(pathName,sizeof(pathName));
												ppath = strrchr(pathName,'/');
												memset(cmd,0,sizeof(cmd));
										}
						}
						else
						{
								printf("xxxxxxxx\n");
								chdir("/");
								strcpy(before_path,pathName);
								memset(pathName,0,sizeof(pathName));
								getcwd(pathName,sizeof(pathName));
								ppath = " /";
								memset(cmd,0,sizeof(cmd));

						}

				}
				else
					if(strchr(cmd,'=')!=NULL)
					{
							int i=0;
							int j=0;
							char buf[100];
							char buf2[100];
							memset(buf,0,sizeof(buf));
							memset(buf2,0,sizeof(buf2));
							while(cmp[i]!='=')
							{
									buf[i]=cmp[i];
									i++;
							}
							while(cmp[i]!='\n')
							{
									buf1[j]=cmp[i];

							}


					}
				else
				{
						system(cmd);
				}
		}
		puts("thank you for using my shell.");
}
