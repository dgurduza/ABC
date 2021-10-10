//------------------------------------------------------------------------------
// well_of_wisdom.cpp 
//------------------------------------------------------------------------------

#include "well_of_wisdom.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фразы из файла
bool In(well_of_wisdom& s, FILE* file) {
    int k;
    fscanf(file,"%d", k);
    switch (k) {
    case 1:
        s.k = well_of_wisdom::APHORISMS;
        In(s.a, file);
        return true;
    case 2:
        s.k = well_of_wisdom::PROVERBS;
        In(s.p, file);
        return true;
    case 3:
        s.k = well_of_wisdom::RIDDLES;
        In(s.r, file);
        return true;
    default:
        return false;
    }
}

// Случайный ввод обобщенной фразы
bool InRnd(well_of_wisdom& s) {
    auto k = rand() % 2 + 1;
    switch (k) {
    case 1:
        s.k = well_of_wisdom::APHORISMS;
        InRnd(s.a);
        return true;
    case 2:
        s.k = well_of_wisdom::PROVERBS;
        InRnd(s.p);
        return true;
    case 3:
        s.k = well_of_wisdom::RIDDLES;
        InRnd(s.r);
        return true;
    default:
        return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фразы в поток
void Out(well_of_wisdom& s, FILE* file) {
    switch (s.k) {
    case well_of_wisdom::APHORISMS:
        Out(s.a, file);
        break;
    case well_of_wisdom::PROVERBS:
        Out(s.p, file);
        break;
    case well_of_wisdom::RIDDLES:
        Out(s.r, file);
        break;
    default:
        fprintf(file,"Incorrect phrase!");
    }
}

//------------------------------------------------------------------------------
// Вычисление частного от знаков препинания на длину фразы.
double Quotient(well_of_wisdom& s) {
    switch (s.k) {
    case well_of_wisdom::APHORISMS:
        return Quotient(s.a);
        break;
    case well_of_wisdom::PROVERBS:
        return Quotient(s.p);
        break;
    case well_of_wisdom::RIDDLES:
        return Quotient(s.r);
        break;
    default:
        return 0.0;
    }
}