#include"bin.h"

int transf_bin(pSta ps,int num,int flg)
{
    int result,temp;
    while(num != 0)
    {
        switch (flg)
        {
            case 1:
                temp = 2;
                break;
            case 2:
                temp = 8;
                break;
            case 3:
                temp = 16;
                break;

        }

        pull(ps,num%temp);
        num /= temp;
    }
    printf("\nresult is:");
    while(ps->top != 0)
    {
        pop(ps,&result);
        if(result >=10&&result<=15)
        {
            printf("%c",result + 87);
        }else
        {

            printf("%c ",result + 48);
        }
    }
    printf("\n");
}

