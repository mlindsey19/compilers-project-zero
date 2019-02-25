//
// Created by mlind on 2/10/2019.
//

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "traversals.h"


static void printNode(node *node){
    int i;
    if(strlen(node->dataArray[0]) == 0 )
        fprintf(outFilePtr,"File was empty");
    for (i = 0; i < node->depth; i++)
        fprintf(outFilePtr, "  ");
    for (i = 0; i < node->setCount; i++)
        fprintf(outFilePtr, "%s ", node->dataArray[i]);
    fputc( '\n', outFilePtr);

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