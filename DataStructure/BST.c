//
//  BST.c
//  DataStructure
//
//  Created by Apple on 2019/5/26.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "BST.h"
#include <stdlib.h>

treeNode * creatTreeNode(int value){
    treeNode * Node = (treeNode*)malloc(sizeof(treeNode));
    Node->left = NULL;
    Node->right = NULL;
    Node->value = value;
    return Node;
}

treeNode * tree_search(treeNode * root, int value){
    if(root == NULL){
        return NULL;
    }
    else if(value > root->value){
        return tree_search(root->right, value);
    }
    else if(value < root->value){
        return tree_search(root->left, value);
    }
    else return root;
}

void tree_print(treeNode * root){
    // 中序遍历
    // inorder traversal
    // left-degree-right(LDR)
    if(root != NULL){
        if (root->left != NULL){
            tree_print(root->left);
        }
        printf(" %d ",root->value);
        if (root->right!=NULL) {
            tree_print(root->right);
        }
    }
}

treeNode * BST_insert(treeNode * root, int value){
    if (root == NULL){
        root = creatTreeNode(value);
    }
    else{
        if(value < root->value){
            root->left = BST_insert(root->left, value);
        }
        if(value >= root->value){
            root->right = BST_insert(root->right, value);
        }
    }
    return root;
}

treeNode * findNext(treeNode * Node){
    //寻找指定节点在中序遍历的下一个节点，也就是右子树的最小值
    if(Node->left == NULL)
        return Node;
    else {
        return findNext(Node->right);
    }
}

treeNode* BST_delete(treeNode* root, int x){
    if(root == NULL){
        return root;
    }else if(x < root->value){
        root->left = BST_delete(root->left,x);
    }else if(x > root->value){
        root->right = BST_delete(root->right,x);
    }else{
        if(root->left == NULL && root->right == NULL){//no child
            free(root);
            root = NULL;
        }else if(root->left == NULL){//right child only
            treeNode* temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NULL){//left child only
            treeNode* temp = root;
            root = root->left;
            free(temp);
        }else{//two children
            treeNode * temp = findNext(root);
            root->value = temp->value;
            //delete the smallest node in right sub-tree, because it has been copied to the node we want to delete initially.
            root->right = BST_delete(root->right,temp->value);
        }
    }
    return root;
}

void BST_test(void){
    treeNode * BST = NULL;
    BST = creatTreeNode(9);
    BST_insert(BST, 5);
    BST_insert(BST, 3);
    BST_insert(BST, 1);
    BST_insert(BST, 7);
    BST_insert(BST, 8);
    BST_insert(BST, 4);
    BST_insert(BST, 2);
    
    tree_print(BST);
    printf("\n");
    
    BST_delete(BST, 8);
    //delete(BST, 2);

    tree_print(BST);
    printf("\n");
}


