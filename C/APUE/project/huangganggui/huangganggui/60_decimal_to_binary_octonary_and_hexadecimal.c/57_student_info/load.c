#include"load.h"

void load(pStu pHead)
{
    int n, i;
    pStu pNew = NULL;
    init_node(&pNew);
    
    FILE *fp = NULL;
    fp = fopen("stuinfo","r");
    if(NULL == fp)
    {   
        printf("\nsysterm is first uesed\n");
        fp = fopen("stuinfo","w+");
        if(NULL == fp)
        {
            printf("fopen error\n");
            exit(-1);
        }
    }
    fseek(fp,0,SEEK_END);
    /*
     *  How many nodes should be create
     * */
    n = ftell(fp) / (2*sizeof(int));
    rewind(fp);
    if(0 == n)
    {
        printf("\nthere are no student . insert please.\n");
        return ;
    }
    /*
     *  create some new nodes
     * */
    
    for(i = 0; i < n; i++)
    {
        init_node(&pNew);

        fread(&pNew->num,sizeof(int),1,fp);
        fread(&pNew->age,sizeof(int),1,fp);
    
        pStu pPosition = find_bigger_position(pHead,pNew);

        insert_behind(pPosition,pNew);
    }
        
    

    fclose(fp);
}

