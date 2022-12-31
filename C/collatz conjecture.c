// collatz_conjecture.h

#ifndef COLLATZ_CONJECTURE_H
#define COLLATZ_CONJECTURE_H

#define ERROR_VALUE -1

int steps(int start);

#endif

// collatz_conjecture.c

#include "collatz_conjecture.h"

int steps(int start){
    if (start <= 0){
        return -1;
    }
    
    int num_steps = 0;

    while( start != 1){
        if(start%2==0){
            start /=2;
        }
        else{
            start= start*3 +1;
        }
        num_steps++;
    }
    
   return num_steps; 
}
