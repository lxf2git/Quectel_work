
#ifndef MAIN_H
#define  MAIN_H
#include"stack.h"
#define  N    (100)
 int mid_tree(Ptree proot, Psta ps);
 int show_tree(Ptree proot, Psta ps);
 int ma_init_node(Ptree * p);
 int creat_tree(Ptree* proot, char* arr);
int prev_tree(Ptree proot, Psta ps);
int back_tree(Ptree proot, Psta ps);

#endif 
