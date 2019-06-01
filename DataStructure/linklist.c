//
//  linklist.c
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include <stdlib.h>
#include "linklist.h"

Node * createNode(int value){
    Node * node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Node * findNode(Node * head, int loc){
    Node * temp = head;
    for (int i=0;i<=loc;i++){
        temp = temp->next;
        if(temp == NULL){
            return NULL;
        }
    }
    return temp;
}

//指定位置插入节点
void LinkList_insert(Node * head, int value, int loc){
    Node * newNode = createNode(value);
    Node * temp = findNode(head, loc-1); //找到要插入位置的上一个结点
    if(temp == NULL){
        printf("error\n");
    }
    else{
    newNode->next = temp->next;
    temp->next = newNode;
    head->value++;
    }
}

//指定位置删除节点
int LinkList_delete(Node * head, int loc){
    Node * temp1 = findNode(head, loc-1);
    Node * temp2 = temp1->next;
    if(temp2 == NULL){
        printf("error\n");
        return -1;
    }
    else{
    int result = temp2->value;
    temp1->next = temp2->next;
    free(temp2);
    head->value--;
    return result;
    }
}

//把头节点作为栈顶，入栈
void LinkList_push(Node * head, int value){
    Node * newNode = createNode(value);
    newNode->next = head->next;
    head->next = newNode;
    head->value++;
}

//把头节点作为栈顶，出栈
int LinkList_pop(Node * head){
    Node * temp = head->next;
    int result = temp->value;
    head->next = temp->next;
    free(temp);
    head->value--;
    return result;
}

//把尾节点作为队尾，队尾入队
void LinkList_enqueue(Node * head, int value){
    Node * newNode = createNode(value);
    Node * temp = findNode(head, head->value-1);
    newNode->next = temp->next;
    temp->next = newNode;
    head->value++;
}

//把头节点作为队首，队首出队
int LinkList_dequeue(Node * head){
    Node * temp = head->next;
    int result = temp->value;
    head->next = temp->next;
    free(temp);
    head->value--;
    return result;
}

void LinkList_print(Node * head){
    Node * temp;
    printf("[");
    for(temp=head->next;temp!=NULL;temp=temp->next){
        printf(" %d",temp->value);
    }
    printf(" ]\n");
    printf("size: %d\n",head->value);
}

void linklist_test(void){
    Node * linklist = createNode(0);    //头节点记录链表的长度
    LinkList_insert(linklist, 2, 0);
    LinkList_insert(linklist, 3, 1);
    LinkList_insert(linklist, 4, 2);
    LinkList_insert(linklist, 5, 0);
    LinkList_delete(linklist, 2);
    LinkList_push(linklist, 8);
    LinkList_push(linklist, 9);
    printf("出栈的数： %d\n",LinkList_pop(linklist));
    LinkList_enqueue(linklist, 3);
    LinkList_enqueue(linklist, 6);
    LinkList_enqueue(linklist, 7);
    printf("出队的数： %d\n",LinkList_dequeue(linklist));
    
    LinkList_print(linklist);
}
