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


#endif /* queue_h */
