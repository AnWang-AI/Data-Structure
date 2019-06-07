//
//  graph.c
//  DataStructure
//
//  Created by Apple on 2019/6/4.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include "graph.h"
#include <stdlib.h>
#include "queue.h"

Adjmatrix * createAdjmatrix(int **matrix, int *vertex, int n){
    Adjmatrix * graph = (Adjmatrix*)malloc(sizeof(Adjmatrix));
    graph->n = n;
    graph->e = 0;
    graph->edge = matrix;
    graph->vertex = (Vertex*)malloc(sizeof(Vertex)*n);
    for(int i=0;i<n;i++){
        graph->vertex[i].status = UNDISCOVERED;
        graph->vertex[i].dtime = 0;
        graph->vertex[i].dtime = 0;
        graph->vertex[i].value = vertex[i];
        graph->vertex[i].inDegree = 0;
        graph->vertex[i].outDegree = 0;
        for (int j=0;j<n;j++)
            if (exists(graph, i, j)){
                graph->vertex[i].outDegree ++;
                graph->e ++;
            }
        for (int j=0;j<n;j++)
            if (exists(graph, j, i))
                graph->vertex[i].inDegree ++;
    }
    return graph;
}

int exists(Adjmatrix * graph, int i, int j){
    // 顶点i和j之间有边则返回1，否则返回0
    if (i>=0 && i<graph->n && j>=0 && j<graph->n && graph->edge[i][j]!=0){
        return 1;
    }
    else
        return 0;
}

int nextNeighbor(Adjmatrix * graph, int i, int j){// 顶点i的邻居j的下一个邻居（逆向顺序查找）
    j--;
    while (j>=0 && exists(graph, i, j)==0){
        j--;
    }
    return j;
}

int firstNeighbor(Adjmatrix * graph, int i){   // 定点i的第一个邻居
    return nextNeighbor(graph, i, graph->n);
}

void insertEdge(Adjmatrix * graph, int i, int j ,int weight){
    if (i>=0 && i<graph->n && j>=0 && j<graph->n){
        graph->edge[i][j] = weight;
        graph->vertex[i].outDegree ++;
        graph->vertex[j].inDegree ++;
        graph->e ++;
    }
    else{
        printf("insert error!\n");
    }
}

void BFS(Adjmatrix * graph, int v){
    // 广度优先搜索
    // v为遍历的起始顶点
    VertexQueue queue = createVertexQueue(100);
    Vertex * vertex = graph->vertex;
    vertex->status = DISCOVERED;
    enVertexQueue(&queue, vertex[v]);
    while(queue.size!=0){
        Vertex temp = deVertexQueue(&queue);
        printf(" %d ",temp.value);
        v = temp.value;
        int u;
        for (u = firstNeighbor(graph, v); u>=0 ; u=nextNeighbor(graph, v, u)){
            if (vertex[u].status==UNDISCOVERED){
                vertex[u].status = DISCOVERED;
                enVertexQueue(&queue, vertex[u]);
            }
        }
        temp.status = VISITED;
    }
}

void bfs(Adjmatrix * graph, int s){
    // 含有多连通域的广度优先搜索
    // s为遍历的起始顶点
    Vertex * vertex = graph->vertex;
    int v;
    for (v = s; v<graph->n; v++){
        if (vertex[v].status == UNDISCOVERED){
            BFS(graph, v);
        }
    }
}

void DFS(Adjmatrix * graph, int v, int * p_clock){
    // 深度优先搜索
    Vertex * vertex = graph->vertex;
    *p_clock = *p_clock+1;
    vertex[v].dtime = *p_clock;
    vertex[v].status = DISCOVERED;
    for (int u=firstNeighbor(graph, v); u>=0; u =nextNeighbor(graph, v, u)){
        if (vertex[u].status == UNDISCOVERED){
            DFS(graph, u, p_clock);
        }
    }
    vertex[v].status = VISITED;
    *p_clock = *p_clock+1;
    vertex[v].ftime = *p_clock;
    printf("value: %d ",vertex[v].value);
    printf("dtime: %d ftime: %d\n",vertex[v].dtime,vertex[v].ftime);
}

void dfs(Adjmatrix * graph, int s){
    // 含有多连通域的深度优先搜索
    // s为遍历的起始顶点
    Vertex * vertex = graph->vertex;
    int v;
    int clock = 0;
    for (v = s; v<graph->n; v++){
        if (vertex[v].status == UNDISCOVERED){
            DFS(graph, v, &clock);
        }
    }
}

void graph_test(void){
    int n = 7;  // 顶点数
    int vertex[7] = {0,1,2,3,4,5,6};
    int adjmatrix[7][7] =
    {
        0,1,1,0,0,0,0,
        0,0,0,0,0,0,0,
        0,0,0,1,1,0,0,
        0,0,0,0,0,0,0,
        0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,
    };
    
    // 注意这里不能把二维矩阵直接传参给函数,需要执行以下步骤
    int ** matrix = (int**)malloc(sizeof(int*)*n);
    for (int i=0;i<n;i++){
        matrix[i] = adjmatrix[i];
    }
    
    Adjmatrix * graph = createAdjmatrix(matrix, vertex, n);
    
    for (int i = 0; i<n; i++) {
        printf("%d  ",i);
        printf("in: %d ", graph->vertex[i].inDegree);
        printf("out: %d \n", graph->vertex[i].outDegree);
    }
    printf("e: %d\n", graph->e);
    
//    bfs(graph, 0);
//    printf("\n");

    dfs(graph, 0);
    printf("\n");

}
