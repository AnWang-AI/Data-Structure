//
//  stack.h
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "BST.h"

typedef struct Stack{
    int * list;
    int head;
    int length;
} Stack;

Stack createStack(int length);
void stack_init(Stack * stack, int array[], int array_size, int length);
void stack_print(Stack stack);
void push(int x, Stack * stack);
int pop(Stack * stack);




typedef struct treeNodeStack{
    treeNode * list;
    int head;
    int length;
} treeNodeStack;

treeNodeStack createTreeNodeStack(int length);
void treeNodePush(treeNode node, treeNodeStack * stack);
treeNode treeNodePop(treeNodeStack * stack);
int isTreeNodeStackEmpty(treeNodeStack * stack);



void stack_test(void);

#endif /* stack_h */
