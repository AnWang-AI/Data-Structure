//
//  BST.c
//  DataStructure
//
//  Created by Apple on 2019/5/26.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "BST.h"
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

treeNode * creatTreeNode(int value){
    treeNode * Node = (treeNode*)malloc(sizeof(treeNode));
    Node->left = NULL;
    Node->right = NULL;
    Node->parent = NULL;
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

void inorder_tree_print(treeNode * root){
    // 中序遍历 （递归方式）
    // inorder traversal
    // left-degree-right(LDR)
    if(root != NULL){
        if (root->left != NULL){
            inorder_tree_print(root->left);
        }
        printf(" %d ",root->value);
        if (root->right!=NULL) {
            inorder_tree_print(root->right);
        }
    }
}

void inorder_tree_print2(treeNode * root){
    // 中序遍历 (非递归方式)
    // inorder traversal
    // left-degree-right(LDR)
    treeNodeStack stack = createTreeNodeStack(100);
    treeNodePush(*root, &stack);
    treeNode * temp = root;
    while(isTreeNodeStackEmpty(&stack)==0){
        while(temp->left!=NULL){
            temp = temp->left;
            treeNodePush(*temp, &stack);
        }
        *temp = treeNodePop(&stack);
        printf(" %d ", temp->value);
        if(temp->right!=NULL){
            temp = temp->right;
            treeNodePush(*temp, &stack);
        }
    }
}



void levelorder_tree_print(treeNode * root){
    // 层次遍历
    // leverl order traversal
    NodeQueue queue = createNodeQueue(100); // 引入辅助队列
    enNodeQueue(&queue, *root); // 将根节点入队
    while(queue.size!=0){   // 如果队列不为空
        treeNode node = deNodeQueue(&queue); // 从队列中取出最早入队的元素
        printf(" %d", node.value);
        if(node.left!=NULL){
            enNodeQueue(&queue, *node.left);    // 左孩子入队
        }
        if(node.right!=NULL){
            enNodeQueue(&queue, *node.right);   //y 右孩子入队
        }
    }
}


treeNode * BST_insert_1(treeNode * root, int value, treeNode * parent){
    // 通过递归插入节点,初始时parent参数输入为NULL
    if (root == NULL){
        root = creatTreeNode(value);
        root->parent = parent;
    }
    else{
        if(value < root->value){
            root->left = BST_insert_1(root->left, value, root);
        }
        if(value >= root->value){
            root->right = BST_insert_1(root->right, value, root);
        }
    }
    return root;
}

treeNode * BST_insert_2(treeNode * root, int value){
    // 通过while循环插入节点，可设置父节点
    if (root == NULL){
        root = creatTreeNode(value);
    }
    else{
        treeNode * pre = root;
        treeNode * cur = root;
        while(cur != NULL){
            pre = cur;
            if(value < pre->value){
                cur = pre->left;
            }
            else if(value >= pre->value){
                cur = pre->right;
            }
        }
        cur = creatTreeNode(value);
        cur->parent = pre;
        if(value < pre->value)
            pre->left = cur;
        else if(value >= pre->value)
            pre->right = cur;
    }
    return root;
}


treeNode * findNext(treeNode * Node){
    //(在有右子树的情况)寻找指定节点在中序遍历的下一个节点，也就是右子树的最小值
    if (Node->right!=NULL){
        treeNode * tmp = Node->right;
        if(tmp->left!=NULL){
            tmp = tmp->left;
        }
        return tmp;
    }else{
        return NULL;
    }
}


treeNode* BST_delete_1(treeNode * root, int x){
    // 通过递归删除结点
    if(root == NULL){
        return root;
    }else if(x < root->value){
        root->left = BST_delete_1(root->left, x);
    }else if(x > root->value){
        root->right = BST_delete_1(root->right, x);
    }else{
        if(root->left == NULL && root->right == NULL){//no child
            free(root);
            root = NULL;
        }else if(root->left == NULL){//right child only
            treeNode* temp = root;
            root = root->right;
            root->parent = temp->parent;
            free(temp);
        }else if(root->right == NULL){//left child only
            treeNode* temp = root;
            root = root->left;
            root->parent = temp->parent;
            free(temp);
        }else{//two children
            treeNode * temp = findNext(root);
            root->value = temp->value;
            //delete the smallest node in right sub-tree, because it has been copied to the node we want to delete initially.
            root->right = BST_delete_1(root->right, temp->value);
        }
    }
    return root;
}

treeNode * BST_delete_2(treeNode * root, int x){
    // 先用search函数搜索到待删除结点，再删除结点，修改父节点
    if(root == NULL){
        printf("This three is empty!\n");
        return root;
    }else{
        treeNode * cur = tree_search(root, x);
        if (cur == NULL) {
            printf("The tree don't have this node");
        }
        else{
            treeNode * pre = cur->parent;
            if(cur->left == NULL && cur->right == NULL){// no child
                free(cur);
                cur = NULL;
                if (pre){
                    if (x < pre->value)
                        pre->left = NULL;
                    else if (x >= pre->value)
                        pre->right = NULL;
                }
                else{
                    // 此时的BST变成一棵空树
                    return NULL;
                }
            }
            else if(cur->left == NULL){// right child only
                treeNode* temp = cur;
                cur = cur->right;
                cur->parent = pre;
                free(temp);
                if (pre){
                    if (x < pre->value)
                        pre->left = cur;
                    else if (x >= pre->value)
                        pre->right = cur;
                }
                else{
                    return cur;
                }
            }
            else if(cur->right == NULL){// left child only
                treeNode* temp = cur;
                cur = cur->left;
                cur->parent = pre;
                free(temp);
                if(pre){
                    if (x < pre->value)
                        pre->left = cur;
                    else if (x >= pre->value)
                        pre->right = cur;
                }
                else{
                    return cur;
                }
            }
            else{// two children
                treeNode * temp = findNext(cur);    // 寻找右子树的最大结点，也就是cur中序遍历的后续结点
                cur->value = temp->value;
                cur->right = BST_delete_1(cur->right,temp->value);
            }
        }
    }
    
    
    return root;
}

void BST_test(void){
    treeNode * BST = NULL;
    BST = BST_insert_1(BST, 7, NULL);
    BST = BST_insert_1(BST, 3, NULL);
    BST = BST_insert_1(BST, 9, NULL);
    BST = BST_insert_2(BST, 1);
    BST = BST_insert_2(BST, 5);
    BST = BST_insert_2(BST, 4);
    BST = BST_insert_2(BST, 8);
    BST = BST_insert_2(BST, 10);
    
    
    inorder_tree_print(BST);
    //levelorder_tree_print(BST);
    printf("\n");
    
    treeNode * tmp1 = tree_search(BST, 9);
    treeNode * tmp2 = findNext(tmp1);
    printf("%d", tmp2->value);
        
//    BST = BST_delete_1(BST, 9);
    
//    inorder_tree_print2(BST);
    //levelorder_tree_print(BST);
//    printf("\n");
    
//    printf(" %d ", BST->right->value);
    printf("\n");
}


