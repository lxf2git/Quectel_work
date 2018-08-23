#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
long generatorId();
int showMenu();
int saveMenu();
int creatMenu(int j);
int withdrawMenu();
int save();
int query();
int queryMenu();
extern long id;
extern double balance;
#endif
