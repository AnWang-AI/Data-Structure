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

void linklist_test(void);

#endif /* linklist_h */
