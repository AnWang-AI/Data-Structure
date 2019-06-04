//
//  StringMatch.c
//  DataStructure
//
//  Created by Apple on 2019/6/3.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "StringMatch.h"
#include <String.h>
#include <stdlib.h>

int * buildNext(char * P){
    // Next表的作用：
    //    t = Next[j]表示P[0,j）的最大自匹配的真前缀和真后缀的长度
    //    也就是意味着在匹配失败时，可以快速移动模版串，直到移动后模版串自匹配的真前缀和原先真后缀的位置对齐
    int m = (int)strlen(P); // 字符串长度
    int j = 0; // 串P的指针
    int * Next = (int*)malloc(sizeof(int) * m);
    int t = Next[0] = -1; // 指示前缀长度的指针
    while (j<m-1){ // 如果指针j没有越界
        if (t == -1 || P[j] == P[t]){ // 如果匹配成功（或前缀指针t指向了-1）
            j++;
            t++;
            // 原KMP算法：
            // Next[j] = t; //最大自匹配的真前缀和真后缀的长度
            // 改进后：
            Next[j] = P[j]!=P[t]? t:Next[t];
        }
        else{   // 如果匹配失败
            t = Next[t];
        }
    }
    
    for(int i = 0; i<m; i++){
        printf("%d ",Next[i]);
    }
    printf("\n");
    
    return Next;
}

int KMP_match(char * T, char * P){
    int n = (int)strlen(T); // 文本串T的长度
    int m = (int)strlen(P); // 模版串P的长度
    int * Next = buildNext(P); // 建立一个Next表
    int i = 0;  // 文本串T的指针
    int j = 0;  // 模版串P的指针
    while ( j<m && i<n ){ // 如果指针没有越界，如果j越界，表示匹配成功，如果i越界j没越界，表示匹配失败
        if (T[i]==P[j] || j==-1){ // 如果匹配成功
            i++;
            j++;
        }
        else{ // 如果匹配失败
            j = Next[j];
        }
    }
    return i-j;
};

void KMP_test(){
    char str1[] = "aaaaabbbb";
    char str2[] = "baabaa";
    int number = KMP_match(str1, str2);
    printf("%d\n",number);
}
