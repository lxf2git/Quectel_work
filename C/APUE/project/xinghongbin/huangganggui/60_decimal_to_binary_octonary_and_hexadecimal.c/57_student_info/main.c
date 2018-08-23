#include"main.h"

int main()
{
    FILE *fp = NULL;
    sList fun;
    pStu pNew = NULL;
    int (*pSearchArr[2])(pStu ,int)={search_by_id_print, search_by_age_print};
    fun.pHead = NULL;
    init_node(&fun.pHead);
    load(fun.pHead);

    fun.pInsert = insert;
    fun.pDel = delete;
    fun.pPrint = print_chain;
    fun.pSearch = search;
    fun.pStu_save = save_chain;

    do{
    
        printf("\nInput your choice\n");
        printf("1 Insert information\n");
        printf("2 Delete information\n");
        printf("3 Print All\n");
        printf("4 Search information\n");
        printf("5 Save and quit\n\n");
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                (*fun.pInsert)( fun.pHead, pNew, findid, find_bigger_position);
                break;
            case 2:
                (*fun.pDel)( fun.pHead, find_node_with_age);
                break;
            case 3:
                (*fun.pPrint)(fun.pHead);
                break;
            case 4:
                (*fun.pSearch)(fun.pHead, pSearchArr);
                break;
            case 5:
                (*fun.pStu_save)(fun.pHead, fp);
                break;
            default:
                printf("Input Error\nInput again please\n");
                break;
        
        }


    }while(1);

    
    
    


    return 0;
}

