// complex_numbers.h

#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

typedef struct {
   double real;
   double imag;
} complex_t;

complex_t c_add(complex_t a, complex_t b);
complex_t c_sub(complex_t a, complex_t b);
complex_t c_mul(complex_t a, complex_t b);
complex_t c_div(complex_t a, complex_t b);
double c_abs(complex_t x);
complex_t c_conjugate(complex_t x);
double c_real(complex_t x);
double c_imag(complex_t x);
complex_t c_exp(complex_t x);

#endif


// complex_numbers.c

#include "complex_numbers.h"
#include "math.h"


complex_t c_add(complex_t a, complex_t b)
{
   complex_t complex;
    complex.real = a.real + b.real;
    complex.imag = a.imag + b.imag;
    return complex;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t complex;
    complex.real = a.real - b.real;
    complex.imag = a.imag - b.imag;
    return complex;
}

complex_t c_mul(complex_t a, complex_t b)
{
   complex_t complex;
    complex.real = a.real * b.real - a.imag * b.imag;;
    complex.imag = a.real * b.imag + a.imag * b.real;
    return complex;
}

complex_t c_div(complex_t a, complex_t b)
{
   complex_t complex;
    double mod_b = pow(b.real, 2) + pow(b.imag, 2); 
    complex.real = (a.real * b.real + a.imag * b.imag) / mod_b;
    complex.imag = (-a.real * b.imag + a.imag * b.real) / mod_b;
    return complex;
}

double c_abs(complex_t x)
{
    return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}

complex_t c_conjugate(complex_t x)
{
   complex_t complex = x; 
    complex.imag = -complex.imag;
    return complex;
}

double c_real(complex_t x)
{
   return x.real;
}

double c_imag(complex_t x)
{
   return x.imag;
}

complex_t c_exp(complex_t x)
{
   complex_t complex;
    complex.real = (exp(x.real))*cos(x.imag);
    complex.imag = (exp(x.real))*sin(x.imag);
    return complex;
}
