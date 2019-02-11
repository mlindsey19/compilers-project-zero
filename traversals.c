//
// Created by mlind on 2/10/2019.
//

#include <stddef.h>
#include <stdio.h>
#include "traversals.h"

void inOrder(node *root)
{
    node *curentNode, *parentNode;

    if(root == NULL)
        return;

    curentNode = root;

    printf("  %s\n", curentNode->dataArray[0]);

    while(curentNode != NULL)
    {
        if(curentNode->leftChild != NULL)
        {

            curentNode = curentNode->rightChild;
            printf("1  %s\n", curentNode->dataArray[0]);

        }
        else
        {
            parentNode = curentNode->leftChild;

            while(parentNode->rightChild != NULL && parentNode->rightChild != curentNode)
                parentNode = parentNode->rightChild;

            if (parentNode->rightChild != NULL)
            {
                parentNode->rightChild = curentNode;
                curentNode = curentNode->leftChild;
                printf("2  %s\n", curentNode->dataArray[0]);

            }
            else
            {
                parentNode->rightChild = NULL;
                curentNode = curentNode->rightChild;
                printf("3  %s\n", curentNode->dataArray[0]);

            }
        }
    }
}