// isogram.h

#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>

bool is_isogram(const char phrase[]);

#endif


// isogram.c

#include "isogram.h"
#include <stddef.h>
#include <ctype.h> 

bool is_isogram(const char phrase[]){
    if (phrase == NULL){
        return false;
    }
    
    int n = 0;
    
    while(phrase[n] != '\0'){
        n+=1;
    }

    for (int i=0; i<n-1;i++){
        if ((phrase[i] >= 'a' && phrase[i] <= 'z') || (phrase[i] >= 'A' && phrase[i] <= 'Z') ){
            for (int j=i+1;j<n;j++){
                if (tolower(phrase[i]) == tolower(phrase[j])){
                    return false;
                }
            }
        }
    }
    return true;
}
