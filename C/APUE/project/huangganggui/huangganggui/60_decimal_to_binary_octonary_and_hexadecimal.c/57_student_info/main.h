#ifndef _MAIN_C
#define _MAIN_C

#include<stdio.h>
#define EXIST -1
#define NOTHAVE 0
#define SUCCESSED 0
#define FAILE -1



typedef struct student
{
    int num;    /*id*/
    int age;

    struct student *next;

    void (*stu_print)(struct student *);
    int (*stu_input)(struct student *);

}sStu, *pStu;

typedef struct list
{
    pStu pHead;
    int (*pInsert)(pStu pHead, pStu pNew, int (*pIDFind)(pStu pHead, pStu pNew), pStu(pInsertPosition)( pStu pHead, pStu pNew));
    

    int (*pDel)(pStu pHead, pStu(pDelPosition)(pStu pNode, int age));

    void (*pPrint)(pStu pHead);

    int (*pSearch)(pStu pHead, int(*pFun_search[2])(pStu pHead, int num));

    int (*pStu_save)(pStu pHead, FILE *fp);
}sList, *pList;
#include"load.h"
#include"init.h"
#include"insert.h"
#include"delete.h"
#include"print_chain.h"
#include"search.h"
#include"save_chain.h"

#endif
