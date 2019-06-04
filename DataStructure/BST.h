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
    treeNode * parent;
};

treeNode * creatTreeNode(int value);

treeNode * tree_search(treeNode * root, int value);

void inorder_tree_print(treeNode * root);

treeNode * BST_insert_1(treeNode * root, int value);
treeNode * BST_insert_2(treeNode * root, int value);

treeNode * BST_delete_1(treeNode * root, int x);
treeNode * BST_delete_2(treeNode * root, int x);

void BST_test(void);

#endif /* BST_h */
