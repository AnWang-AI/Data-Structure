//
//  sqlist.h
//  DataStructure
//
//  Created by Apple on 2019/10/23.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef sqlist_h
#define sqlist_h

#include <stdio.h>

typedef struct SqList SqList;

struct SqList{
    int * array;
    int size;
    int maxsize;
};

void sqListTest(void);


#endif /* sqlist_h */
