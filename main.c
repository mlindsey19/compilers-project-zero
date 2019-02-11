//Mitch Lindsey
//cs4280
//2-5-19
//



#include <stdio.h>
#include <assert.h>

#include "checkArgs.h"

int main (int argc, char **argv){

    printf("%i\n",argc);
    checkArgs( argc, argv);

    if (argc > 2){
        perror("too many arguments");
    }
    if (argc == 1){
        char  ch[32] ="";
        int eoff = 0; //end of file flag
        FILE * fp = fopen("P0_test3.input1", "r");
        if (!fp) {
            perror("rf: could not open file");
            return 1;
        }
        while (eoff >= 0) {
            eoff = fscanf(fp, "%s", ch); // fail returns neg number to eoff
            printf("%s\n", ch);
        }
    }

    return 0;
}