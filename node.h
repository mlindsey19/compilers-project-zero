//
// Created by mlind on 2/10/2019.
//

#ifndef P0_NODE_H
#define P0_NODE_H


typedef struct node
{
    char ** dataArray;
    int setCount;
    struct node* leftChild;
    struct node* rightChild;
} node;

#endif //P0_NODE_H
