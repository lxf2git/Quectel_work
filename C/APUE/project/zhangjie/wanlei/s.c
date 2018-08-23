#include"apue.h"

int main()
{
		char src[256];
		char dest[256];
		printf("src");
		scanf("%s",src);
		printf("dest");
		scanf("%s",dest);
		int l=strlen(src);
		char str[256];
		int j=0,i;
		memset(str, 0, sizeof(str));
		for(i=l-1;i>=0;i--)
		{   
				if('/' == src[i])
				{   
						break;
				}
				str[j] = src[i];
				j++;
		}
		l=strlen(str);
		for(i=0;i<l/2;i++)
		{   
				str[i]=str[l-i-1];
		}   
		strcat(dest,"/");
		strcat(dest,str);
		printf("%s\n",dest);

		return 0;
}
