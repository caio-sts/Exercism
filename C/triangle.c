// triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdbool.h>

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

bool is_triangle(triangle_t sides);
bool is_equilateral(triangle_t sides);
bool is_isosceles(triangle_t sides);
bool is_scalene(triangle_t sides);

#endif


// triangle.c

#include "triangle.h"


bool is_triangle(triangle_t sides){
    if (sides.a == 0 || sides.b == 0 || sides.c == 0){
        return false;
    }
    else if (sides.a + sides.b < sides.c){
        return false;
    }
    else if (sides.b + sides.c < sides.a){
        return false;
    }
    else if (sides.c + sides.a < sides.b){
        return false;
    }
    return true;
}


bool is_equilateral(triangle_t sides){
    if (is_triangle(sides) != true){
        return false;
    }
    if (sides.a == sides.b && sides.b == sides.c){
        return true;
    }
    return false;
}

bool is_isosceles(triangle_t sides){
    int isosceles = 0;
    if (is_triangle(sides) != true){
        return false;
    }
    if (sides.a == sides.b ){
        isosceles += 1;
    }
    if (sides.b == sides.c){
        isosceles += 1;
    }
    if (sides.c == sides.a){
        isosceles += 1;
    }
    if (isosceles >= 1){
        return true;
    } 
    return false;
}

bool is_scalene(triangle_t sides){
    if (is_triangle(sides) != true){
        return false;
    }
    if (sides.a != sides.b && sides.b != sides.c && sides.c != sides.a){
        return true;
    }
    return false;
}
