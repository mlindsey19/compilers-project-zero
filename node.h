//
// Created by mlind on 2/10/2019.
//

#ifndef P0_NODE_H
#define P0_NODE_H

#define MAX_STR_SIZE 64
#define MAX_NUM_STR 32

typedef struct node
{
    int setCount;
    int depth;
    struct node * leftChild;
    struct node * rightChild;
    char   dataArray[MAX_NUM_STR][MAX_STR_SIZE];

} node;

#endif //P0_NODE_H
