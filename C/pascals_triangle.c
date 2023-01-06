// pascals_triangle.h

#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stddef.h>
#include <stdint.h>

void free_triangle(uint8_t **triangle, size_t rows);
uint8_t **create_triangle(size_t rows);

#endif

//pascals_triangle.c

#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows){
    for (size_t i=0; i<rows; i++){
        free(triangle[i]);
        triangle[i] = NULL;
    }
    free(triangle);
    triangle = NULL;
}
uint8_t **create_triangle(size_t rows){
    uint8_t **triangle = (uint8_t **)malloc(rows * sizeof(uint8_t*));
    if (rows == 0){
        triangle[0] = calloc(1, sizeof(uint8_t));
        return triangle;
    }
    for(size_t i = 0; i < rows; i++){
        *(triangle+i) = (uint8_t *)malloc(rows * sizeof(uint8_t));
    }
    
    for (size_t i=0; i<rows;i++){
        for (size_t j=0;j<rows;j++){
            if (j==0){
                *(*(triangle+i)+j) = (uint8_t)1;
            }
            else if(i==0){
                *(*(triangle+i)+j) = (uint8_t)0;
            }
            else{
                *(*(triangle+i)+j) = *(*(triangle+i-1)+j) + *(*(triangle+i-1)+j-1);
            }
        }
    }
    return triangle;
}
