#include<stdio.h>
int main()
{

		int line=0,cha=0,word=0;
		char a;
	printf("请输入正文:");
	for(;;)
	{	
		scanf("%c",&a);
		if(a==46)
		{
			line++;
			printf("\n");

		}
		if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
		{
			cha++;
			printf("%c",a);

		}
		if(a==32)
		{
			word++;

		}
		if(a=='\n')
		{
			break;
		}

	}


			printf("line:%d ",line);
			printf("cha:%d ",cha);
			printf("word:%d ",line+word);
		return 0;





}

