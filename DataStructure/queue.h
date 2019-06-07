//
//  queue.h
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "BST.h"
#include "graph.h"

// 元素为int型的队列
typedef struct Queue{
    int * list;
    int front;
    int rear;
    int size;     //队列中包含元素的个数
    int length;   //队列总长
}Queue;

Queue createQueue(int length);
void enqueue(Queue * queue, int x);
int dequeue(Queue * queue);
void queue_print(Queue queue);

void queue_test(void);

/*   -----------------------------   */

// 元素为treeNode的队列
typedef struct NodeQueue{
    treeNode * list;
    int front;
    int rear;
    int size;     //队列中包含元素的个数
    int length;   //队列总长
}NodeQueue;

NodeQueue createNodeQueue(int length);
void enNodeQueue(NodeQueue * queue, treeNode Node);
treeNode deNodeQueue(NodeQueue * queue);

/*   -----------------------------   */

// 元素为Vertex的队列
typedef struct VertexQueue{
    Vertex * list;
    int front;
    int rear;
    int size;     //队列中包含元素的个数
    int length;   //队列总长
}VertexQueue;

VertexQueue createVertexQueue(int length);
void enVertexQueue(VertexQueue * queue, Vertex Node);
Vertex deVertexQueue(VertexQueue * queue);

#endif /* queue_h */
