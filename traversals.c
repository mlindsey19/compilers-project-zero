//
// Created by mlind on 2/10/2019.
//

#include <stddef.h>
#include <stdio.h>
#include "traversals.h"

static void printNode(node *node ){
    int i;
    for (i = 0; i < node->depth; i++)
        printf("  ");
    for (i = 0; i < node->setCount; i++)
        printf("%s ", node->dataArray[i]);
    putchar('\n');

}

void inOrder(node *node)
{
    if ( node->leftChild != NULL )
        inOrder(node->leftChild);
    printNode(node);
    if (node->rightChild != NULL)
        inOrder(node->rightChild);
}
void preOrder(node *node)
{
    printNode(node);
    if ( node->leftChild != NULL )
        preOrder(node->leftChild);
    if (node->rightChild != NULL)
        preOrder(node->rightChild);
}
void postOrder(node *node)
{
    if ( node->leftChild != NULL )
        postOrder(node->leftChild);
    if (node->rightChild != NULL)
        postOrder(node->rightChild);
    printNode(node);
}