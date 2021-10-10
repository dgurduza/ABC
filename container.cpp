//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container& c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container& c, FILE* file) {
    while (!feof(file)) {
        if (In(c.cont[c.len], file)) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container& c, int size) {
    while (c.len < size) {
        if (InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Out(container& c, FILE* file) {
    fprintf(file, "%s %u %s", "Container contains ", c.len, " elements.");
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%u %s", i, ": ");
        Out(c.cont[i], file);
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического элементов в контейнере.
double ArithmeticMeanOfQuotients(container& c) {
    double sum = 0.0;
    int i;
    for (i = 0; i < c.len; ++i) {
        sum += Quotient(c.cont[i]);
    }
    return double(sum / i - 1);
}
//------------------------------------------------------------------------------
// Удаление элементов с несоответствующим частным.
int DeletingNullElements(container& c) {
    int indexer = 0;
    well_of_wisdom wow;
    double mean = ArithmeticMeanOfQuotients(c);
    for (int i = 0; i < c.len; ++i) {
        if (Quotient(c.cont[i]) < mean) {
            c.cont[i] = wow;
            --c.len;
        }
    }
    return c.len;
}

