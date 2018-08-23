#ifndef _CREATETREE_H_
#define _CREATETREE_H_

#include "pub.h"

void CreateTree(struct tree *, char *);
struct tree *AddTreeNode(char);
void DLR_tree(struct tree *);
void LDR_tree(struct tree *);
void LRD_tree(struct tree *);
void PrintTreeNode(struct tree *);
void Push_tree(struct tree *);
void Pop_tree();


#endif
