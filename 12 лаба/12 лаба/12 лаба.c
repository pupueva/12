//12 ����
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>
#define CRT_NO_SECURE_DEPRECATE


int main() {
    setlocale(LC_CTYPE, "RUS");
    // ������������ ���������� ������ ��� ��������� ��������� �����
    char* pc;
    int* pi;
    double* pd;

    printf("������ ������ ��� ��������� �� char: %lu ����\n", sizeof(pc));
    printf("������ ������ ��� ��������� �� int: %lu ����\n", sizeof(pi));
    printf("������ ������ ��� ��������� �� double: %lu ����\n", sizeof(pd));

    // ������ � ����������� �� float
    float PI = 3.14159, * p1, * p2;
    p1 = p2 = &PI;

    printf("�� ������ p1=%p �������� *p1=%g\n", p1, *p1);
    printf("�� ������ p2=%p �������� *p2=%g\n", p2, *p2);

    // ��������� ��������� int
    int x = 5, * pa = &x;
    printf("�� ������ %p �������� *pa=%d\n", pa, *pa);
    pa++;
    printf("����� ���������� ���������: %p\n", pa);
    pa--;
    printf("����� ���������� ���������: %p\n", pa);

    // ��������� ���� �� double � char ��� ���������
    double dx = 3.14, * pd_ptr = &dx;
    printf("�� ������ %p �������� *pd_ptr=%g\n", pd_ptr, *pd_ptr);
    pd_ptr++;
    printf("����� ���������� ��������� double: %p\n", pd_ptr);

    char ch = 'A', * pc_ptr = &ch;
    printf("�� ������ %p �������� *pc_ptr=%c\n", pc_ptr, *pc_ptr);
    pc_ptr++;
    printf("����� ���������� ��������� char: %p\n", pc_ptr);

    // ������������ ���� long double, short unsigned int, _Bool
    long double ld = 1.2345678901234567L, * pld = &ld;
    printf("�� ������ %p �������� *pld=%Lf\n", pld, *pld);
    pld++;
    printf("����� ���������� ��������� long double: %p\n", pld);

    short unsigned int sui = 100, * psui = &sui;
    printf("�� ������ %p �������� *psui=%d\n", psui, *psui);
    psui++;
    printf("����� ���������� ��������� short unsigned int: %p\n", psui);

    _Bool b = 1, * pb = &b;
    printf("�� ������ %p �������� *pb=%d\n", pb, *pb);
    pb++;
    printf("����� ���������� ��������� _Bool: %p\n", pb);

    // ����������� �� ������� � ����������
    float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
    float* ptr_a = array;

    printf("����� array: %p, &array[0]: %p, &array: %p\n", array, &array[0], &array);
    printf("������ �������: %p, ��������: %.2f\n", ptr_a, *ptr_a);
    ptr_a++;
    printf("����� ptr_a++: %p, ��������: %.2f\n", ptr_a, *ptr_a);
    ptr_a += 4;
    printf("����� ptr_a+4: %p, ��������: %.2f\n", ptr_a, *ptr_a);
    ptr_a -= 2;
    printf("����� ptr_a-2: %p, ��������: %.2f\n", ptr_a, *ptr_a);

    // ������ �� ������� ���������� � ����� 2
    printf("������ ������ � ����������� ��������� �� 2:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("�����: %p, ��������: %.2f\n", &array[i], array[i]);
    }

    // �������� ������ �� �������
    ptr_a = &array[9];
    printf("�������� ������:\n");
    for (int i = 9; i >= 0; i--) {
        printf("�����: %p, ��������: %.2f\n", &array[i], array[i]);
    }

    // ���������� ����� ������ �����
    int x_test = 0x12345678;
    int* ptr_x = &x_test;
    unsigned char* a = (unsigned char*)ptr_x;

    printf("���������� ����� ����� 0x12345678:\n");
    printf("%.2x %.2x %.2x %.2x\n", a[3], a[2], a[1], a[0]);

    // ����������� ������� ������
    if (a[0] == 0x78) {
        printf("������� ���������� ������� little-endian.\n");
    }
    else {
        printf("������� ���������� ������� big-endian.\n");
    }

    // ����� �������� ��������� ����� ������ (��� sizeof � ��������)
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

    printf("������ int: %lu ����\n", (char*)(&int_var + 1) - (char*)&int_var);
    printf("������ char: %lu ����\n", (char*)(&char_var + 1) - (char*)&char_var);
    printf("������ short int: %lu ����\n", (char*)(&short_int_var + 1) - (char*)&short_int_var);
    printf("������ unsigned short int: %lu ����\n", (char*)(&ushort_int_var + 1) - (char*)&ushort_int_var);
    printf("������ unsigned char: %lu ����\n", (char*)(&uchar_var + 1) - (char*)&uchar_var);
    printf("������ wchar_t: %lu ����\n", (char*)(&wchar_var + 1) - (char*)&wchar_var);
    printf("������ long long int: %lu ����\n", (char*)(&long_long_var + 1) - (char*)&long_long_var);
    printf("������ size_t: %lu ����\n", (char*)(&size_var + 1) - (char*)&size_var);
    printf("������ float: %lu ����\n", (char*)(&float_var + 1) - (char*)&float_var);
    printf("������ double: %lu ����\n", (char*)(&double_var + 1) - (char*)&double_var);
    printf("������ signed int: %lu ����\n", (char*)(&signed_int_var + 1) - (char*)&signed_int_var);

    return 0;
}
