//Mitch Lindsey
//cs4280
//2-5-19
//



#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "tree.h"
#include "traversals.h"

FILE * outFilePtr;

int main (int argc, char **argv){

    char ext[] = ".input1\0";
    char infile[32] = "out.input1\0";


    if (argc > 2){
        perror("too many arguments");
    }

    node * root = NULL;
    FILE * fp;

    if (argc == 1)
        fp = stdin;
    else {
        strcpy(infile,argv[1]);
        char *pos = strstr(infile, ext);
        if(pos == NULL)
            strcat(infile,ext);
        strcat(infile, "\0");
        fp = fopen(infile, "r");
    }

    char  ch[32] ="\0";
    int eoff = 0; //end of file flag
    if (!fp) {
        perror("rf: could not open file");
        return 1;
    }
    while (eoff >= 0) {
        eoff = fscanf(fp, "%s", ch); // fail returns neg number to eoff
        root = insertNode(root, ch);
    }

    fclose(fp);

    size_t x = strlen(infile) - strlen(ext);
    char outfileInOrd[32];
    char outfilePreOrd[32];
    char outfilePostOrd[32];

    strncpy(outfilePostOrd,infile, x);
    strncpy(outfileInOrd,infile, x);
    strncpy(outfilePreOrd,infile, x);

   outfileInOrd[x ] = NULL;
    outfilePostOrd[x ] = NULL;
    outfilePreOrd[x ] = NULL;

    strcat(outfileInOrd, ".inorder\0");
    strcat(outfilePreOrd, ".preorder\0");
    strcat(outfilePostOrd, ".postorder\0");

    outFilePtr = fopen(outfileInOrd, "w");
    inOrder(root);
    fclose(outFilePtr);

    outFilePtr = fopen(outfilePreOrd, "w");
    preOrder(root);
    fclose(outFilePtr);

    outFilePtr = fopen(outfilePostOrd, "w");
    inOrder(root);
    fclose(outFilePtr);

    return 0;
}