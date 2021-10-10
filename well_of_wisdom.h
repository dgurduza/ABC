#ifndef __well_of_wisdom__
#define __well_of_wisdom__

//------------------------------------------------------------------------------
// well_of_wisdom.h 
//------------------------------------------------------------------------------

#include "aphorisms.h"
#include "proverbs.h"
#include "riddles.h"

//------------------------------------------------------------------------------
// ���������, ������������ ��� ���� ����.
struct well_of_wisdom {
    // ������������ ��� ���������� �������� ������ ��� ������� ���� ����.
    enum key { APHORISMS, PROVERBS, RIDDLES };
    key k;
    // ������������ ������������.
    union { // ���������� ����������.
        aphorisms a;
        proverbs p;
        riddles r;
    };
};

// ���� ���������� �����.
bool In(well_of_wisdom& wow, FILE* file);

// ��������� ���� ���������� �����.
bool InRnd(well_of_wisdom& wow);

// ����� ���������� �����.
void Out(well_of_wisdom& wow, FILE* file);

// ���������� �������� �� ���������� ������ ���������� �� ����� ������.
double Quotient(well_of_wisdom& wow);

#endif