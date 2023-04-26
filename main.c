//
// Created by akaan on 24.04.2023.
//
#include "inc/lib_bst.h"
#include "inc/str_utils.h"
#include <string.h>

int main(int argc, const char* argv[]){
    if(argc<2){
        printf("use -p to print\n-w to write\n-r to read");
        return 1;
    }
    Tree *bst = newBST();
    if(!strcmp(argv[1], "-p")){
        if(!strcmp(argv[argc-1], "-str")){
            for (int i = 2; i < argc-1; ++i) {
                char *str = strLower(argv[i]);
                insertNode(bst, str, compare_str);
            }
            printInorder(bst, null, print_str);
            clear(bst);
        }
        else if(!strcmp(argv[argc-1], "-int")){
            for (int i = 2; i < argc-1; ++i) {
                int* pi = (int*) malloc(sizeof (int));
                if(pi == null) break;
                *pi = atoi(argv[i]);
                insertNode(bst, pi, compare_int);
            }
            printInorder(bst, null, print_int);
            clear(bst);
        }
        else if(!strcmp(argv[argc-1], "-flt")){
            for (int i = 2; i < argc-1; ++i) {
                float *pf = (float *) malloc(sizeof(float));
                if(pf == null) break;
                *pf = atof(argv[i]);
                insertNode(bst, pf, compare_float);
            }
            printInorder(bst, null, print_float);
            clear(bst);
        }
        else return 1;
    }
    else if(!strcmp(argv[1], "-w")){
        FILE *wFile = fopen(argv[2], "w");
        if(!strcmp(argv[argc-1], "-str")){
            for (int i = 3; i < argc-1; ++i) {
                char* str = strLower(argv[i]);
                if(str == null) break;
                insertNode(bst, str, compare_str);
            }
            printInorder(bst, wFile, print_str);
            clear(bst);
            fclose(wFile);
        }
        else if(!strcmp(argv[argc-1], "-int")){
            for (int i = 3; i < argc-1; ++i) {
                int *pi = (int*) malloc(sizeof(int));
                if(pi == null) break;
                *pi = atoi(argv[i]);
                insertNode(bst, pi, compare_int);
            }
            printInorder(bst, wFile, print_int);
            clear(bst);
            fclose(wFile);
        }
        else if(!strcmp(argv[argc-1], "-flt")){
            for (int i = 3; i < argc-1; ++i) {
                float *pf = (float *) malloc(sizeof (float));
                if(pf == null) break;
                *pf = atof(argv[i]);
                insertNode(bst, pf, compare_float);
            }
            printInorder(bst, wFile, print_float);
            clear(bst);
            fclose(wFile);
        }
        else return 1;
    }
    else if(!strcmp(argv[1], "-r")){
        FILE *wFile = fopen(argv[argc-2], "w");
        FILE *rFile = fopen(argv[2],"r");
        if(!strcmp(argv[argc-1], "-str")){
            char buffer[25];
            while (fgets(buffer, 25, rFile)){
                char *str = strLower(buffer);
                insertNode(bst, str, compare_str);
            }
            printInorder(bst, wFile, print_str);
            clear(bst);
            fclose(wFile);
            fclose(rFile);
        }
        else if(!strcmp(argv[argc-1], "-int")){
            char buffer[8];
            while (fgets(buffer, 6, rFile)){
                int *pi = (int*) malloc(sizeof(int));
                if(pi == null) break;
                *pi = atoi(buffer);
                insertNode(bst, pi, compare_int);
            }
            printInorder(bst, wFile, print_int);
            clear(bst);
            fclose(wFile);
            fclose(rFile);
        }
        else if(!strcmp(argv[argc-1], "-flt")){
            char buffer[20];
            while (fgets(buffer, 20, rFile)){
                float *pf = (float*) malloc(sizeof(float));
                if(pf == null) break;
                *pf = atof(buffer);
                insertNode(bst, pf, compare_float);
            }
            printInorder(bst, wFile, print_float);
            clear(bst);
            fclose(rFile);
            fclose(wFile);
        }
        else {
            free(bst);
            return 1;
        }
    }
    return 0;
}
