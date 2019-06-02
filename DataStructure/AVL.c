//
//  AVL.c
//  DataStructure
//
//  Created by Apple on 2019/5/31.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "AVL.h"
#include <stdlib.h>

AVLNode * creatAVLNode(int value){
    AVLNode * Node = (AVLNode*)malloc(sizeof(AVLNode));
    Node->left = NULL;
    Node->right = NULL;
    Node->parent = NULL;
    Node->value = value;
    Node->height = 0;
    return Node;
}

void AVL_print(AVLNode * root){
    // 中序遍历
    // inorder traversal
    // left-degree-right(LDR)
    if(root != NULL){
        if (root->left != NULL){
            AVL_print(root->left);
        }
        printf(" %d ",root->value);
        if (root->right!=NULL) {
            AVL_print(root->right);
        }
    }
}

int getHeight(AVLNode * tree){
    if (tree == NULL){
        return -1;
    }else{
        return tree->height;
    }
}

int Max(int a, int b){
    return a>b? a:b;
}

/* ---    插入方法一     --- */
AVLNode * zag(AVLNode * A){ // 左旋
    AVLNode * B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(getHeight(A->left),getHeight(A->right))+1;
    B->height = Max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}

AVLNode * zig(AVLNode * A){ // 右旋
    AVLNode * B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(getHeight(A->left),getHeight(A->right))+1;
    B->height = Max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}

AVLNode * zigzag(AVLNode * A){    //先右旋后左旋
    A->right = zig(A->right);
    return zag(A);
}

AVLNode * zagzig(AVLNode * A){    //先左旋后右旋
    A->left = zag(A->left);
    return zig(A);
}

AVLNode * AVL_insert(AVLNode * root, int value){
    
    if (root == NULL){
        root = creatAVLNode(value);
    }
    else if (value > root->value){
        root->right = AVL_insert(root->right, value);
        if (getHeight(root->left) - getHeight(root->right) == -2){
            if (value > root->right->value){
                root = zag(root);
            }
            else if (value < root->right->value){
                root = zigzag(root);
            }
        }
    }
    else if (value < root->value){
        root->left = AVL_insert(root->left, value);
        if (getHeight(root->left) - getHeight(root->right) == 2){
            if (value < root->left->value){
                root = zig(root);
            }
            else if (value > root->left->value){
                root = zagzig(root);
            }
        }
    }
    
    root->height = Max(getHeight(root->left),getHeight(root->right))+1;
;
    
    return root;
}
/*---                 ---*/

/*---    插入方法二     ---*/
AVLNode * connect34(AVLNode * a, AVLNode * b, AVLNode * c,
                    AVLNode * T0, AVLNode * T1, AVLNode * T2, AVLNode * T3){
    // 3-4重构
    
    a->left = T0; if(T0) T0->parent = a;
    a->right = T1; if(T1) T1->parent = a;
    c->left = T2; if(T2) T2->parent = c;
    c->right = T2; if(T2) T2->parent = c;
    a->parent = b; b->left = a;
    c->parent = b; b->right = c;
    
    return b;
}

AVLNode * rotateAt(AVLNode * v){
    // v 节点  p 父亲  g 爷爷
    AVLNode * p = v->parent;
    AVLNode * g = p->parent;
    if (p == g->right){
        // p是g的右孩子
        if (v == g->right){ // zagzag
            // v是g的右孩子
            return connect34(g, p, v, g->left, p->left, v->left, v->right);
        }
        else{ // zigzag
            // b是g的左孩子
            return connect34(g, v, p, g->left, v->left, v->right, p->right);
        }
    }
    else{
        // p是g的左孩子
        if (v == g->left){ // zigzig
            // v是g的左孩子
            return connect34(v, p, g, v->left, v->right, p->right, g->right);
        }
        else{ //zagzig
            // b是g的左孩子
            return connect34(p, v, g, p->left, v->left, v->right, g->right);
        }
    }
}

/*---        ---*/

void AVL_test(void){
    AVLNode * AVL = creatAVLNode(1);
    AVL = AVL_insert(AVL, 2);
    AVL = AVL_insert(AVL, 3);
    AVL = AVL_insert(AVL, 4);
    AVL = AVL_insert(AVL, 5);
    AVL = AVL_insert(AVL, 6);
    AVL = AVL_insert(AVL, 7);
    AVL = AVL_insert(AVL, 8);
    AVL_print(AVL);
    printf("\n");
    
}

