#include"main.h"
int judge_fileORdir(int argc,char **argv)
{
	int flag=0;
	DIR * op_dir=NULL;
	if(argc!=3)
	{
		printf("Input error!\n");
		exit(-1);
	}
	op_dir=opendir(argv[1]);
	if(op_dir==NULL)
	{
		flag=-1;
	}
	else
		{flag=0;
		closedir(op_dir);
		}

	return flag;	
}
void get_prevDir_Addr(char *path)
{
	int i=0,j=0;
	int flag=0;
	char name[M];
	char prev_addr[M];
	memset(name,0,sizeof(name));
	while(path[i]!='\0')
	{
		if(path[i]=='/')
		{
			flag++;
			j=0;
			memset(name,0,sizeof(name));
			while(path[i]!='\0')
			{
				name[j]=path[i];
				j++;
				i++;
				if(path[i]=='/')
				{
					break;
				}
			}
			i--;
		}
		i++;
	}
	if(flag==0)
	{
		memset(path,0,sizeof(path));
		strcpy(path,"..");
	}
	else
	{	memset(prev_addr,0,sizeof(prev_addr));
		strncpy(prev_addr, path,strlen(path)-strlen(name));
		memset(path,0,sizeof(path));
		strcpy(path,prev_addr);
	}
}
