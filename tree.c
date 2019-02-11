//Mitch Lindsey
//cs4280
//2-5-19
//


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <assert.h>
#include "tree.h"

/*
    compare two char
    case is not important so
    both are cast to lower case
*/
static int compare(char left,char right)
{
    left = (char) tolower(left);
    right = (char) tolower(right);
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0; // equal
}

/*
    adds word to set
    no duplicates
 */

static void appendDataToSet(node * node, char *data){
    size_t numberOfChars = strlen(data);
    size_t size = sizeof( char *) * (++node->setCount);//new size of array and size effect: increment count
    if (node->setCount == 0){ assert(node->setCount == 1);
        node->dataArray = malloc(size);
        node->dataArray[0] = malloc(numberOfChars);
        node->dataArray[0] = data;
    } else {
        node->dataArray = realloc(node->dataArray, size);
        node->dataArray[node->setCount] = data;

    }

}

/*
    create a new node
*/
node* createNode(char* data )
{
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    new_node->setCount = 0;
    appendDataToSet(new_node, data);
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    return new_node;
}

/*
    insert a new node into the BST
*/
node* insertNode(node *root,  char * data)
{

    if(root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        int sem  = 0; // comparison flag
        char currentNodeData, newData;
        node* cursor = root;
        node* prev   = NULL;

        newData = data[0];

        while(cursor != NULL)
        {
            currentNodeData = cursor->dataArray[0][0];
            sem = compare(currentNodeData,newData);
            prev = cursor;
            if(sem < 0)
            {
                cursor = cursor->leftChild;
                prev->leftChild = createNode(data);

            }
            else if(sem > 0)
            {
                cursor = cursor->rightChild;
                prev->rightChild = createNode(data);

            }

        }

    }
    return root;
}