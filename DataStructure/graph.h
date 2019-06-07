//
//  graph.h
//  DataStructure
//
//  Created by Apple on 2019/6/4.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>

enum VERTEX_STATUS {UNDISCOVERED, DISCOVERED, VISITED};

typedef struct Vertex Vertex;
struct Vertex{
    int value;
    int inDegree;   //入度
    int outDegree;  //出度
    enum VERTEX_STATUS status;
    int dtime;
    int ftime;
};

//typedef struct Edge Edge;
//struct Edge{
//    int value;
//    int weight;
//};


// 用邻接矩阵(adjacency matrix)表示图
typedef struct Adjmatrix Adjmatrix;
struct Adjmatrix{
    Vertex * vertex;
    int ** edge;
    int n; // 顶点的数目
    int e; // 边的数目
};


int exists(Adjmatrix * graph, int i, int j);
int nextNeighbor(Adjmatrix * graph, int i, int j);// 顶点i的邻居j的下一个邻居（逆向顺序查找）
int firstNeighbor(Adjmatrix * graph, int i);    // 定点i的第一个邻居

void insertEdge(Adjmatrix * graph, int i, int j ,int weight);



void graph_test(void);

#endif /* graph_h */
