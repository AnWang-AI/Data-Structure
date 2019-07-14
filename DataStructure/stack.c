//
//  stack.c
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include <stdlib.h>
#include "stack.h"
#include "BST.h"

Stack createStack(int length){
    Stack stack;
    stack.list = (int*)malloc(sizeof(int)*length); //创建数组
    stack.head = 0;
    stack.length = length;
    return stack;
}

void stack_init(Stack * stack, int array[], int array_size, int length){
    stack->list = array;
    stack->head = array_size;
    stack->length = length;
}

void push(int x, Stack * stack){
    stack->list[stack->head++] = x;
}

int pop(Stack * stack){
    return stack->list[--stack->head];
}

void stack_print(Stack stack){
    printf("this stack cotains: \n");
    for(int i=0;i<stack.head;i++)
        printf("%d ",stack.list[i]);
    printf("\n");
}

/**/

treeNodeStack createTreeNodeStack(int length){
    treeNodeStack stack;
    stack.list = (treeNode*)malloc(sizeof(treeNode)*length);
    stack.head = 0;
    stack.length = length;
    return stack;
}

void treeNodePush(treeNode node, treeNodeStack * stack){
    stack->list[stack->head++] = node;
}

treeNode treeNodePop(treeNodeStack * stack){
    return stack->list[--stack->head];
}

int isTreeNodeStackEmpty(treeNodeStack * stack){
    if(stack->head==0){
        return 1;
    }else{
        return 0;
    }
}
/**/


void stack_test(void){
    Stack stack;
    int array[10] = {3,4,5,7,7,4};
    int array_size = sizeof(array)/sizeof(array[0]);
    stack_init(&stack, array, 6, array_size); // 注意因为函数里的形参试stack的指针，故这里传的是stack的地址
    push(1, &stack);
    stack_print(stack);
    printf("pop: %d\n",pop(&stack));
    printf("pop: %d\n",pop(&stack));
    printf("pop: %d\n",pop(&stack));
    printf("pop: %d\n",pop(&stack));
    printf("pop: %d\n",pop(&stack));
    printf("pop: %d\n",pop(&stack));
    stack_print(stack);
}
