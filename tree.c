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

static int isInSet(node * node,  char * data){
    int i = 0;
    for (i=0; i < node->setCount; i++){
        if( !strcmp(data, node->dataArray[i]))
            return 1;
    }
    return 0;
}

/*
    adds word to set
    no duplicates
 */

static void appendDataToSet(node * node, char * data){
    if(node->setCount > 0)
        if( isInSet(node, data) )
            exit(0);
    size_t numberOfChars = strlen(data);
    size_t size = sizeof( char *) * (++node->setCount);//new size of array and size effect: increment count
    if (node->setCount == 1){ assert(node->setCount == 1); // does char work instead of char*
       *node->dataArray = malloc(size);
        node->dataArray[0] = malloc(numberOfChars);
        strncpy(node->dataArray[0], data, numberOfChars);
    } else {
        *node->dataArray = realloc(*node->dataArray, size);
        node->dataArray[node->setCount] = malloc(numberOfChars);
        strncpy(node->dataArray[node->setCount], data, numberOfChars);

    }

}

/*
    create a new node
*/
node* createNode(char * data )
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
node* insertNode(node *root,  char * data) {

    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    int sem = 0; // comparison flag
    char currentNodeData, newData;
    node * currentNode = root;
    node * parentNode = NULL;

    newData = data[0];
    while (currentNode != NULL) {
        currentNodeData = currentNode->dataArray[0][0];
        sem = compare(currentNodeData, newData);
        parentNode = currentNode;
        if (sem == 0) {
            appendDataToSet(currentNode, data);
            return root;
        }
        if (sem < 0)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;
    }
    if (sem < 0)
        parentNode->leftChild = createNode(data);
    else
        parentNode->rightChild = createNode(data);


    return root;
}