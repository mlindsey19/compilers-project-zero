//Mitch Lindsey
//cs4280
//2-5-19
//
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "checkArgs.h"

static void helpMenu(){
    printf("/\n    Help\n");
    printf("-h show help menu\n");
    printf("//\n");
    printf("//some more stuff here\n");
}

int checkArgs( int argc, char **argv) {

    int c,i;

    opterr = 0;

    while ( (c = getopt(argc, argv, "h")) != -1)
        switch (c) {
            case 'h':
                helpMenu();
                break;
            case '?':
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                abort();
        }
    for (i = optind; i < argc; i++)
        printf("Non-option argument: %s\n", argv[i]);

    return 0;
}