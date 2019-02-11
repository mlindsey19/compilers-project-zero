//
// Created by mlind on 2/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "buildTree.h"
#include "node.h"


node* create_node(int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}