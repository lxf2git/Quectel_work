#include"../apue.h"

#define SHOW_HIDE 1
#define SHOW_INODE 2
#define SHOW_ALL 4

void show_ls(int flag);
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
        printf("argv[optind]:%s\n", argv[optind]);

        if(-1 == ch)
        {
            break;
        }

        switch(ch)
        {
            case 'a':
//                printf("a\n");
                flag |= SHOW_HIDE;
                break;


            case 'l':
  //              printf("l\n");
                flag |= SHOW_ALL;
                break;

            case 'i':
    //            printf("i\n");
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
   
//   printf("%d", flag);
    show_ls(flag);
//    printf("show succesful\n");
    return 0;
}

void show_ls(int flag)
{
    DIR *dp = NULL;
    int ret = 0;
    char strTemp[255];
    extern char* optarg;
    //puts(optarg);
//    memset(strTemp, 0, 255);
    char *onlyShow = NULL;
    int change = 1;
#if 0
    if (NULL != optarg)
    {
        dp = opendir(optarg);
        if (NULL == dp)
        {
            if(ENOTDIR == errno)
            {
                dp = opendir("./");
                if(NULL == dp)
                {
                    perror("optdir");

                    exit(-1);
                }
                onlyShow = optarg;
                change = 0;
            }else
            {
                perror("opdir");
                exit(-1);

            }
        }
    }else
    {
        dp = opendir("./");
        if(NULL == dp)
        {
            perror("opdir");
            exit(-1);
        }
        change = 0;
    }
#endif
//    printf("change:%d\n", change);
    

    struct dirent *pdirent;
    struct stat *pstat;
    create_memory((void **)&pstat, sizeof(struct stat));
    char buf[255];
    while(1)
    {
        pdirent = readdir(dp);
        if(NULL == pdirent)
        {
            break;
        }
        memset(buf ,0 ,255);

        if (NULL != onlyShow)
        {
            if(strcmp(pdirent->d_name,onlyShow))
            {
                continue ;
            }
        }

        if (0 != change)
        {
            strcat(buf, optarg);
        }
        strcat(buf, pdirent->d_name);

     //   printf("judge a:%d\n", flag);
//        printf(" flag&1:%d\n", flag&1); 

    //    if(!(flag&1))
        if (0 == (flag&1))
        {
  //              printf("debug\n");
          //      printf("pdirent->d_name[0]:%c\n", pdirent->d_name[0]);
            
            if('.' == pdirent->d_name[0] )
            {
                continue;
            }
        }

        ret = stat(buf, pstat);
        if(ret < 0)
        {
            perror("stat");
            exit(-1);
        }

        show_info(pstat, flag);
        printf("%s\n", pdirent->d_name);

    }

}
void show_info(struct stat *pstat, int flag)
{
    struct stat stat = *pstat;
    char mode[11];
    if ( (flag>>1)&1)
    {
        printf("%d ", pstat->st_ino);
    }
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

        printf("%-2d ", stat.st_nlink);
        printf("%d ", stat.st_uid);
        printf("%d ", stat.st_gid);
        printf("%d ", stat.st_size);
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
