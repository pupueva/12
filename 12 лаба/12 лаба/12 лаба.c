//12 лаба
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#define CRT_NO_SECURE_DEPRECATE


int main() {
    setlocale(LC_CTYPE, "RUS");
    // Исследование выделенной памяти под указатели различных типов
    char* pc;
    int* pi;
    double* pd;

    printf("Размер памяти для указателя на char: %lu байт\n", sizeof(pc));
    printf("Размер памяти для указателя на int: %lu байт\n", sizeof(pi));
    printf("Размер памяти для указателя на double: %lu байт\n", sizeof(pd));

    // Работа с указателями на float
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;

    printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
    printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);

    // Инкремент указателя int
    int x = 5, * pa = &x;
    printf("По адресу %p хранится *pa=%d\n", pa, *pa);
    pa++;
    printf("После инкремента указателя: %p\n", pa);
    pa--;
    printf("После декремента указателя: %p\n", pa);

    // Изменение типа на double и char для указателя
    double dx = 3.14, * pd_ptr = &dx;
    printf("По адресу %p хранится *pd_ptr=%g\n", pd_ptr, *pd_ptr);
    pd_ptr++;
    printf("После инкремента указателя double: %p\n", pd_ptr);

    char ch = 'A', * pc_ptr = &ch;
    printf("По адресу %p хранится *pc_ptr=%c\n", pc_ptr, *pc_ptr);
    pc_ptr++;
    printf("После инкремента указателя char: %p\n", pc_ptr);

    // Исследование типа long double, short unsigned int, _Bool
    long double ld = 1.2345678901234567L, * pld = &ld;
    printf("По адресу %p хранится *pld=%Lf\n", pld, *pld);
    pld++;
    printf("После инкремента указателя long double: %p\n", pld);

    short unsigned int sui = 100, * psui = &sui;
    printf("По адресу %p хранится *psui=%d\n", psui, *psui);
    psui++;
    printf("После инкремента указателя short unsigned int: %p\n", psui);

    _Bool b = 1, * pb = &b;
    printf("По адресу %p хранится *pb=%d\n", pb, *pb);
    pb++;
    printf("После инкремента указателя _Bool: %p\n", pb);

    // Перемещение по массиву с указателем
    float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
    float* ptr_a = array;

    printf("Адрес array: %p, &array[0]: %p, &array: %p\n", array, &array[0], &array);
    printf("Начало массива: %p, значение: %.2f\n", ptr_a, *ptr_a);
    ptr_a++;
    printf("После ptr_a++: %p, значение: %.2f\n", ptr_a, *ptr_a);
    ptr_a += 4;
    printf("После ptr_a+4: %p, значение: %.2f\n", ptr_a, *ptr_a);
    ptr_a -= 2;
    printf("После ptr_a-2: %p, значение: %.2f\n", ptr_a, *ptr_a);

    // Проход по массиву указателем с шагом 2
    printf("Прямой проход с увеличением указателя на 2:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("Адрес: %p, значение: %.2f\n", &array[i], array[i]);
    }

    // Обратный проход по массиву
    ptr_a = &array[9];
    printf("Обратный проход:\n");
    for (int i = 9; i >= 0; i--) {
        printf("Адрес: %p, значение: %.2f\n", &array[i], array[i]);
    }

    // Побайтовый вывод целого числа
    int x_test = 0x12345678;
    int* ptr_x = &x_test;
    unsigned char* a = (unsigned char*)ptr_x;

    printf("Побайтовый вывод числа 0x12345678:\n");
    printf("%.2x %.2x %.2x %.2x\n", a[3], a[2], a[1], a[0]);

    // Определение порядка байтов
    if (a[0] == 0x78) {
        printf("Система использует порядок little-endian.\n");
    }
    else {
        printf("Система использует порядок big-endian.\n");
    }

    // Вывод значений различных типов данных (без sizeof и констант)
    int int_var;
    char char_var;
    short int short_int_var;
    unsigned short int ushort_int_var;
    unsigned char uchar_var;
    wchar_t wchar_var;
    long long int long_long_var;
    size_t size_var;
    float float_var;
    double double_var;
    signed int signed_int_var;

    printf("Размер int: %lu байт\n", (char*)(&int_var + 1) - (char*)&int_var);
    printf("Размер char: %lu байт\n", (char*)(&char_var + 1) - (char*)&char_var);
    printf("Размер short int: %lu байт\n", (char*)(&short_int_var + 1) - (char*)&short_int_var);
    printf("Размер unsigned short int: %lu байт\n", (char*)(&ushort_int_var + 1) - (char*)&ushort_int_var);
    printf("Размер unsigned char: %lu байт\n", (char*)(&uchar_var + 1) - (char*)&uchar_var);
    printf("Размер wchar_t: %lu байт\n", (char*)(&wchar_var + 1) - (char*)&wchar_var);
    printf("Размер long long int: %lu байт\n", (char*)(&long_long_var + 1) - (char*)&long_long_var);
    printf("Размер size_t: %lu байт\n", (char*)(&size_var + 1) - (char*)&size_var);
    printf("Размер float: %lu байт\n", (char*)(&float_var + 1) - (char*)&float_var);
    printf("Размер double: %lu байт\n", (char*)(&double_var + 1) - (char*)&double_var);
    printf("Размер signed int: %lu байт\n", (char*)(&signed_int_var + 1) - (char*)&signed_int_var);

    return 0;
}
