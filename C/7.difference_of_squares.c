// difference_of_squares.h

#ifndef DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_H

unsigned int sum_of_squares(unsigned int number);
unsigned int square_of_sum(unsigned int number);
unsigned int difference_of_squares(unsigned int number);

#endif

// difference_of_squares.c

#include "difference_of_squares.h"
#include "math.h"

unsigned int sum_of_squares(unsigned int number){
    unsigned int sum_squares = 0;

    for (int i=1; (unsigned)i<=number;i++){
        sum_squares += (unsigned int)pow(i, 2);
    }
    return sum_squares;
}
unsigned int square_of_sum(unsigned int number){
    unsigned int sum = 0;

    for (int i=1; (unsigned)i<=number;i++){
        sum += i;
    }
    return (unsigned int)pow(sum, 2);
}

unsigned int difference_of_squares(unsigned int number){
    return (unsigned int) (square_of_sum(number) - sum_of_squares(number));
}
