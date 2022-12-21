// grains.h

#ifndef GRAINS_H
#define GRAINS_H

#include <stdint.h>

uint64_t square(uint8_t index);
uint64_t total(void);

#endif

// grains.c

#include "grains.h"
#include "math.h"


uint64_t total(void){
    uint64_t total_grains = 0;
    for (int i=1;i<=65;i++){
        total_grains += square(i);
    }
    return total_grains;
}

uint64_t square(uint8_t index){
    return (uint64_t)pow(2, index-1);
}
