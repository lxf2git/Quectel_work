#include "main.h"
#include "init.h"
#include "save.h"
#include "print.h"
#include "del.h"

void function(pStu p,pList q)
{
    int s;
    do
    {
        printf("please select the function:\n");
        printf("===========================\n");
        printf("1:---------INSERT----------\n");
        printf("2:----------DEL------------\n");
        printf("3:---------SEARCH----------\n");
        printf("4:---------PRINT-----------\n");
        printf("5:---------SAVE------------\n");
        printf("6:---------EXIT------------\n");
        printf("===========================\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
				create(p,q);
				break;
            case 2:
				del(p);
				break;
            case 3:
				search(p);
				break;
            case 4:
				print(p);
				break;
            case 5:
				save(p);
				break;
            case 6:
				exit (-1);
        }
    }while(s>=1&&s<=6);
}

