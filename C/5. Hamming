// hamming.h

#ifndef HAMMING_H
#define HAMMING_H

int compute(const char *lhs, const char *rhs);

#endif


// hamming.c

#include "hamming.h"
#include "string.h"

int compute(const char *lhs, const char *rhs){
    int n1 = strlen(lhs);
    int n2 = strlen(rhs);

    if (n1 == 0 && n2 == 0){
        return 0;
    }
    
    else if ((n1 != n2) || n1 == 0 || n2 == 0 ){
        return -1;
    }
    
    int ham_distance = 0;
    
    
    for (int i=0; i<n1;i++){
        if(lhs[i] != rhs[i]){
            ham_distance += 1;
        }
    }    
    return ham_distance;
}
