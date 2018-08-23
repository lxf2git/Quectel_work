#include"main.h"

int main()
{
    int num_dec,flg;
    sSta sStack;
    init_stack(&sStack);
    
    while(1)
    {
        printf("\nwhat type do you want:\n");
        printf("1 Bin\n");
        printf("2 Oct\n");
        printf("3 Hex\n\n");
        printf("4 EXIT\n");
        printf("\n");

        scanf("%d", &flg);
        if(flg == 4)
        {
            if (sStack.bottom != NULL)
            {
                free(sStack.bottom);
                sStack.bottom = NULL;
            }
            exit(0);

        }
        printf("input a number you want to be transformed:\n");
        scanf("%d", &num_dec);
        printf("\n");

        transf_bin( &sStack,num_dec,flg);
    }
    return 0;
}
