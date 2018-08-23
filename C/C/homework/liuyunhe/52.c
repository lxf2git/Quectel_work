#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
struct vote
{
		char *vote_name;

}VV[N];
struct vote_1
{
		int xi;
		int liu;
		int li;
		int paopiao;
}VO;
void vote_vo()
{
		int i;
		VO.xi=0;
		VO.liu=0;
		VO.li=0;
		VO.paopiao=0;
		for(i=0;i<N;i++)
		{
				 if(strcmp(VV[i].vote_name,"xi")==0)
				 {
							VO.xi++;
				 }
				 else if(strcmp(VV[i].vote_name,"liu")==0)
				 {
							VO.liu++;
				 }
				 else if(strcmp(VV[i].vote_name,"li")==0)
				 {
							VO.li++;
				 }
				 else
				 {
						 VO.paopiao++;
				 }
		}	 
}
int main()
{
		int i;
		for(i=0;i<N;i++)
		{
				VV[i].vote_name=malloc(N*sizeof(struct vote));
				printf("请输入投票候选人的名字xi,liu,li\n");
				scanf("%s",VV[i].vote_name);
				//printf("%s",VV[i].vote_name);
		}

		vote_vo();
		printf("xi=%dliu=%dli=%d跑票=%d\n",VO.xi,VO.liu,VO.li,VO.paopiao);

		for(i=0;i<N;i++)
		{
				free(VV[i].vote_name);
		}
}
