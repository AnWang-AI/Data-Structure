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

int partition1(int * a, int low, int high){
    // 选择一个pivot，将待划分的部分数组中小于pivot的数放在左边，大于等于pivot的数放在右边
    // 最后，pivot放在之间的位置，返回pivot的位置
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

int partition5(int *a, int low, int high){
    while(low<high){
        int pivot = a[low];
        while(a[low]<pivot) low++;
        while(a[high]>pivot) high--;
        if(low>=high) break;
        int temp = a[low]; a[low] = a[high]; a[high] = temp;
        low++; high--;
    }
    return low;
}

void quickSort(int * a, int low, int high){
    if (low<high){
        int pivotposition = partition4(a, low, high);
//        for (int i=0; i<12; i++){
//            printf(" %d ", a[i]);
//        }
//        printf("\n");
        quickSort(a, low, pivotposition-1);
        quickSort(a, pivotposition+1, high);
    }
}
void quickSort2(int * a, int low, int high){
    if (low<high){
        int pivotposition = partition5(a, low, high);
        //        for (int i=0; i<12; i++){
        //            printf(" %d ", a[i]);
        //        }
        //        printf("\n");
        quickSort(a, low, pivotposition-1);
        quickSort(a, pivotposition, high);
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
    int a[] = {3, 4, 6, 9, 10, 11, 6, 9, 1, 2, 13, 14};
    int n = 12;
//    int a[] = {2,3,0,1,6,7,4,5};
//    int n = 8;
    quickSort(a, 0, n-1);
    for (int i=0; i<n; i++){
        printf(" %d ", a[i]);
    }
    printf("\n");
    
}
