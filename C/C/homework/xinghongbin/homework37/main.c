#include"mystring.h"
void str_input(char *p);
int main()
{
		int c;
		char a[100];
		char b[100];

		printf("input str_a \n");
		str_input(a);



		printf("strcpy:\n");
		mystrcpy(b,a);
		printf("%s\n",b);

		printf("strcat:\n");
		printf("input str_b for strcat str_a\n");
		str_input(b);
		mystrcat(a,b);
		printf("%s\n",a);

		printf("strcmp:\n");
		printf("input str_b for strcmp str_a\n");
		str_input(b);
		c=mystrcmp(a,b);
		printf("%d\n",c);

}
void str_input(char *p)
{
		scanf("%s",p);
}

