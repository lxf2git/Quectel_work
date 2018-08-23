#include <common.h>
#include <eint.h>
#include <iic.h>
#define  X (132)
#define  Y  (43)

static char buf[X][Y];

void do_pic( int x, int y);
void print();
void delay(int data);
void iic_master_read_stop();
void iic_clear_repond();
void iic_wait_for_repond();
void iic_master_read_start(int addr_data);
void iic_write(int data);
void iic_init();
void mem_init(unsigned long* ttb);
void mmu_init(void);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
void memcpy(char *dest, const char *src, int n);
void do_irq(void);
void gpio_for_iic1();
void do_ts();
void iic_enable_ack();
extern int start;
extern int end;
int main()
{
	   unsigned long *va=(void*)0xffff0018;
	   unsigned long *pa=(void*)0x7fff0018;

		   mmu_init();
		   mmu_enable();
		  mmap((void*)0x70000000,(unsigned long)va,(unsigned long)pa);
		  memcpy((void*)0xffff0000,(void*)start,end-start);

	    __asm__ __volatile__(
					"cpsie i\n\t"
				);	   

		/******CPU INterface****/
	     ICCICR_CPU0=1;    //786
		 ICCPMR_CPU0=255;   //786
		/*******GIC(中断分配器) ********/
  		ICDDCR=1;  // 794

		/*******中断源***********/
		ICDISER1=1<<(62-32);    //使能中断源 748   780   801
		 ICDIPR15 &=~(0xff<<16);             // (值越低，优先级越大) 748  781   812  
		 ICDIPTR15=1<<16;     // 782  中断源对应的处理器0   815    
	
		    GPX1CON  |=0xf<<24;       // 设置成中断 357 
	          EXT_INT41CON |=2<<24;    // 触发条件 366 
	         EXT_INT41_MASK &=~(1<<6); //使能 379


		gpio_for_iic1(); 
		  iic_init();
		   iic_enable_ack();
			pic_init();

}

void pic_init()
{

		int i, j;
		for (i=0; i<X; i++)
		{
				if ( i==0 || i == X-1)
				{
						for (j=0;j<Y; j++)
						{
								buf[i][j] ='*';
						}
				}

				else if (i<X-1)
				{

						for (j=0;j<Y; j++)
						{
								if (j==0 || j==Y-1)
								{
										buf[i][j] ="*";
								}
								else
									buf[i][j] =' ';

						}
				}
				
		   }

}

void iic_enable_ack()
{
	    I2CCON |=1<<7;

}
void iic_init()
{
	   I2CCON =(1<<6)|15|(1<<5);
	     I2CLC=(1<<2)| 3;
}	
void gpio_for_iic1()
{
	  GPD1CON |=0x22<<8;
}
void do_irq(void)
{
	  unsigned  iic_=ICCIAR_CPU0;
	      switch(iic_&0x3ff)
		  {
		  	case 62:
					do_ts();
					break;
			default:
					break;
		  }
		  ICCEOIR_CPU0=iic_;
}

void iic_write(int data)
{

	   I2CDS=data;

}

void iic_master_read_start(int addr_data)
{
	      iic_write(addr_data);
		    I2CSTAT=0xb0;

}
void iic_wait_for_repond()
{
	   while( !(I2CCON&(1<<4))) ;

}
void iic_clear_repond()
{
		 I2CCON &=~(1<<4);

}
char  iic_read()
{
	   return (char)I2CDS;

}
void iic_master_read_stop()
{
	    I2CSTAT=0x90;
		 iic_clear_repond();

}


void do_pic( int x, int y)
{
	printf("x = %d, y = %d \n",x,y);
	buf[x/10][y/10] ='@';
}

void print()
{
	int i=0; 
	int j=0; 

	for (i =0; i<Y; i++)
	{
		for (j=0; j<X; j++)
		{
			printf("%c",buf[j][i]);
			buf[j][i] ='\0';
		}
		printf("\n");
	}
	pic_init();
	
}
 
void do_ts()
{
	   char buffer[30];
	   int num;
	     
	          iic_master_read_start(0x70);
			     iic_wait_for_repond();
				   iic_clear_repond();
		         for(num=0;num<30;num++)
				 {
			     iic_wait_for_repond();
		            buffer[num]=iic_read();
				   iic_clear_repond();
				 }
                  
				 iic_master_read_stop();
				 switch(buffer[2])
				 {
				 	case 4:
				    case 3:
					case 2:
							print();
							break;
					case 1: 
							do_pic((buffer[3]&0xf)<<8|buffer[4], (buffer[5]&0xf)<<8|buffer[6]);
							break;
				    defalut:
						break;
				 }
	     EXT_INT41_PEND=EXT_INT41_PEND;
}


void delay(int data)
{
	int num,num1;
		for(num=0;num<1000;num++)
			for(num1=0;num1<data;num1++)
				;
}

  void memcpy(char *dest, const char *src, int n)
{
			while(n--)
				*dest++=*src++;

}
void mmu_enable(void)
{
	    __asm__ __volatile__(
				
					   "mrc p15,0,r0,c1,c0,0\n\t"
					   "orr r0,r0,#1\n\t"
					   "orr r0,r0,#(1<<13)\n\t"  
					   "mcr p15,0,r0,c1,c0,0\n\t"
					   :
					   :
					   :"r0"
				);
}
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa)
{
	ttb[va>>20]=(pa&0xfff00000)|2;
}
void mem_init(unsigned long* ttb)
{ 
	   unsigned  long pa,va;
		  for(pa=0x00000000;pa<0x14000000;pa+=0x100000)
		  { va=pa;
		  ttb[va>>20]=(pa&0xfff00000)|2;
		  }
		 
	   	for(pa=0x40000000;pa<0x80000000;pa+=0x100000)
		  {
			  va=pa;
		  ttb[va>>20]=(pa&0xfff00000)|2;
			}

}
void mmu_init(void)
{
		unsigned long* ttb=(void*)0x70000000;

		     mem_init(ttb);

         __asm__ __volatile__(
				 	" mvn r0,#0x0\n\t"
					"mcr  p15,0,r0,c3,c0,0\n\t"
				 	"mcr  p15,0,%0,c2,c0,0\n\t"
					:
					:"r"(ttb)
					:"r0"

				 );
}




