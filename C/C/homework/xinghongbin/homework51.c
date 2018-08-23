#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
		int id;
		char* name;
		int math_sco;
		int china_sco;
		int english_sco;
		int scorce;
		int avera;

}*pStu;
void input(pStu,int n);
void rank(pStu p,int n);
void output(pStu p,int n);

int main()
{
		int n;
		pStu p;
		printf("input number people\n");
		scanf("%d",&n);
		p=malloc(n*sizeof(struct Student));
		printf("%d %d\n",sizeof(struct Student),sizeof(pStu));
		input(p,n);
		rank(p,n);
		output(p,n);
		return 0;

}
void input(pStu p,int n)
{
		int i;
		
		
		for(i=0;i<n;i++,p++)
		{
				p->name=malloc(20);
				printf("id name math_sco chain_sco english_soc score avera\n");
				scanf("%d%s%d%d%d",&p->id , p->name , &p->math_sco , &p->china_sco , &p->english_sco);
				p->scorce = p->math_sco + p->china_sco + p->english_sco;
				p->avera = p->scorce / 3;
//				printf("%d%s%d%d%d%d%d\n",p->id,p->name,p->math_sco,p->chain_soc,p->english_sco,p->score,p->avera);

		}
		p-=n;
}
void rank(pStu p,int n)
{
		int i,j;
		int math_ave=0;
		int china_ave=0;
		int english_ave=0;
		struct Student temp;
				for(j=0;j<n;j++)
				{
						for(i=0;i<n;i++)
						{
								if((p+i)->avera > (p+j)->avera)
								{
										temp=*(p+i);
										*(p+i)=*(p+j);
										*(p+j)=temp;
								}
								


						}
						math_ave+=(p+j)->math_sco;
						china_ave+=(p+j)->china_sco;
						english_ave+=(p+j)->english_sco;
				}
				math_ave/=n;
				china_ave/=n;
				english_ave/=n;
}
void output(pStu p,int n)
{
		int i;
		float j=n*0.3;
		for(i=0;i<j;i++)
				printf("id:%d name:%s math:%d chain:%d english:%d scorce:%d avera:%d\n",p->id,p->name,p->math_sco,p->china_sco,p->english_sco,p->scorce,p->avera);
}
