oneday

1安装minicom
minicom -s 
+------------------------------------------------------
| A -    Serial Device      : /dev/ttyUSB0             
 B - Lockfile Location     : /var/lock                
| C -   Callin Program      :                          
| D -  Callout Program      :                          
| E -    Bps/Par/Bits       : 115200 8N1               
| F - Hardware Flow Control : No                       
| G - Software Flow Control : No                       
|                                                      
PSR  当前程序状态寄存器
SPSR  备份程序状态寄存器


+-------------------------------------------
// shif +A /dev/ttyUSB //设置端口
// shif + F yes				
//	save+exit
启动minicom 
//# minicom
退出
//ctrl+a +q +yes



2 安装vsftpd

安装 vsftpd   
生效 

/etc/init.d/vsftpd restart 
添加到 vim /root/.bash_profile //环境变量配置文件


3 配置IP网卡
 /etc/sysconfig/network-script //配置文件
//ifcfg-eth0 
//ifcfg-eth1

 配置arm板 ip网卡
 //vi /etc/eth0-setting(在minicom下)

 重启网卡
/etc/init.d/network restart 
&&
service network restart

4 解压 交叉编译环境
tar zxvf  arm-linux-gcc-4.5.1-v6-vfp-20120301.tgz  -C  / 

配置环境变量  PATH 

PATH=/opt/FriendlyARM/toolschain/4.5.1/bin:$PATH:$HOME/bin:./
生效
source /root/.bash_profile //重启配置文件



5 编译程序

arm-linux-gcc xx.c 

把a.out  拷贝到 /var/ftp  
minicom 下  

ftp 主机IP //进入ftp

name  ftp
password enter

get  a.out 

quit  退出

chmod 777 a.out 

1 nfs 启动
	mkdir /exynos
	vim  /etc/exports //配置nfs  文件
	/exynos *(rw)
	setup  //nfs 
	/etc/init.d/nfs restart //重启nfs
	minicom 下
	mount -t nfs -o nolock 192.168.1.41:/exynos /mnt //挂载 的arm板的/mnt下

2 makefile 的写法


3 shell 的写法 //参见 SHELL目录


4 内嵌汇编

G__asm__  __volatile__(
				汇编语句
				：输出部分   //汇编---》输出C语言
				：输入部分	//C语言-----》汇编
				：破坏部分
				)；

__asm__  汇编语句开始

__volatile__   告诉编译器下面的语句不需要优化

占位符：  %0 -----  %9

权限 ：  r  通用寄存器
=只写

CPSR  当前程序状态寄存器
SPSR  备份程序状态寄存器


汇编条件执行

cmp Z=1  表示比较两个数大小相等
	N=1	 结果为负数; N = 0 大于或等于0	

bne 不等于则跳转
subne 不等于就做减法操作
eq 等于
lt 小于
le 小于等于
gt 大于
ge 大于等于

ldr str(内存和寄存器之间数据的移动)

ldr:从内存取出一个word

