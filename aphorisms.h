#ifndef __aphorisms__
#define __aphorisms__

//------------------------------------------------------------------------------
// aphorisms.h
//------------------------------------------------------------------------------

#include <stdio.h>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// �������.
struct aphorisms {
    char* author; // �����.
    char* aphorism;
};

// ���� ���������� �������� �� �����.
void In(aphorisms& a, FILE* file);

// ��������� ���� ���������� ��������.
void InRnd(aphorisms& a);

// ����� ���������� �������� � ������������� �����.
void Out(aphorisms& a, FILE* file);

// ���������� �������� �� ���������� ������ ���������� � �������� �� ����� ��������.
double Quotient(aphorisms& a);

#endif //__aphorisms__
