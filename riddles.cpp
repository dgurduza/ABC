//------------------------------------------------------------------------------
// riddles.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "riddles.h"

//------------------------------------------------------------------------------
// ���� ���������� ������� �� �����.
void In(riddles& r, FILE* file) {
     fscanf(file,"%s %s", r.riddle, r.answer);
}

// ��������� ���� ���������� �������.
void InRnd(riddles& r) {
    r.answer = RandomOneWord();
    r.riddle = Random();
}

//------------------------------------------------------------------------------
// ����� ���������� ������� � ������������� �����.
void Out(riddles& r, FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is riddle: ", r.riddle, "\nIt is answer to the riddle: ", r.answer, "\n");
}

//------------------------------------------------------------------------------
// ���������� �������� �� ���������� ������ ���������� � ������� �� ����� ���� �������.
double Quotient(riddles& r) {
    int num = 0;
    for (int i = 0; i < strlen(r.riddle); ++i) {
        if (r.riddle[i] == '!' || r.riddle[i] == '\"' || r.riddle[i] == '#'
            || r.riddle[i] == '$' || r.riddle[i] == '%' || r.riddle[i] == '&' || r.riddle[i] == '\''
            || r.riddle[i] == '(' || r.riddle[i] == ')' || r.riddle[i] == '*' || r.riddle[i] == '+'
            || r.riddle[i] == ',' || r.riddle[i] == '-' || r.riddle[i] == '.' || r.riddle[i] == ':'
            || r.riddle[i] == ';' || r.riddle[i] == '?') {
            ++num;
        }
    }
    return double(num / strlen(r.riddle));
}
