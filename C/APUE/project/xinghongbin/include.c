#include <stdio.h>
#define NONE "\e[0m"   //无色
#define RED "\e[40;31m"//黑第红
#define GRE "\e[40;32m"//黑第绿
#define YEL "\e[40;33m"//黄
#define WIT "\e[40;37m"//白
#define PRO "\e[40;35m"//紫


struct UserInformation
{
		char userId[10];
		char passwd[10];
		char vip;
		long balance;
};
union dataOrinformation
{
		char data[200];
		struct UserInformation loginInformation;
}



typedef struct 
{
		int  mode;         						//数据类型
		char destAddr[20]; 						//目的地址
		char sourceAddr[20];					//源地址
		union dataOrinformation dorinform		//数据或者信息


}sData_package;

enum
{
		LOGIN,      //登入
		REGISTER,   //注册
		ADDFRIEND,  //添加好友
		FILE_REQUES,//文件请求
		TELL_REQUES,//谈话请求
		REQUES_EXIT,//请求结束
		END			//最后一个
};



int login_menu();
int main()
{
		int login_mode;
		login_mode = login_menu(); //界面
//		loginCmd_deal(mode); //mode解析
}


int login_menu()
{
		int login_mode;
		do
		{
				printf("do you want "RED"login"NONE" syetem and "RED"register"NONE"ID\n");
				printf(GRE"plese input "RED"1 To login "NONE"or"RED" 2 To register"NONE"\n");
				scanf("%d",&login_mode);
		}while(login_mode != 1||login_mode != 2)
		return login_mode;

}



int sendToService(mode)
{

}






