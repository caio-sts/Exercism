#include "armstrong_numbers.h"
#include <math.h>


bool is_armstrong_number(int candidate){
    // Find number of digits
    int num = candidate;
    int num_digits = 0;
    while(num != 0){
        num /= 10;  
        num_digits += 1; 
    }

    // Calculate sum powered of digits
    int next_numb_check = candidate;
    int result_number = 0;

    while (next_numb_check != 0){
        result_number += pow(next_numb_check%(10), num_digits);
        next_numb_check /= 10;
    };

    if (candidate == result_number){
        return true;
    }
    return false;
}
