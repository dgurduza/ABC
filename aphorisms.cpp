//------------------------------------------------------------------------------
// aphorisms.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "aphorisms.h"

//------------------------------------------------------------------------------
// ���� ���������� �������� �� �����.
void In(aphorisms& a, FILE* file) {
    fscanf(file, "%s %s", a.aphorism, a.author);
}

// ��������� ���� ���������� ��������.
void InRnd(aphorisms& a) {
    a.aphorism = Random();
    a.author = RandomOneWord();
}

//------------------------------------------------------------------------------
// ����� ���������� �������� � ������������� �����.
void Out(aphorisms& a, FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is aphorism: ", a.aphorism, "\nName of the author of the aphorism: ", a.author, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � �������� �� ����� ����� ��������.
double Quotient(aphorisms& a) {
    int num = 0;
    for (int i = 0; i < strlen(a.aphorism); ++i) {
        if (a.aphorism[i] == '!' || a.aphorism[i] == '\"' || a.aphorism[i] == '#'
            || a.aphorism[i] == '$' || a.aphorism[i] == '%' || a.aphorism[i] == '&' || a.aphorism[i] == '\''
            || a.aphorism[i] == '(' || a.aphorism[i] == ')' || a.aphorism[i] == '*' || a.aphorism[i] == '+'
            || a.aphorism[i] == ',' || a.aphorism[i] == '-' || a.aphorism[i] == '.' || a.aphorism[i] == ':'
            || a.aphorism[i] == ';' || a.aphorism[i] == '?') {
            ++num;
        }
    }
    return double(num / strlen(a.aphorism));
}
