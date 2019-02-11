//
// Created by mlind on 2/10/2019.
//

#include <stddef.h>
#include <stdio.h>
#include "traversals.h"

void inOrder(node *root)
{
    node *cursor, *pre;

    if(root == NULL)
        return;

    cursor = root;

    printf("  %s\n", cursor->dataArray[0]);

    while(cursor != NULL)
    {
        if(cursor->leftChild != NULL)
        {

            cursor = cursor->rightChild;
            printf("1  %s\n", cursor->dataArray[0]);

        }
        else
        {
            pre = cursor->leftChild;

            while(pre->rightChild != NULL && pre->rightChild != cursor)
                pre = pre->rightChild;

            if (pre->rightChild != NULL)
            {
                pre->rightChild = cursor;
                cursor = cursor->leftChild;
                printf("2  %s\n", cursor->dataArray[0]);

            }
            else
            {
                pre->rightChild = NULL;
                cursor = cursor->rightChild;
                printf("3  %s\n", cursor->dataArray[0]);

            }
        }
    }
}