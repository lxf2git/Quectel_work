#ifndef _CREATE_H_
#define _CREATE_H_

#include "pub.h"

void CreateTree(struct tree *, char *);
struct tree *AddTreeNode(unsigned int);
void Pop_tree();
void Push_tree(struct tree *);
void LDR_tree(struct tree *);
void PrintTreeNode(struct tree *);
void DelTreeNode(struct tree *);
struct tree **FindEqualNode(struct tree *, struct tree *);
struct tree *SearchTreeNode(struct tree *, int);

#endif

