#include<stdio.h>


int main()
{

	char a[100]={};
	int i,j=0;
	printf("输入一串含#的字符串");
		for(i=0;;i++)
		{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		break;
		
			if(a[i]=='#')
			{
				for(;;)
				{	
				scanf("%c",&a[i]);
					if(a[i]=='\n'||a[i]=='#')
					{
					//	a[i]='\0';
						break;
					}
				}
				i--;
			}
		}	

		a[i]='\0';
		printf("%s\n",a);



	return 0;
}
