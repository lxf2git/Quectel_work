#include"../apue.h"

int main()
{
    int ret ;
    ret = fork();

    if (0 == ret)
    {
        char c = 'a';
        int fd;
        pid_t ret;
        
        chdir("/");
        fd = open("/dev/null", O_WRONLY);
        if(fd < 0)
        {
            perror("open");
            exit(-1);
        }

        dup2(fd, 1);
        dup2(fd, 2);
        dup2(fd, 0);

        close(fd);

        ret = setsid();
        if(ret < 0)
        {
            perror("setsid");
            exit(-1);
        }
        umask(0);

        fd = open("/tmp/daemon", O_CREAT|O_RDWR|O_APPEND, 0666);
        if (fd < 0)
        {
            perror("open");
            exit(-1);
        }


        while(1)
        {
            write(fd, &c, 1);
            if('z' == c)
            {
                c = 'a';
            }

            c++;

        }


    }else
    {
        exit(0);
    }

}
