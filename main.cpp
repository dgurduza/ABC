//------------------------------------------------------------------------------
// main.cpp - �������� ������� �������, 
// �������������� ������� ������������
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h> // ��� ������� rand() � srand()
#include <time.h>   // ��� ������� time()
#include <string.h>

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n %s %s %s %s","  Waited:\n","     command -f infile outfile01 outfile02\n",
        "  Or:\n","     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n %s %s %s %s","  Waited:\n","     command -f infile outfile01 outfile02\n",
        "  Or:\n","     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    Init(c);

    ////cout << "argv[1] = " << argv[1] << "\n";
    if (!strcmp(argv[1], "-f")) {
        FILE* file= fopen(argv[2],"r+");
        In(c, file);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect numer of phrases = %u %s", size, ". Set 0 < number <= 10000\n");
            return 3;
        }
        // ��������� ���� � �������� ��������������
        srand(static_cast<unsigned int>(time(0)));
        // ���������� ���������� ����������� ��������� �����.
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // ����� ����������� ���������� � ����
    FILE* file1 = fopen(argv[3],"a + t");
    fprintf(file1, "%s", "Filled container:\n");
    Out(c, file1);

    // The 2nd part of task
    FILE* file2=fopen(argv[4],"at");
    fprintf(file2,"%s %d %s", "New container size after deleting= ", DeletingNullElements(c), "\n");

    Clear(c);
    printf("Stop\n");
    return 0;
}
