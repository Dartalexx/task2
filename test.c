#include "stdio.h"
extern int squaring(int);
extern double square_root(int);
//функции для double
extern double double_squaring(double);
extern double double_square_root(double);
//функции для float
extern double float_squaring(float);
extern double float_square_root(float);

int main()
{

    int num1 = 16;
    printf("Int\nNumber is %d\nSquare is %d\nRoot is %.2f\n", num1, squaring(num1), square_root(num1));
    double num2 = 15.2;
    printf("\nFloat\nNumber is %.2f\nSquare is %.2f\nRoot is %.2f\n", num2, double_squaring(num2), double_square_root(num2));
    float num3 = 5.732;
    printf("\nDouble\nNumber is %.2f\nSquare is %.2f\nRoot is %.2f\n", num3, float_squaring(num3), float_square_root(num3));
    return 0;
}