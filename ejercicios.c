#include <stdio.h>

typedef struct s_complex
{
    // x;
    double real;
    //y;
    double imaginary;
}   t_complex;

int main()
{
    t_complex   z;
    t_complex   c;
    double  tem;
    int i;

    z.real = 0;
    z.imaginary = 0;
    c.real = 0.25;
    c.imaginary = 0.4;

    i = 0;
    while(i < 42)
    {
        //General formula
        // z = z² + c
        tem = (z.real * z.real) - (z.imaginary * z.imaginary);
        z.imaginary = 2 * z.real * z.imaginary;
        z.real = tem;

        //adding the c value 
        z.real += c.real;
        z.imaginary += c.imaginary;
        printf("iteration n -> %d real %f imaginary%f\n", i, z.real, z.imaginary);
        ++i;
    }
}

