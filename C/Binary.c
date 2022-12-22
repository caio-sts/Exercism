// binary.h

#ifndef BINARY_H
#define BINARY_H

#define INVALID -1
#include "math.h"


int convert(const char *input);

#endif

// binary.c

#include "binary.h"

int convert(const char *input){
    int n = 0;
    int initial_zeros_counter = 0;
    int non_initial_zeros_flag = 0;
    int pos = 0;
    while (input[pos] != '\0'){
        if (input[pos] != '1' && input[pos] != '0'){
            return -1;
        }
        if (input[pos] == '0' && non_initial_zeros_flag == 0){
             initial_zeros_counter++;   
        }
        if (input[pos] == '1' && non_initial_zeros_flag == 0){
            non_initial_zeros_flag = 1;
            n++;
        }
        else if (non_initial_zeros_flag == 1){
            n++;
        }
        pos = initial_zeros_counter + n; 
    }
    
    
    int decimal = 0;
    int coef = 0;
    for (int i=0; i<n;i++){
        coef = (int)input[i+initial_zeros_counter]-48;
        decimal += coef*pow(2, n-1-i);
    }
    return decimal;
}
