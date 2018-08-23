#include<stdio.h>
#include<string.h>


void sort(char aa[40])
{
	int a, b;
	char f;
	int c = strlen(aa);
	for(a = 0;a < c;a++)
	{
		for(b = a;b < c;b++)
		{
			if(aa[a] > aa[b])
			{
				f = aa[a];
				aa[a] = aa[b];
				aa[b] = f;
			}
		}
	}

}

void dup(char aa[40])
{
	int a, b, c;
	c = strlen(aa);
	printf("\n");
	for(a = 0;a < c -1;a++)
	{
		if(aa[a] == aa[a + 1])
		{
			for(b = a;b < c -1;b++)
			{
				if(aa[b] == '\0')
				{
					break;
				}
				aa[b] = aa[b + 1];
			}
			c--;
			a--;
		}
		aa[c] = '\0';
	}
} 
int main()
{
	char aa[40] = {'0'}, bb[20] = {'0'};
	int max, a, b, c;
	printf("请输入第一组字符串\n");
	gets(aa);
	printf("请输入第二组字符串\n");
	gets(bb);

	sort(aa);//排序
	sort(bb);//排序
	printf("第一组字符串排序");
	puts(aa);
	printf("第二组字符串排序");
	puts(bb);

	strcat(aa,bb);//将两个字符串接一起
	sort(aa);//链接后的字符串排序
	dup(aa);//去重
	puts(aa);
	return 0;
}
