#ifndef __well_of_wisdom__
#define __well_of_wisdom__

//------------------------------------------------------------------------------
// well_of_wisdom.h 
//------------------------------------------------------------------------------

#include "aphorisms.h"
#include "proverbs.h"
#include "riddles.h"

//------------------------------------------------------------------------------
// Структура, объединяющая все виды фраз.
struct well_of_wisdom {
    // Перечисление для объявления значений ключей для каждого вида фраз.
    enum key { APHORISMS, PROVERBS, RIDDLES };
    key k;
    // Используемые альтернативы.
    union { // Простейшая реализация.
        aphorisms a;
        proverbs p;
        riddles r;
    };
};

// Ввод обобщенной фразы.
bool In(well_of_wisdom& wow, FILE* file);

// Случайный ввод обобщенной фразы.
bool InRnd(well_of_wisdom& wow);

// Вывод обобщенной фразы.
void Out(well_of_wisdom& wow, FILE* file);

// Вычисление частного от количества знаков препинания на длину строки.
double Quotient(well_of_wisdom& wow);

#endif