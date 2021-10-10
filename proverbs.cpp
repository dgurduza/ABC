//------------------------------------------------------------------------------
// proverbs.cpp
//------------------------------------------------------------------------------
#include "string.h"
#include "proverbs.h"

//------------------------------------------------------------------------------
// ¬вод параметров пословицы из файла.
void In(proverbs& p, FILE* file) {
    fscanf(file, "%s %s", p.proverb, p.country);
}

// —лучайный ввод параметров пословицы.
void InRnd(proverbs& p) {
    p.country = RandomOneWord();
    p.proverb = Random();
}

//------------------------------------------------------------------------------
// ¬ывод параметров пословицы в форматируемый поток.
void Out(proverbs& p, FILE* file) {
    fprintf(file, "%s %s %s %s %s",
        "It is proverb: ", p.proverb, "\nIt is proverb country: ", p.country, "\n");
}

//------------------------------------------------------------------------------
// ¬ычисление частного от количества знаков препинани€ в пословице на длину этой пословицы.
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
