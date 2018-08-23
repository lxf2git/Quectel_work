#include"../apue.h"

#define SHOW_HIDE 1
#define SHOW_INODE 2
#define SHOW_ALL 4

void show_ls(int flag, char **argv);
void create_memory(void **p, int size);
void show_info(struct stat *pstat, int flag);
int deal(int i); 

int main(int argc, char **argv)
{
    int ch = 0;
    int flag = 0;

    while('?' != ch)
    {
        ch = getopt(argc, argv, "lai");
#if 1
        if(-1 == ch)
        {
            break;
        }
#endif
        switch(ch)
        {
            case 'a':
                flag |= SHOW_HIDE;  // flag = 0000 0000 |= 1 
                break;

            case 'l':
                flag |= SHOW_ALL;         //     0000 0000 |=2  
                break;

            case 'i':
                flag |= SHOW_INODE;
                break;

            case '?':
                printf("input error\n");
                break;

            default :
                perror("getopt");
                break;
        }

    }
   //   flag = 0000 0101
   //
    show_ls(flag, argv);
    return 0;
}

void show_ls(int flag, char **argv)
{
    DIR *dp = NULL;
    int ret = 0;
    int i;
    struct dirent *pdirent;
    struct stat *pstat;

    create_memory((void **)&pstat, sizeof(struct stat));

/*
 *  if it has no file
 * */
    if (NULL == argv[optind])
    {/*
		ls -l 
	
	*/
        argv[optind] = "./";
    }
    ret = stat(argv[optind], pstat);

    if (ret < 0)
    {
        perror("stat");
        exit(-1);
    }
    /*
     *  if it is not a directory.
     * */
    if(!S_ISDIR(pstat->st_mode))
    {
        show_info(pstat, flag);                 //show Infomation of this file.
        
        for(i=strlen(argv[optind]); argv[optind][i] !='/'; i--)
        {
          ;
        }
        puts(argv[optind] + i + 1);             //output this filename.

    }else
    {
    /*-
     *  if it is a directory, show the file infomation within this directory.
     * */
        dp = opendir(argv[optind]);
        if(NULL == dp)
        {
            perror("opendir");
            exit(-1);
        }
        ret = chdir(argv[optind]);
        if (ret < 0)
        {
            perror("optdir");
            exit(-1);
        }
    /*
     *  traversal the directory by readdir
     * */
        while(1)
        {
            pdirent = readdir(dp);
            /*
             *  The end of the directory stream is reached.
             * */
            if(NULL == pdirent)
            {
                break;
            }

            /*
             *  If display hide file.
             * 
				flag = 0;
				flag |= 1;
				      0000 0001
			*/
			// flag -a
            if (0 == (flag&1))
            {
                if('.' == pdirent->d_name[0] )
                {
                    continue;
                }
            }

            ret = stat(pdirent->d_name, pstat);
            if(ret < 0)
            {
                perror("stat");
                exit(-1);
            }

            show_info(pstat, flag);
            /*
             *  show the name of file or directory.
             * */
            printf("%s\n", pdirent->d_name);

        }
    }

}
/*
 *  show the infomatiom of the file or dir.
 * */
void show_info(struct stat *pstat, int flag)
{
    struct stat stat = *pstat;
    char mode[11];
    /*
     *  inode number
     * */
    if ( (flag>>1)&1)
    {
        printf("%7d ", pstat->st_ino);
    }
    /*
     *  protection
     * */
    if ( (flag>>2)&1 )
    {

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
        printf("%s ", mode);

        /*
         *  number of hard links.
         * */
        printf("%3d ", stat.st_nlink);

        /*
         *  user ID of owner.
         * */
        

        printf("%s ", getpwuid(stat.st_uid)->pw_name);

        /*
         *  group ID of owner.
         * */
        printf("%s ", getgrgid(stat.st_gid)->gr_name);
        /*
         *  time of last modification. 
         * */
        char *buf;
        buf = ctime(&(stat.st_mtime));
        if(10 == buf[strlen(buf) - 1] )
        {
            buf[strlen(buf) -1] = 0;
        }

        printf("%s ", buf);
        /*
         *  total size, in bytes.
         * */
        printf("%8d ", stat.st_size);
    }
}

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


void create_memory(void **p, int size)
{
    *p = malloc(size);
    if(NULL == *p)
    {
        printf("malloc error\n");
        exit(-1);
    }
}
