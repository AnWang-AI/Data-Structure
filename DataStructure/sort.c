//
//  sort.c
//  DataStructure
//
//  Created by Apple on 2019/7/9.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "sort.h"
#include <stdlib.h>


/***    冒泡排序   ***/
void bubbleSort(int * a, int n){
    // a为待排序的数组，n为数组的长度
    int i, j;
    int temp;
    int didswap;
    for (i=n; i>0; i--){
        didswap = 0;
        for (j=0; j<i-1; j++){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                didswap = 1;
            }
        }
        if (didswap == 0)
            return;
    }
    return;
}

/***    快速排序   ***/

// 考研版本
int partition1(int * a, int low, int high){
    // 挖坑法
    // 从两边分别不断往中间查看（先右后左），若右边有小于pivot的数，则移到左边，再看若左边有pivot的数，则移到右边
    // 最后，当查看到中间只有一个单元时，将pivot放在这个位置，并返回pivot的位置
    int pivot = a[low];
    while (low<high){
        while (a[high]>=pivot)
            high --;
        a[low] = a[high]; // 此时a[high]<pivot
        // 注：在第一次进行这个操作时，将pivot原来的位置替换成一个比pivot小的数
        while (low<high && a[low]<=pivot)
            low ++;
        a[high] = a[low]; // 此时a[low]>pivot
    }
    a[low] = pivot; // 此时low = high
    return low;
}

int partition2(int * a, int low, int high){
    int pivot = a[low];
    int i = low+1, j = high;
    while (i<j){
        while (a[i]<pivot) i++;
        while (a[j]>pivot) j--;
        if (j<=i) break;
        int temp = a[i]; a[i] = a[j]; a[j] = temp;
        i ++;
        j --;
    }
    a[low] = a[i-1];
    a[i-1] = pivot;
    return i-1;
}

// （算法导论版本）

int partition3(int * a, int low, int high){
    int pivot = a[high];
    int i = low;
    int j;
    for (j = low; j<high; j++){
        if (a[j] <= pivot){
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++;
        }
    }
    // 以上步骤使得 从low到i-1（包括low和i-1）之间的数小于等于pivot，i到high-1（包括i和high-1）的数比pivot大
    // 也就是说a[i]指向的为第一个比a[pivot]大的数
    int temp = a[i]; a[i] = a[high]; a[high] = temp;
    return i;
}

int partition4(int *a, int low, int high){
    int pivot = a[low];
    int i = low;
    int j;
    for (j = low+1; j<=high; j++){
        if (a[j]<=pivot){
            i++;
            int temp = a[i]; a[i] = a[j]; a[j] = temp;
        }
    }
    int temp = a[i]; a[i] = a[low]; a[low] = temp;
    return i;
}


void quickSort1(int * a, int low, int high){
    if (low<high){
        int pivotposition = partition4(a, low, high);
        
        quickSort1(a, low, pivotposition-1);
        quickSort1(a, pivotposition+1, high);
    }
}

// 快排（日本考试常见版本）：非常容易写错

void quickSort2(int * a, int low, int high){
    int i = low, j = high;
    int pivot = a[low];
    while(i<j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i>j) break;
        int temp = a[i]; a[i] = a[j]; a[j] = temp;
        i++; j--;
    }
    
    printf("pivot:%d low: %d, high: %d\n",pivot, low, high);
    printf("i: %d, j: %d\n", i, j);
    for (int i=low; i<=high; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
    
    if (low < i-1)
        quickSort2(a, low, j);
    if (high > j+1)
        quickSort2(a, i, high);
}

// 换种方式写quicksort2

int partition5(int * a, int low, int high){
    int i = low, j = high;
    int pivot = a[low];
    while(i<j){
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i>j) break;
        int temp = a[i]; a[i] = a[j]; a[j] = temp;
        i++; j--;
    }
    // 结束循环的情况有三种，第一种是i=j时，a[i]=pivot,那么j会移动到i-1的位置，i会移动到i+1的位置
    // 第二种是刚好换完时，i=j，此时循环退出，但并不知道a[i]与pivot之间的大小关系
    // 第三种是刚好换完时，i=j-1，此时a[i]>=pivot,a[j]<=pivot
    if(a[i]>pivot)
        return i-1;
    else
        return i;
}



void quickSort3(int * a, int low, int high){
    if (low<high){
        int pivotposition = partition5(a, low, high);
        for (int i=low; i<=high; i++){
            printf(" %d ", a[i]);
        }
        printf("\n");
        quickSort1(a, low, pivotposition);
        quickSort1(a, pivotposition+1, high);
    }
}

/***    选择排序   ***/

void selectSort(int * a, int n){
    int max;
    for (int i=n; i>0; i--){
        max = i;
        for (int j=i; j>=0; j--)
            if (a[max]<a[j]){
                max = j;
            }
        if (max != i){
            int temp = a[max];
            a[max] = a[i];
            a[i] = temp;
        }
    }
}

/***   插入排序   ***/
 
void insertSort(int* a, int n){
    int i,j;
    for(i=1;i<n;i++){
        int temp = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j] > temp){
                a[j+1] = a[j];
            }else{
                break;
            }
        }
        a[j+1] = temp;
    }
}


/**  插入排序（二分）   ***/

void bi_insertSort(int* a, int n){
    int i;
    for(i=1;i<n;i++){
        int k = a[i];
        int low = 0;
        int high = i - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if (a[mid]>k) {
                high = mid-1;
            }
            else{
                low = mid + 1;
            }

        }
        for (int p = i; p > low; p--){
            a[p] = a[p-1];
        }
        a[low] = k;
    }
}


/***   希尔排序   ***/

void shellSort(int* a, int n){
    int i,j;
    int gap;
    int temp;
    for(gap = n>>1; gap>0; gap>>=1){
        for(i=gap;i<n;i++){
            temp = a[i];
            for(j=i-gap;j>=0&&a[j]>temp;j-=gap){
                a[j+gap] = a[j];
            }
            a[j+gap] = temp;
        }
    }
}

/***    归并排序   ***/

void merge(int * a, int left, int mid, int right){
    int * temp_array = (int *)malloc((right - left +1)*sizeof(int));
    int i = left, j = mid+1, k=0;
    while(i<=mid && j<=right){
        if (a[i]<a[j]){
            temp_array[k] = a[i];
            i++;
            k++;
        }else{
            temp_array[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp_array[k] = a[i];
        i++;
        k++;
    }
    while (j<=right) {
        temp_array[k] = a[j];
        j++;
        k++;
    }
    for(k=left;k<=right;k++){
        a[k] = temp_array[k-left];
    }
}

void mergeSort(int * a, int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}

/***    排序测试   ***/

void sorttest(){
    int a[] = {3, 4, 6, 9, 11, 10, 6, 9, 13, 1, 5, 7};
    
    int n = 12;
    
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
    bi_insertSort(a, n);
    
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    
}
