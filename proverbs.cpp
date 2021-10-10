//------------------------------------------------------------------------------
// proverbs.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "proverbs.h"

//------------------------------------------------------------------------------
// ���� ���������� ��������� �� �����.
void In(proverbs& p, FILE* file) {
    fscanf(file, "%s %s", p.proverb, p.country);
}

// ��������� ���� ���������� ���������.
void InRnd(proverbs& p) {
    p.country = RandomOneWord();
    p.proverb = Random();
}

//------------------------------------------------------------------------------
// ����� ���������� ��������� � ������������� �����.
void Out(proverbs& p, FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is proverb: ", p.proverb, "\nIt is proverb country: ", p.country, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � ��������� �� ����� ���� ���������.
double Quotient(proverbs& p) {
    int num = 0;
    for (int i = 0; i < strlen(p.proverb); ++i) {
        if (p.proverb[i] == '!' || p.proverb[i] == '\"' || p.proverb[i] == '#'
            || p.proverb[i] == '$' || p.proverb[i] == '%' || p.proverb[i] == '&' || p.proverb[i] == '\''
            || p.proverb[i] == '(' || p.proverb[i] == ')' || p.proverb[i] == '*' || p.proverb[i] == '+'
            || p.proverb[i] == ',' || p.proverb[i] == '-' || p.proverb[i] == '.' || p.proverb[i] == ':'
            || p.proverb[i] == ';' || p.proverb[i] == '?') {
            ++num;
        }
    }
    return double(num / strlen(p.proverb));
}
