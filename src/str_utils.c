//
// Created by akaan on 24.04.2023.
//

#include "../inc/str_utils.h"

static char checkLetter(const char c){
    for (int i = 65; i <= 90; ++i) {
        if(c == i) return (char)(i+32);
    }
    return c;
}

char* strLower(const char* str){
    if(str==null) return str;
    size_t len = strlen(str);
    char *pc = (char*) calloc(len+1, sizeof(char));
    if(pc == null) return null;
    for (int i = 0; i < len; ++i) {
        pc[i] = checkLetter(str[i]);
    }
    pc[len] = '\0';
    return pc;
}