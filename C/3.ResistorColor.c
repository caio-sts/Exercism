// resistor_color.h
#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

int color_code(resistor_band_t);
const resistor_band_t* colors(void);

#endif

//resistor_color.c
#include "resistor_color.h"

int color_code(resistor_band_t c){
    return (int)c;
}

const resistor_band_t* colors(void){
static resistor_band_t resist_color[] = 
    { BLACK,
        BROWN,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
        GREY,
        WHITE
    };
    return resist_color;    
}
