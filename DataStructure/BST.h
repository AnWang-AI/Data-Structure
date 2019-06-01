//
//  BST.h
//  DataStructure
//
//  Created by Apple on 2019/5/26.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <stdio.h>

typedef struct treeNode treeNode;

struct treeNode{
    int value;
    treeNode * left;
    treeNode * right;
};

treeNode * creatTreeNode(int value);

treeNode * tree_search(treeNode * root, int value);
void tree_print(treeNode * root);

treeNode * BST_insert(treeNode * root, int value);
treeNode * BST_delete(treeNode * root, int value);

void BST_test(void);

#endif /* BST_h */
