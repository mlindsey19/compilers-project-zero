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
        return -1;
    if(left < right)
        return 1;
    return 0; // equal
}

static int isInSet(node * node,  char * data){
    int i;
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
    if(node->setCount == 0 || !isInSet(node, data) )
            strcpy(node->dataArray[node->setCount++], data);
}

/*
    create a new node
*/
node* createNode(char * data)
{
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    newNode->setCount = 0;
    newNode->depth = 0;
    appendDataToSet(newNode, data);

    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

/*
    insert a new node into the BST
*/
node* insertNode(node *insRoot,  char * data) {

    if (insRoot == NULL) {
        insRoot = createNode(data);
        return insRoot;
    }
    int depthOfNode = 0;

    int sem = 0; // comparison flag
    char currentNodeData, newData;
    node * currentNode = insRoot;
    node * parentNode = NULL;

    newData = data[0]; //first char
    while (currentNode != NULL) {
        currentNodeData = currentNode->dataArray[0][0];
        sem = compare(currentNodeData, newData);
        parentNode = currentNode;
        if (sem == 0) {
            appendDataToSet(currentNode, data);
            currentNode->depth = depthOfNode;
            return insRoot;
        }
        depthOfNode++;
        if (sem < 0)
            currentNode = currentNode->leftChild;
        else
            currentNode = currentNode->rightChild;

    }
    if (sem < 0) {
        parentNode->leftChild = createNode(data);
        parentNode->leftChild->depth = depthOfNode;
    }else {
        parentNode->rightChild = createNode(data);
        parentNode->rightChild->depth = depthOfNode;
    }

    return insRoot;
}