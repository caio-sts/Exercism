// luhn.h

#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool luhn(const char *num);

#endif


// luhn.c

#include "luhn.h"
#include "string.h"

bool luhn(const char *num){
    int n = 0;
    int j = 0;
    for (int i=0; i<(int)strlen(num); i++){
        if (num[i] != ' ' && (num[i] < '0' || num[i] > '9')){
            return false;
        }
        else if (num[i] != ' '){
            n++;
        }
    }
    int sum_of_digits = 0;
    if (n <= 1){
        return false;
    }

    char str[n];   
    j = 0;

    for (int k=0;k<n;k++){
        while(num[j] == ' '){
            j++;
        }
        str[k] = num[j];
        j++;
    }
    
    // double multiples of the second position starting from right
    for (int i=n-2; i>=0;i=i-2){
        if ((str[i]-'0')*2 > 9){
            str[i] = ((str[i]-'0')*2 - 9)+'0';
            
        }
        else{
            str[i] = ((str[i]-'0')*2)+'0';
        }
    }
    
    for (int i=0; i<n; i++){
        sum_of_digits+= (str[i]-'0');
    }
    
    if (sum_of_digits%10 == 0){
        return true;
    }
   
    return false;
}
