//
//  sqlist.c
//  DataStructure
//
//  Created by Apple on 2019/10/23.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "sqlist.h"
#include <stdlib.h>
#include <stdbool.h>

SqList * createSqList(int a[], int size, int maxsize){
    SqList * sqlist = (SqList*)malloc(sizeof(SqList));
    sqlist->size = size;
    sqlist->array = a;
    sqlist->maxsize = maxsize;
    return sqlist;
}

bool insertSqList(SqList * sqlist, int value, int i){ // 插入位置为i，插入值为value
    if(i<0 || i>=sqlist->size)
        return false;
    if(sqlist->size >= sqlist->maxsize)
        return false;
    for(int j = sqlist->size; j>i; j--){
        sqlist->array[j] = sqlist->array[j-1];
    }
    sqlist->array[i] = value;
    sqlist->size++;
    return true;
}

bool deleteSqList(SqList * sqlist, int i){ // 删除i位置的元素
    if(i<0 || i>=sqlist->size)
        return false;
    for(int j = i; j<=sqlist->size; j++){
        sqlist->array[j] = sqlist->array[j+1];
    }
    sqlist->size--;
    return true;
}



void printSqList(SqList * sqlist){
    for (int i=0; i<sqlist->size; i++){
        printf("%d ", sqlist->array[i]);
    }
    printf("\n");
}




void sqListTest(){
    int a[10] = {3,4,5,6};
    int size = 4;
    SqList * sqlist = createSqList(a, size, 10);
    printSqList(sqlist);
    insertSqList(sqlist, 9, 1);
    printSqList(sqlist);
    deleteSqList(sqlist, 0);
    printSqList(sqlist);


}
