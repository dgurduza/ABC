#ifndef __rnd__
#define __rnd__

#include <stdlib.h>

//------------------------------------------------------------------------------
// rnd.h 
//------------------------------------------------------------------------------

inline auto Random() {
    int size = rand() % 40 + 1;
    char* phrase = new char[size];
    for (int i = 0;i < size;++i) {
        phrase[i] = static_cast<char>(rand() % 26 + 97);
    }
    int count_of_char = rand() % 4 + 1;
    while (count_of_char > 0) {
        int index_of_char = rand() % size + 1;
        phrase[index_of_char] = static_cast<char>(rand() % 15 + 32);
        --count_of_char;
    }
    return phrase;
}
inline auto RandomOneWord() {
    int size = rand() % 8 + 1;
    char* word = new char[size];
    for (int i = 0;i < size;++i) {
        word[i] = static_cast<char>(rand() % 26 + 97);
    }
    return word;
}
#endif //__rnd__