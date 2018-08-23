/*
 *字符串    长度    拷贝    链接    比较
 *
 *
 *
 *
 * */
 
#include"mystring.h"

 /****************字符串 长度*********************/
int mystrlen(char *s)
{
		int length;
		for(length=0;*s++!='\0';length++)
				;

		return length;
}



 /****************字符串拷贝*********************/
char *mystrcpy(char *dest,char *src)
{
		int length,i;
		length=mystrlen(src);

		for(i=0;i<length;i++,dest++,src++)
				*dest=*src;
		*dest='\0';
		return dest;
}


 /****************字符串连接*********************/
char *mystrcat(char *dest,char *src)
{
		int len_dest,len_src,i;
		len_dest=mystrlen(dest);
		len_src=mystrlen(src);

		for(i=0 ,dest+=len_dest;  i<len_src  ;i++ ,dest++ ,src++)
				*dest=*src;
		*dest='\0';
		return dest;

}

 /****************字符串比较*********************/
char mystrcmp(char *s1,char *s2)
{
		int len_s1,len_s2,i;
		len_s1=mystrlen(s1);
		len_s2=mystrlen(s2);

		for(i=0; (i<=len_s1)&&(i<=len_s2) ;i++,s1++,s2++)
				if(*s1 != *s2)
						return *s1-*s2;
		return 0;
}
