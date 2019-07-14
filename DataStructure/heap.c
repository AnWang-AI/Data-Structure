//
//  heap.c
//  DataStructure
//
//  Created by Apple on 2019/5/29.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "heap.h"
#include <stdlib.h>

int parent(int index){
    return (index-1)/2;
}

int left_child(int index){
    return index*2+1;
}

int right_child(int index){
    return index*2+2;
}


void heapify(Heap * heap, int index){
    int left = left_child(index);
    int right = right_child(index);
    int largest = index;
    if (left<heap->size && heap->data[largest]<heap->data[left]) largest = left;
    if (right<heap->size && heap->data[largest]<heap->data[right]) largest = right;
    if (largest != index){
        int temp = heap->data[index];
        heap->data[index] = heap->data[largest];
        heap->data[largest] = temp;
        heapify(heap, largest);
    }
}

Heap * bulid_heap(int * data, int size){
    Heap * heap = (Heap*)malloc(sizeof(Heap));
    heap->data = data;
    heap->size = size;
    for(int i=(heap->size-1)/2;i>=0;i--){
        heapify(heap, i);
    }
    return heap;
}

/*-------               heapsort版本一                 ---------*/
// 开辟新的空间去建堆

void heap_sort(int * data, int size){
    bulid_heap(data, size);
    int n = size;
    for(int i=size-1;i>0;i--){
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        n--;
        bulid_heap(data, n);
    }
}

void Heap_test(void){
    int a[10] = {4,5,7,3,2,1,8,9,6,0};
    int size = 10;
    Heap * heap = bulid_heap(a, size);
    for(int i=0; i<10; i++){
        printf(" %d ", heap->data[i]);
    }
    printf("\n");
    heap_sort(a, size);
    for(int i=0; i<10; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
}

/*-------               heapsort版本二                 ---------*/
// 不需要开辟新的空间
void heapify2(int * data, int index, int size){
    int left = left_child(index);
    int right = right_child(index);
    int largest = index;
    if (left<size && data[largest]<data[left]) largest = left;
    if (right<size && data[largest]<data[right]) largest = right;
    if (largest != index){
        int temp = data[index];
        data[index] = data[largest];
        data[largest] = temp;
        heapify2(data, largest, size);
    }
}

void bulid_heap2(int * data, int size){
    for(int i=(size-1)/2;i>=0;i--){
        heapify2(data, i, size);
    }
}

void heap_sort2(int * data, int size){
    bulid_heap2(data, size);
    for(int i=size-1;i>0;i--){
        int temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        size--;
        heapify2(data, 0, size);
    }
    
}

void Heap_test2(void){
    int a[10] = {4,5,7,3,2,1,8,9,6,0};
    int size = 10;
    bulid_heap(a, size);
    for(int i=0; i<10; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
    heap_sort2(a, size);
    for(int i=0; i<10; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
}

/*-------               -----------                 ---------*/





void heap_insert(Heap * heap, int value);
int heap_delete(Heap * heap, int value);
