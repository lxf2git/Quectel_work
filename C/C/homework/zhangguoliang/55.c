#include<stdio.h>
int main()
{
	FILE *fp=fopen("b.txt","w+");
	int i,j;
	char a[20];
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%s",a);
			switch(j)
			{
				case 0:
				   fputs(" 姓名:",fp);
				   break;
				case 1:
				   fputs(" 年龄:",fp);	
				   break;
				case 2:
				   fputs(" 性别:",fp);	
				   break;
				case 3:
				   fputs(" id:",fp);	
				   break;
			}
			fputs(a,fp);
		}
		fputs("\n",fp);
	}
	fclose(fp);
	return 0;
}
