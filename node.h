//
// Created by mlind on 2/10/2019.
//

#ifndef P0_NODE_H
#define P0_NODE_H


typedef struct node
{
    int setCount;
    struct node * leftChild;
    struct node * rightChild;
    char  * dataArray[]; // this grows dynamically so it must be and the end of struct

} node;

#endif //P0_NODE_H
