#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - �������� ��� ������,
// �������������� ���������� ���������.
//------------------------------------------------------------------------------

#include "well_of_wisdom.h"

//------------------------------------------------------------------------------
// ���������� ��������� �� ������ ����������� �������.
struct container {
    enum { max_len = 10000 }; 
    int len; 
    well_of_wisdom cont[max_len];
    well_of_wisdom new_container[max_len];
};

// ������������� ����������.
void Init(container& c);

// ������� ���������� �� ��������� (������������ ������).
void Clear(container& c);

// ���� ����������� ���������� �� ���������� ������.
void In(container& c, FILE* file);

// ��������� ���� ����������� ����������.
void InRnd(container& c, int size);

// ����� ����������� ���������� � ��������� �����.
void Out(container& c, FILE* file);

// ���������� �������� ��������������� ��������� � ����������.
double ArithmeticMeanOfQuotients(container& c);

// �������� ��������� �� ����������.
int DeletingNullElements(container& c);

#endif
