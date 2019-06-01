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

void heap_insert(Heap * heap, int value);
int heap_delete(Heap * heap, int value);
