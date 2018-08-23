#include "../apue.h"

void display_path(char *path);

int main(int argc, char **argv)
{
    char path[1024] = {0};
    if(2 != argc)
    {
        printf("%s filename", argv[1]);
        exit(-1);
    }
    
    int ret = 0;
    ret = chdir(argv[1]);
    if(ret < 0)
    {
        perror("chdir");
        exit(-1);
    }
    
    sprintf(path, "%s",getcwd(path, 1024 - 1));
    display_path(path);

    return 0;
}

void display_path(char *path)
{
    
    DIR *dirp = NULL;
    struct dirent *direntp;
    dirp = opendir(path);
    if (NULL == dirp)
    {
        perror("opendir");
        exit(-1);
    }
    char temp[1024];
    while(1)
    {
        direntp = readdir(dirp);
        if(NULL == direntp)
        {
            break;
        }
        if('.' == direntp->d_name[0])
        {
            continue ;
        }

        memset(temp, 0, 1024);
        sprintf(temp, "%s/%s",path, direntp->d_name);
        puts(temp);
        if(DT_DIR == direntp->d_type)
        {
            display_path(temp);

        }
                
    }

    closedir(dirp);
    
}
