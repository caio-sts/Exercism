// binary_search.h

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#define EON EOF

#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

const int *binary_search(int value, const int *arr, size_t length);

#endif


// binary_search.c

#include "binary_search.h"


const int *binary_search(int value, const int *arr, size_t length){
    if (length == 0){
        return NULL;
    }
    int low = 0;
    int high = length - 1;
    while (low<=high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == value)
      return &arr[mid];

    else if (arr[mid] < value)
      low = mid + 1;
        
    else
      high = mid - 1;
  }
    return NULL;
}
