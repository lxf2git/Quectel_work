#include "apue.h"
int deal(int i)
{
    switch(i%3)
    {
        case 1:
            return 'r';
            break;
        case 2:
            return 'w';
            break;
        case 0:
            return 'x';
            break;
        default:
            return 0;
            break;

    }

}

int main(int argc, char **argv)
{
	struct stat stat;
	char mode[11];

	if(argc!=2)
	{
			printf("%s name", argv[0]);
			return -1;
	}
 
	memset(mode, 0, sizeof(mode));
	lstat(argv[1], &stat);
	if(S_ISREG(stat.st_mode))
	{
		mode[0]='-';
	}
	else 
		if(S_ISDIR(stat.st_mode))
		{
			mode[0]='d';
		}
		else
			if(S_ISCHR(stat.st_mode))
			{
					mode[0]='c';
			}
			else
				if(S_ISBLK(stat.st_mode))
				{
						mode[0]='b';
				}
				else
					if(S_ISFIFO(stat.st_mode))
					{
							mode[0]='p';
					}
					else
						if(S_ISLNK(stat.st_mode))
						{
								mode[0]='l';
						}
						else
							if(S_ISSOCK(stat.st_mode))
							{
									mode[0]='s';
							}

	int mode_num = 0;
    int i;

    for(i = 1; i < 10; i++)
    {
	    mode_num = (stat.st_mode >> (9 - i))&0x1;
        if (1 == mode_num)
        {
            mode[i] = deal(i);
        }else
        {
            mode[i] = '-';
        }
        
    }
	printf("mode=%s\n", mode);

#if 0
	mode_num=(stat.st_mode>>6)&0x7;
	printf("1:%d\n", mode_num);

	mode_num=(stat.st_mode>>3)&0x7;
	printf("2:%d\n", mode_num);

	mode_num=stat.st_mode&0x7;
	printf("3:%d\n", mode_num);
	
#endif

	return 0;
}












