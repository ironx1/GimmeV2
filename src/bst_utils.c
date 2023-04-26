//
// Created by akaan on 24.04.2023.
//

#include "../inc/bst_utils.h"
#include <string.h>
#define null ((void*)0)

COMPARE_NUM(int)
COMPARE_NUM(float)

PRINT_NUM(d, int)
PRINT_NUM(f, float)

int compare_str(void* fStr, void* sStr){
    return strcmp((char*)fStr, (char*)sStr);
}

void print_str(void* data, FILE* file){
    if(file == null) printf("%s ", (char*)data);
    else fprintf(file, "%s\n", (char*)data);
}
