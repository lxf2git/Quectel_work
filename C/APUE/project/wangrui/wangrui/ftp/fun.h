#ifndef FUN_H
#define FUN_H

#define ARG_FILE 2
#define ARG_DIR  3
#define ARG_OTHER  4
//get
int funSerToCGet(int confd,struct cli_to_ser ctose);
void ftp_ser_get_dir(int confd,int cmdttr,char * dirname);
void ftp_ser_get_file(int confd,int cmdttr,char * filename);
int judgAttr(char * arg);
void getArgName(char * arg);
void funCliToSGet(int sockfd,struct ser_to_cli stocl);
void ftp_cli_get_dir(int sockfd,char * dirname);
void ftp_cli_get_file(int sockfd,char * filename);
//put
int funSerToCPut(int confd,struct cli_to_ser ctose);
void ftp_ser_put(int confd,struct ser_to_cli stocl);
void ftp_ser_put_dir(int confd,char * dirname);
void ftp_ser_put_file(int confd,char * filename);
void funCliToSPut(int confd,struct ser_to_cli stocl);
void ftp_cli_put_dir(int confd,int cmdttr,char * dirname);
void ftp_cli_put_file(int confd,int cmdttr,char * filename);
//cli
void funCliPwd(int sockfd,struct ser_to_cli stocl);
void funCliMkdir(int sockfd,struct ser_to_cli stocl);
void funCliCd(int sockfd,struct ser_to_cli stocl);
void funCliLs(int sockfd,struct ser_to_cli stocl);

//ser
int funcd(int confd,struct cli_to_ser ctose);
int funpwd(int confd,struct cli_to_ser ctose);
int funmkdir(int confd,struct cli_to_ser ctose);
int funls(int confd,struct cli_to_ser ctose);



#endif
