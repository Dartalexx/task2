#include "stdio.h"
#include <dlfcn.h>
#include <string.h>
#include <math.h>
extern double squaring(int);
extern double square_root(int);
//функции для double
extern double double_squaring(double);
extern double double_square_root(double);
//функции для float
extern double float_squaring(float);
extern double float_square_root(float);

int main(int argc, char* argv[])
{   
    //handler
    void *lib_handler; 
    //открываем библиотеку для использования
    lib_handler = dlopen("libsquaredynamic.so",RTLD_LAZY);
    //проверка на ошибки
    if (!lib_handler)
    {
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
		return 1;
	};

    //указатели на функции разных типов из библиотеки
    double (*func_int)(int x);
    double (*func_double)(double x);
    double (*func_float)(float x);

    //Вызов функций для работы с int 
    int num1 = 16;
    func_int=dlsym(lib_handler, "squaring");
    printf("\n\nTest program:\n");
    printf("\nInt\nNumber is %d\nSquare is %.0f", num1, (*func_int)(num1));
    func_int=dlsym(lib_handler, "square_root");
    printf("\nRoot is %.2f\n", (*func_int)(num1));

    //Вызов функций для работы с double
    double num2 = 15.2;
    func_double=dlsym(lib_handler, "double_squaring");
    printf("\nFloat\nNumber is %.2f\nSquare is %.2f\n", num2, (*func_double)(num2));
    func_double=dlsym(lib_handler, "double_square_root");
    printf("Root is %.2f\n", (*func_double)(num2));

    //Вызов функций для работы с float 
    float num3 = 5.732;
    func_float=dlsym(lib_handler, "float_squaring");
    printf("\nDouble\nNumber is %.2f\nSquare is %.2f\n", num3, (*func_float)(num3));
    func_float=dlsym(lib_handler, "float_square_root");
    printf("Root is %.2f\n", (*func_float)(num3));
    
    //Закрываем библиотеку
    dlclose(lib_handler);
    return 0;
}