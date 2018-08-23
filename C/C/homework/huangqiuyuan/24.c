#include<stdio.h>
int main()
{
	int i,n;
	char a[5000];
	printf("输入一串字母：");
	for(i=0;;i++)
{	
	scanf("%c",&a[i]);
	if(a[i]=='c')
	i--;
	if(a[i]=='\n')
	break;

}

	for(n=0;n<=i;n++)
	printf("%c",a[n]);
 	return 0;
}
