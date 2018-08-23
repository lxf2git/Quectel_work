#ifndef _MICORBLOG_H_
#define _MICORBLOG_H_
//一下内容请仔细阅读!
/*要求*
 * 代码要有注释（变量名 函数名都干啥的 写清楚了）
 * 必须用这个俩个头文件、自己要添加跟我说
 * 链表必须用指针
 * 初始化链表需要把嵌套的链表也初始化
 * 功能函数类型和参数不能更改
 * 注意： 客户端功能要和服务器功能对应好
 * 所有代码自己测试完成再给我
 * 别把测试用的代码打上
 */

#define SUC 0
#define FAIL -1

typedef struct friend	//好友
{
		int s_id;	//好友的ID
		struct friend *prev;
		struct friend *next;
}SFriend, *PFriend;

typedef struct comment //评论
{
		char *s_text; //评论内容
		char s_nick_name[20]; //评论用户昵称
		struct comment *prev;
		struct comment *next;
}SComment, *PComment;

typedef struct microblog //发表的微博
{
		char *s_text; //微博内容
		struct comment *s_comment; //评论
		int s_praise; // 赞
		struct microblog *prev;
		struct microblog *next;
}SMicroblog, *PMicroblog;

typedef struct user_basic_info // 用户基本信息
{
		int s_id;
		int s_age;
		char s_user_name [20];
		char s_passwd [20];
		char s_nick_name [20] ;
		char s_sex [2] ;
}SUer_basic_info, *PUser_basic_info;

typedef struct user_info
{
		int friend_num;
		int fanc_num;
		struct friend* s_friend;//好友
		struct friend* s_fanc;//粉丝
		struct user_basic_info s_user_basic_info; //用户基本信息
		struct microblog* s_microblog; //发表的微博
		struct user_info *prev;
		struct user_info *next;
}SUser_info, *PUser_info;

PUser_info puihead;
static int user_id = 1;

enum{ LOGIN=1, REGISTER, SEARCH, ATTENTION, FANC, PUBLISH, DELBLOG, CHANGEPWD, VIEW };
//		登录、	注册、		搜索、关注、查看fanc、发表微博、删除微博、评论微博、查看用户微博
int del_friend(struct user_info *user, struct user_info *friend);
int add_friend(struct user_info *user,struct user_info *friend);
int find_friend(struct user_info *pfhead, struct user_info *user);
int find_fanc(struct user_info *pfhead, struct user_info *user);
struct user_info *find_nick(char *nick_name);
struct user_info *find_user_name(char *s_user_name);
void *Login(int confd);//登录
void *Register(int confd);//注册
int Add_user(struct user_basic_info *user);
void *Publish_microblog(int confd);//发表微博
void *Search(int confd);//搜索昵称
void *Comment_micorblog(int confd, struct comment *comment, PUser_info s_data, PMicroblog blog);//评论微博
void *Find_fanc(int confd);
void *Find_friend(int confd);
void *Forwar_microblog(int confd, PMicroblog blog);//转发微博
void *Attention(int confd, struct user_info *s_data, int num);//关注
void *Find_friend(int confd);//查看关注列表
void *Find_fanc(int confd);//查看fanc列表
void *Own_zone(int confd);//主页
void *Del_microblog(int confd);//删除微博
void *Rewrite_basic_info(int confd);
void *send_com(int confd, PUser_info s_data, PComment comment);
#endif
