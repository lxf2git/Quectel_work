#include<stdio.h>
char *mystrcpy(char *dest,char *src);
char *mystrcat(char *dest,char *src);
int mystrcmp(char *dest,char *src);
int main()
{
	char ch1[20];
	char ch2[20];
	char *dest=ch1;
	char *src=ch2;
	int i;
	printf("please input ch1:");
	scanf("%s",dest);
	printf("please input ch2:");
	scanf("%s",src);
	printf("\n");
	dest=mystrcpy(dest,src);
	printf("mystrcpy(dest,src):%s\n",dest);
	dest=mystrcat(ch1,ch2);
	printf("mystrcat(dest,src):%s\n",dest);	
	i=mystrcmp(ch1,ch2);
	printf("mystrcmp(dest,src):%d\n",i);

}
char *mystrcpy(char *dest,char *src)
{
	char *p;
		p=dest;
	for(;*src!='\0';dest++,src++)
	{
		*dest=*src;
	}
		*dest='\0';
		dest=p;
			return dest;


}

/*char *mystrcpy(char *dest,char *src)
{
	while(*src!='\0')
	{
		*(dest++)=*(src++);
		

	}
		return dest;

}*/
char *mystrcat(char *dest,char *src)
{
	char *p;
		p=dest;
		while(*dest!='\0')
		{
			dest++;
	
		}
		while(*src!='\0')
		{
			*(dest++)=*(src++);
		
		}
			*dest='\0';
		/*for(;*dest=='\0';*(dest++))
		{
			i=i+1;
		}
		for(*dest=*(dest+i);*src=='\0';*(dest++),*(src++))
		{
			*dest=*src;
		}*/
		dest=p;
	
	return dest;


}

int mystrcmp(char *dest,char *src)
{
	int i;
	for( ;*dest!=*src; dest++,src++)
	{
		if(*dest!=*src)
		{
			i=*src-(*dest);
			return i;
			
		}
	}


}
