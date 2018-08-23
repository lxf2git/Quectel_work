#include"apue.h"

int main(int argc,char **argv)
{
		if(argc!=2&&argc!=3)
		{
				printf("%s [pathname] \"which\"\n",argv[0]);
				return -1;
		}

		int fd[2];
		char arr[50]={0};
		pid_t pid;
		set_err(pipe(fd),"pipe");
		set_err(pid=fork(),"fork");
		if(pid==0)
		{
			close(fd[1]);
			char *p;
			int i,j,flag;
			
			if(argc==2)
				p=argv[1];
			else
				p=argv[2];
			
			while(1)
			{
					set_err(read(fd[0],arr,sizeof(arr)),"read");
					for(i=0,flag=1;(p[i]!='\0')&&flag;i++)
					{
							for(j=0,flag=0;arr[j]!='\0';j++)
							if(p[i]==arr[j])
							flag=1;
					}
					
					if(flag==1)
					printf("%s\n",arr);
					bzero(arr,sizeof(arr));
			}
		}
		else
		{
				close(fd[0]);
				struct dirent *pdirent = NULL;
				char brr[50]="./";
			
				if(argc==3)
				strcpy(brr,argv[1]);
			
				DIR *pdir = opendir(brr);
				if(pdir!=NULL)
				{
					chdir(brr);
					while((pdirent=readdir(pdir))!=NULL)
					{
							if(pdirent->d_name[0]!='.')
							{								
								strcpy(arr,pdirent->d_name);
								set_err(write(fd[1],arr,strlen(arr)),"write");
								usleep(500);
							}
					}
				}
				else
				{
					strcpy(arr,strrchr(argv[1],'/')+1);
					set_err(write(fd[1],arr,strlen(arr)),"write");
					usleep(500);
				}
			
				kill(pid,SIGKILL);
		}
		return 0;
}
