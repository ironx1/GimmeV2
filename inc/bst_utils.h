//
// Created by akaan on 24.04.2023.
//

#ifndef GIMMEV2_LIB_UTILS_H
#define GIMMEV2_LIB_UTILS_H
#include <stdio.h>

#define COMPARE_NUM(type) \
int compare_##type(void* fPtr, void* sPtr){ \
    if(*(type*)fPtr > *(type*)sPtr) return 1; \
    if(*(type*)fPtr == *(type*)sPtr) return 0;\
    if(*(type*)fPtr < *(type*)sPtr) return -1;\
}

#define PRINT_NUM(format, type) \
void print_##type(void* data, FILE* file){\
    if(file == null) printf("%"#format" ", *(type*)data); \
    else fprintf(file, "%"#format"\n", *(type*)data);\
}

typedef int (*funCompare)(void*, void*);
typedef void (*funPrint)(void*, FILE*);
int compare_int(void*, void*);
int compare_float(void*,void*);
int compare_str(void*, void*);
void print_int(void*, FILE*);
void print_float(void*, FILE*);
void print_str(void*, FILE*);
#endif //GIMMEV2_LIB_UTILS_H
