#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер.
//------------------------------------------------------------------------------

#include "well_of_wisdom.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum { max_len = 10000 }; 
    int len; 
    well_of_wisdom cont[max_len];
    well_of_wisdom new_container[max_len];
};

// Инициализация контейнера.
void Init(container& c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container& c);

// Ввод содержимого контейнера из указанного потока.
void In(container& c, FILE* file);

// Случайный ввод содержимого контейнера.
void InRnd(container& c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container& c, FILE* file);

// Вычисление среднего арифметического элементов в контейнере.
double ArithmeticMeanOfQuotients(container& c);

// Удаление элементов из контейнера.
int DeletingNullElements(container& c);

#endif
