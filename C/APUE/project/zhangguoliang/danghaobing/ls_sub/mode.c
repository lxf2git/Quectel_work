#include"mode.h"
void get_mode(struct stat Stat)
{
		char mode[11];
		char mode_str[][4]={"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};
		memset(mode, 0,sizeof(mode));
		if(S_ISREG(Stat.st_mode))
		{
			mode[0] = '-';
		}
		else if(S_ISDIR(Stat.st_mode))
		{
			mode[0] = 'd';
		}
		else if(S_ISCHR(Stat.st_mode))
		{
				mode[0] = 'c';
		}
		else if(S_ISBLK(Stat.st_mode))
		{
				mode[0] = 'b';
		}
		else if(S_ISFIFO(Stat.st_mode))
		{
				mode[0] = 'p';
		}
		else if(S_ISLNK(Stat.st_mode))
		{
				mode[0] = 'l';
		}
		else if(S_ISSOCK(Stat.st_mode))
		{
				mode[0] = 's';
		}
		else
				goto ERR;
		
		int mode_num = 0;
		int i;
		for(i=6; i>=0; i=i-3)
		{
			mode_num=(Stat.st_mode>>i)&0x7;//7
			strcat(mode,mode_str[mode_num]);
		}
		printf("%s ",mode);
		return ;
ERR:
		printf("mode error!\n");
		return ;
} 