ldr r0 [r1]          //从地址r1处取出一个word 赋值给r0 
ldr r0 [r1, #offset] //从地址r1+offset处取出一个word赋值给r0
ldr r0 [r1, #offset]!//从地址r1+offset处取出一个word赋值给r0，r1 = r1+offset
ldr r0 [r1], #offset //从地址r1处取出一个word赋值给r0, r1=r1+offset 

str:
	str ro [r1] 把r0的值赋值给地址r1内存
	......

//烧写uboot到sd卡
1 cd /uboot
	make tiny4412_config
	vim board/samsung/ting4412/config.mk  //改写配置
	修改地址  C改写4  43e00000  T__start  

2  vim include/config/tiny4412.h
	311 行注释							 //关闭虚拟地址

3  make -C sd_fuse
	cd uboot/sd_fuse/tiny4412
	执行
	./sd_fusing.sh /dev/sdb 			//烧录sd卡
//day4
ARM 过程调用标准（APCS）
(默认)
 r0  a1
 r1  a2
 r2  a3
 r3  a4 

 r4 v1
 r5 v2 
 ...
 r11 v8

 
 r12 ip
 r13 sp
 r14 lr
 r15 pc

 a1---a4 用来传递参数（形參）  返回值 r0
 v1----v8 用来保存局部变量 如果使用，需要保存原来的值 然后在使用
 ip 内部过程调用寄存器
 sp 栈指针（栈顶）
 lr 链接寄存器，用来保存返回地址
 pc 程序计数器，存放下一条指令所在单元的地址的地方

mov lr, pc

(1) IA:每次传送后地址加4
(2)	IB:每次传送前地址加4
3   DA:每次传送后地址减4
4  	DB:每次传送前地址减4

STMIA R1！，{r5-r7}
! 最后的地址写回到r1中
^ 23页

(5) FD:满递减堆栈  （满：栈顶指针指向的空间有数据 递减：存数据时是由高地址向低地址 ）
读数据时是由低地址向高地址
(6) ED:空递减堆栈
(7) FA:满递增堆栈
(8) EA:空递增堆栈


STMFD sp!, {r2-r4}
				[sp-4] <-- r4   
				[sp-8] <---r3
				[sp-12]<---r2

LDMFD sp!, {r6-r8}
				r6<--[sp]       
				r7<--[sp+4]
				r8<---[sp+8]






Guser_maual

p82 map_memory

p95 GPIO

p116 




ADC  





 MMU  内存管理单元
 功能
  1 将虚拟地址转换成物理地址
  2 对物理内存设置访问权限


    虚拟地址： 程序能够产生的地址范围。
	 物理地址： 硬件本身的实际地址


	  100     0-----4G

	   2G

	   段模式

	   虚拟地址
	   0x300_00012     0x300_00000（虚拟的地址的基地址） ----->768（描述符下标）  ----->  描述符（物理地址的基地址）0x400_00000 --->0x400_00002

	   虚拟地址=基地址+偏移地址

	   0x400_00014=0x400_00002 + 0x00012
	   物理地址=基地址+偏移地址

	   描述符
	   描述符表 (内存)

		  0xfff_00011
		    0x500_00011

			MMU   c1   c2   c3    .....c10

			c1  0bit  设置成1  使能mmu   设置成0 关闭mmu


			c2  描述符表的地址

			c3  内存访问权限   1111....11(32个)  允许任何访问


			MCR

//中断 
软中断 硬中断

区别：
 1 软中断发生的时间由程序控制，硬中断发生的时间随机的
 2 软中断是由程序调度发生的，硬中断是由外设引发的 




 中断：软中断  硬中断  

 区别
 1 软中断发生的时间是由程序控制的，硬中断发生的时间是随机的
 2 软中断是由程序调度发生的，硬中断是由外设引发的


 硬中断

 中断发生---->中断号----》 中断向量(中断处理程序的地址)-----> 中断处理程序  

 中断向量表  


 0 或0xffff_0000）     设置（mmu---》  c1）  13位   1  0xffff_0000   0   0   //设置中断向量表的地址

 CPSR  
 cpsie i 开中断  

 cpsid i 关中断



 ARM 处理器执行过程

    三级流水线

   取指  译指  执行


   PC    ----》 取指


   pc-8   ----> 执行的指令


   LR  ----> pc-4 //译指



   中断    pc+4
     lr=lr-4


	 7  6  5  4  3  2


	 中断

	 stm 中 ^  cpsr ----》spsr

man user
 
 744 
 786
 794
 748
 780
 801
 812
 782
 815
 357
 367


watdog timer：








uart
数据通信方式：
并行：多条数据线同时数据
串行：一条数据线将数据一位一位的传输


异步通信： 以字符为单位， 传输两个字符时， 间隔不固定， 同一个字符的两个bite 位间隔相等

通信协议：双方约定的一规则。

异步通信的规则：

起始位： 发送一个0逻辑信号，（拉低电平），表示传输字符开始

数据位： 4，5，6 7， 8 （一次传输的位数） 从最低位 开始传输；

奇偶校验位：



奇校验：
 0110101   1 个数是偶数  加1， 变为奇数 所以 校验位0
0110001    1 个数是奇数  加0， 仍为奇数 所以校验位为 0；

偶校验：
0110101    1个数是偶数   加0， 变为偶数 所以校验位 0
0110001    1个数是奇数    加1， 变为偶数 所以校验位  1 

停止位：	
	结束标志
波特率：
	衡量传输速度：单位bit 

锁相环：(倍频放大器)
	

UART:通用异步收发器



1 设置波特率
2 设置传输格式 数据位位数  流控等 
起始位


//BCD 码用四位二进制数存储一个十进制数
	1----》0001
	9----》1001
	10---》0001 0000 
	15---》0001 0101



//PWM 定时器
1 占空比：高电平/整个T



//


SCL1  SDA1  
只支持4个手指头


步骤：

/**********初始化********************/


1  外设中断eint14
2  设置引脚功能 IIC  
3  IIC 分频 0-3  6  使能  5    1415页 
4   设置IIC过滤器  
5  IIC  ACK  使能  7   


/*********处理函数**********************/

6  写中断处理函数 do_ts()

		1) 给数据移位寄存器(I2CDS)赋值，（0x70）
		设置 I2CSTAT  为0xf0
		2）等待  I2Ccon  的  4 位  是否为1   来判断ack  
		3) I2ccon 4位 写入 0 才能读下一个数据  



