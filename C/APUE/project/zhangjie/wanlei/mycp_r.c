#include"../apue.h"

#define N 1

int copy_r(char *src, char *dest);
void newdest(char *dest, char *src);
int copy_file(char *src, char *dest, struct stat buf);

int main(int argc, char **argv)
{
	if(3 != argc)
	{
		printf("%s file name\n",argv[0]);
		return -1;
	}
	int ret=0;
	if('/' != argv[2][0])
	{
		ret = mkdir(argv[2],0777);
	}
	newdest(argv[2],argv[1]);
	ret = mkdir(argv[2], 0777);
	copy_r(argv[1], argv[2]);
	return 0;
}

int copy_r(char *src, char *dest)
{
	int ret = 0;
	DIR *pdir = NULL;
	struct dirent *pdirent = NULL;
	struct stat buf;
	char file_name[1024];
	char dir_name[1024];
	memset(file_name, 0, sizeof(file_name));
	memset(dir_name, 0, sizeof(dir_name));
	strcpy(file_name, dest);
	strcpy(dir_name, dest);
	
	pdir = opendir(src);
	if(NULL == pdir)
	{
		perror("opendir");
		goto ERR;
	}
	ret = chdir(src);
	if(ret < 0)
	{
		perror("chdir");
		goto ERR;
	}

	while(1)
	{
		pdirent = readdir(pdir);
		if(NULL == pdirent)
		{
			break;
		}
	//	printf("%s ",pdirent->d_name);
		ret = lstat(pdirent->d_name, &buf);
		if(-1 == ret)
		{
			perror("lstat");
			goto ERR;
		}
		if(0 == strcmp(pdirent->d_name,".") ||
			0 == strcmp(pdirent->d_name,".."))
		{
			continue;
		}
		if(S_ISDIR(buf.st_mode))
		{
			strcat(dir_name, "/");
			strcat(dir_name,pdirent->d_name);
			ret = mkdir(dir_name, buf.st_mode);
		//	printf("%s ",pdirent->d_name);
			copy_r(pdirent->d_name,dir_name);
			ret = chdir("..");
			if(ret < 0 )
			{
				perror("chdir");
				goto ERR;
			}
		}
		else
		{
			strcat(file_name, "/");
			strcat(file_name, pdirent->d_name);
			copy_file(pdirent->d_name, file_name, buf);
		}
		memset(dir_name, 0, sizeof(dir_name));
		memset(file_name, 0, sizeof(file_name));
		strcpy(dir_name, dest);
		strcpy(file_name, dest);
	}
	closedir(pdir);
	return 0;
ERR :
	closedir(pdir);
	return -1;
}

void newdest(char *dest, char *src)
{
	int l=strlen(src);
	if('/' == src[l-1])
	{
		l=l-1;
	}
	char str[256];
	int j=0,i;
	char tmp;
	memset(str, 0, sizeof(str));
	for(i=l-1;i>=0;i--)
	{
		if('/' == src[i])
		{
			break;
		}
		
		str[j]=src[i];
		j++;
	}
	l=strlen(str);
	for(i=0;i<l/2;i++)
	{
		tmp = str[i];
		str[i]=str[l-i-1];
		str[l-i-1]=tmp;
	}
	strcat(dest,"/");
	strcat(dest,str);
}

int copy_file(char *src, char *dest, struct stat buf)
{
	int fid_src,fid_dest;
	fid_src = open(src, O_RDONLY);
	if(fid_src < 0)
	{
		perror("open");
		return -1;
	}
	fid_dest = open(dest, O_CREAT|O_EXCL|O_WRONLY ,buf.st_mode);
	if(fid_src < 0)
	{
		if(EEXIST == errno)
		{
			printf("overwrite `%s'",dest);
			char ch;
			scanf("%c",ch);
			if('y' != ch || 'Y' != ch)
			{
				return 0;
			}
			fid_dest = open(dest, O_WRONLY);
		}
		else
		{
			goto ERR;
		}
	}
	char str[1024*N];
	int ret;
	memset(str, 0, sizeof(str));
	while(1)
	{
		ret = read(fid_src, str, 1024*N);
		if(0 == ret)
		{
			break;
		}
		write(fid_dest, str, ret);
		memset(str, 0, sizeof(str));
	}
ERR:
	close(fid_src);
	close(fid_dest);
	return -1;
}
