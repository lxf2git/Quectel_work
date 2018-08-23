#include<stdio.h>
int mystrlen(char *s);
char *mystrcpy(char *dest,char *src);
char *mystrcat(char *dest,char *src);
char mystrcmp(char *s1,char *s2);
int main()
{
		int length,c;
		char a[]="hello";
		char b[]="helle";
//		length=mystrlen(a);
		c=mystrcmp(a,b);
		printf("%d\n",c);
		return 0;
}
int mystrlen(char *s)
{
		int length;
		for(length=0;*s++!='\0';length++);
		return length;
}


char *mystrcpy(char *dest,char *src)
{
		int length,i;
		length=mystrlen(src);

		for(i=0;i<length;i++,dest++,src++)
				*dest=*src;
		*dest='\0';
		return dest;
}

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
char mystrcmp(char *s1,char *s2)
{
		int len_s1,len_s2,i;
		len_s1=mystrlen(s1);
		len_s2=mystrlen(s2);

		for(i=0; (i<len_s1)&&(i<len_s2) ;i++,s1++,s2++)
				if(*s1 != *s2)
						return *s1-*s2;
		return 0;
}
