// rational_numbers.h

#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include "math.h"

typedef struct{
    int numerator;
    int denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r1);
rational_t exp_rational(rational_t r1, int n);
float exp_real(float r, rational_t r2);
rational_t reduce(rational_t r1);
int gcd(int a, int b);

#endif

// rational_numbers.c

#include "rational_numbers.h"


int gcd(int a, int b)
{
    if (a < 0){
        a *= -1;
    }
    if (b < 0){
        b *= -1;
    }
    while (b != 0)
    {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return a;
}



rational_t add(rational_t r1, rational_t r2){
    r1 = reduce(r1);
    r2 = reduce(r2);
    rational_t r;
    r.numerator = (r1.numerator*r2.denominator + r1.denominator*r2.numerator);
    r.denominator = (r1.denominator * r2.denominator);
    return reduce(r);
}

rational_t subtract(rational_t r1, rational_t r2){
    r1 = reduce(r1);
    r2 = reduce(r2);
    rational_t r;
    r.numerator = (r1.numerator*r2.denominator - r1.denominator*r2.numerator);
    r.denominator = (r1.denominator * r2.denominator);
    return reduce(r);
}

rational_t multiply(rational_t r1, rational_t r2){
    r1 = reduce(r1);
    r2 = reduce(r2);
    rational_t r;
    r.numerator = r1.numerator*r2.numerator;
    r.denominator = r1.denominator*r2.denominator;
    return reduce(r);
}

rational_t divide(rational_t r1, rational_t r2){
    r1 = reduce(r1);
    r2 = reduce(r2);
    rational_t r;
    r.numerator = r1.numerator*r2.denominator;
    r.denominator = r1.denominator*r2.numerator;
    return reduce(r);
}

rational_t absolute(rational_t r1){
    rational_t r = reduce(r1);
    if (r.numerator < 0){
        r.numerator *= -1;
    }
    return r;
}

rational_t exp_rational(rational_t r1, int n){
    rational_t r = reduce(r1);
    if (n < 0){
        n *= -1;
        int temp;
        temp = r.numerator;
        r.numerator = r.denominator;
        r.denominator = temp;
    }
    r.numerator = pow(r.numerator, n);
    r.denominator = pow(r.denominator, n);
    return reduce(r);
}

float exp_real(float n, rational_t r1){
    rational_t r = reduce(r1);
    n = pow(n, r.numerator);
    n = pow(n, (float)1/r.denominator);
    return n;
}

rational_t reduce(rational_t r1){
    if (r1.denominator < 0){
        r1.denominator *= -1;
        r1.numerator *= -1;
    }
    int mdc = gcd(r1.numerator, r1.denominator);
    rational_t r = {r1.numerator/mdc, r1.denominator/mdc};
    return r;
}
