#ifndef __aphorisms__
#define __aphorisms__

//------------------------------------------------------------------------------
// aphorisms.h
//------------------------------------------------------------------------------

#include <stdio.h>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// Афоризм.
struct aphorisms {
    char* author; // Автор.
    char* aphorism;
};

// Ввод параметров афоризма из файла.
void In(aphorisms& a, FILE* file);

// Случайный ввод параметров афоризма.
void InRnd(aphorisms& a);

// Вывод параметров афоризма в форматируемый поток.
void Out(aphorisms& a, FILE* file);

// Вычисление частного от количество знаков препинания в афоризме на длину афоризма.
double Quotient(aphorisms& a);

#endif //__aphorisms__
