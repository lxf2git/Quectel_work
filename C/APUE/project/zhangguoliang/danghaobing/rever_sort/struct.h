#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct sword
{
	int file_no;//第几个文件
	int where;
	int num;//第几个单词
	struct sword *next;
	struct sword *prev;
}sSword,*pSword;

typedef struct words
{
	char wsave[20];
	pSword same_words;
	struct words *next;
	struct words *prev;
}sWord,*pWord;

typedef struct second
{
	pWord dword[13];
}sSec,*pSec;

typedef struct first
{
	pSec dsecond[4];
}sFirst,*pFirst;
#endif
