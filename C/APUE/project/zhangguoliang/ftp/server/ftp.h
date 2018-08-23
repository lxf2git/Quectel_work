#ifndef _FTP_H_
#define _FTP_H_
#include "apue.h"
void my_ls(struct recv_to_deal);
void my_cd(struct recv_to_deal);
void my_pwd(struct recv_to_deal);
void my_mkdir(struct recv_to_deal);
void my_get(struct recv_to_deal);
void my_put(struct recv_to_deal);
void my_quit();
#endif
