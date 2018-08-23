#include"save_chain.h"

int save_chain(pStu pHead,FILE *fp)
{
    fp = fopen("stuinfo","w+");
    if(NULL == fp)
    {
        printf("fopen Error :%s",__FUNCTION__);
        exit(-1);
    }
    pStu pTemp = NULL;
    pTemp = pHead->next;

    if(NULL == pTemp)
    {
        printf("there is  No data\n");
        delete_node(pHead,&pHead);
        fclose(fp);
        exit(-1);
    }
    while(pTemp != NULL)
    {
        fwrite(&pTemp->num, sizeof(int), 1, fp);
        fwrite(&pTemp->age, sizeof(int), 1, fp);
        delete_node(pHead,&pTemp);
        pTemp = pHead->next;
    }
    delete_node(pHead,&pHead);
    fclose(fp);
    printf("Save Successfully\n");
    exit(-1);


    

}
