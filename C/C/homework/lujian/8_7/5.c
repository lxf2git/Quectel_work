
/****************************************
 *
 * 选做：找出两个字符串中的最大公共子串
 *
 * 例如："abccaddde" "dgcadde"的最大公共子串为"cadde"
 *
 * 指针法 求最大公共字串
 *	
 *
 *							2015 08 08
 *
 *							autor： 陆剑
 * ***************************************/
#include<stdio.h> 
#include<string.h> 
#define  N  (100)
#define  DEBUG

int count_max(char* s3);
int input(char *p);
int search_samestr(char* s1, char* s2);

/**********主函数*********/

int main()
{
	char str1[N], str2[N];

	input(str1);
	input(str2);

	search_samestr(str1, str2);

	 return 0; 
}
/*********字符串输入******/

int input(char *p)
{
	printf("please \n");
   	gets(p);	

	return 0; 
}

/*********寻找公共字符串*********/

 int search_samestr(char* s1, char* s2)
{
	char str3[N];
	char *s3 = str3;
	int i, j, k, l,m=0;

	for (i =0,k=0; i<strlen(s1); i++)
	{
			k = 0; //注意 k 下标的清零 归位

			for (j = 0, l=0; j<strlen(s2); j++)
			{	
					l = 0; // 注意l 下标的清零 归位

					if (*(s1+i)== *(s2+j))
					{
					//	printf("[%s = %d line]\n", __FUNCTION__, __LINE__ ); 
							for (k=i,l=j; (k<strlen(s1))
											&& (l<strlen(s2));
											k++,l++)
							{
								
									if(*(s1+k) != *(s2+l))
											break;
									else
									{	
											*(s3+m++) = *(s1+k);

									}


							}
/**************************** 得到公共的字符串**********/
							*(s3+m) = '\0';
							
							m=0;  //注意 m 清零；

/**************************** 调用最大求最大公共字符串**/

							count_max(s3); 
					}
			}	

		}	
	
	 return 0; 
} 

/*****************求最大公共字符串**********************/


int count_max(char* s3)
{
	static int max = 0;
	if(max<strlen(s3))
	{
		max = strlen(s3);
#if 0		
		for (i =0; i<strlen(str3); i++)
		{
			str4[i] = str3[i];

		}

		str4[i] = '\0';
	}
#endif 
	
	printf("the STRING :%s\n",s3);  //printf("",);	
	}
}
	
	


