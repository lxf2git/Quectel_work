#include"same_str.h"
#define N 20
#define M 20
int main()
{
		char *dest;
		char str1[N],str2[M];
		gets(str1);
		gets(str2);
		dest = same_str(str1,str2);
        printf("%s",dest);  
		return 0;
}
