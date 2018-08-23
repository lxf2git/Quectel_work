#include"../apue.h"

void display(void);
int main()
{
    int ret;
    int i;
    char cmd[256] = {0};
    printf("welecome to xshell.\n");
    while(1)
    {
        display();
        memset(cmd, 0, 255);
        scanf("%[^\n]", cmd);
        getchar();
        for(i = 0; cmd[i] == ' '; i++)
        {
            ;
        }
        if(!strcpm(cmd,"bye"))
        {
            
        }
        if (!strncmp(cmd + i,"cd ",3))
        {
              ret = chdir(cmd + i + 3);
              if(ret < 0)
              {
                perror("bash : cd ");
              }
        }else if(!strncmp(cmd + i,"ls", 2))
        {
            strcat(cmd, " --color");
            system(cmd);
        }else
        {
            system(cmd);
        }

    }

    printf("good bye.\n");
}
void display(void)
{
    int i;
    char temp[255];
    memset(temp, 0, 255);


    getcwd(temp,1024-1);

    for(i = strlen(temp); temp[i] != '/'; i--)
    {
        ;
    }

    strcpy(temp, temp + i + 1);

    fprintf(stdout, " [%s@%s %s]", getenv("USER"), getenv("HOSTNAME"), temp);
    if(!strcmp(getenv("USER"), "root"))
    {
        fprintf(stdout, "%c ", '#');
    }else
    {
        fprintf(stdout, "%c ", '$');
    }

}
