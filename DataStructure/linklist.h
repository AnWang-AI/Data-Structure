//
//  linklist.h
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef linklist_h
#define linklist_h

#include <stdio.h>

typedef struct Node Node;

struct Node{
    int value;
    Node* next;
};

Node * createNode(int value);

void LinkList_insert(Node * head, int value, int loc);
int LinkList_delete(Node * head, int loc);

void LinkList_push(Node * head, int value);
int LinkList_pop(Node * head);

void LinkList_enqueue(Node * head, int value);
int LinkList_dequeue(Node * head);

void LinkList_print(Node * head);

void linklist_test(void);

#endif /* linklist_h */
