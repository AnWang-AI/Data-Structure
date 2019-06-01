//
//  AVL.h
//  DataStructure
//
//  Created by Apple on 2019/5/31.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

#include <stdio.h>

typedef struct AVLNode AVLNode;

struct AVLNode{
    int value;
    AVLNode * left; //左子树
    AVLNode * right; //右子树
    int height; // 高度
};

AVLNode * creatAVLNode(int value);

AVLNode * AVL_search(AVLNode * root, int value);

void AVL_print(AVLNode * root);

AVLNode * AVL_insert(AVLNode * root, int value);

void AVL_test(void);

#endif /* AVL_h */
