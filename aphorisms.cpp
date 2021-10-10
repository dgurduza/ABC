//------------------------------------------------------------------------------
// aphorisms.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "aphorisms.h"

//------------------------------------------------------------------------------
// Ввод параметров афоризма из файла.
void In(aphorisms& a, FILE* file) {
    fscanf(file, "%s %s", a.aphorism, a.author);
}

// Случайный ввод параметров афоризма.
void InRnd(aphorisms& a) {
    a.aphorism = Random();
    a.author = RandomOneWord();
}

//------------------------------------------------------------------------------
// Вывод параметров афоризма в форматируемый поток.
void Out(aphorisms& a, FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is aphorism: ", a.aphorism, "\nName of the author of the aphorism: ", a.author, "\n");
}

//------------------------------------------------------------------------------
// Вычисление частного от количества знаков препинания в афоризме на длину этого афоризма.
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
