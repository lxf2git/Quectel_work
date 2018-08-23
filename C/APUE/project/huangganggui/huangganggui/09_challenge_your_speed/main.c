#include"../apue.h"
int n ;
void wakeup(int flg)
{
    system("stty cooked");
    if ( SIGALRM == flg)
    {
        printf("%d numbers you input.\n", n);
        exit(0);
    }else
    {
        printf("error:%s\n", __FUNCTION__);
    }
    
}

void display(void)
{
    system("stty cooked");
    
    exit(0);
}

int main()
{
    atexit(display);
    srand(time(NULL));
    signal(SIGALRM, wakeup);
    system("clear");

    printf("\n\n\n\n                 Have a Fun Time   !\n");
    printf("\n Introduction: I will give you a character by chance ,input it fast in 15s.\n");
    printf(" The faster you input, the more scores you get.\n");
    alarm (15);

    int except;
    int ch;

    
    while(1)
    {
        except = rand()%26 + 'a';
        printf("%c\n",except);

        system("stty raw");
        ch = getchar();
        system("stty cooked");

        printf("\n");
        if(except == ch)
        {
            n++;
            printf("input currect\n");
        }else
        {
            printf("input error\n");
        }   
    }

    return 0;
}


