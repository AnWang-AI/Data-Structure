//
//  heap.h
//  DataStructure
//
//  Created by Apple on 2019/5/29.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>

typedef struct Heap Heap;

struct Heap{
    int * data; // 数组
    int size; //堆的大小
};

void heapify(Heap * heap, int index);

Heap * bulid_heap(int * data, int size);

void heap_insert(Heap * heap, int value);
int heap_delete(Heap * heap, int value);

void Heap_test(void);

#endif /* heap_h */
