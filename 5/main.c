#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int ord[100][100] = {0};

int compare(const void *a, const void *b) {
    int index_a = *(int *)a;
    int index_b = *(int *)b;
    if (ord[index_a][index_b] == 1) return -1;
    if (ord[index_b][index_a] == 1) return 1;
    return 0;
}

int main() {
    int input, n1, n2, i = 0, j = 0, sum = 0, sum1 = 0;
    int iteration = 1, middle[25], s = 0, error = 0;
    int lastDigit = -1, newDigit = -1;

    while (1) {
        input = getchar();
        if (input == '\n') {
            input = getchar();
            if (input == '\n') break;
        }
        if (isdigit(input)) {
            n1 = input - '0';
            input = getchar();
            if (isdigit(input)) {
                n2 = input - '0';
                if (iteration == 1) {
                    i = n1 * 10 + n2;
                    iteration = 2;
                } else {
                    j = n1 * 10 + n2;
                    ord[i][j] = 1;
                    iteration = 1;
                }
            }
        }
    }

    memset(middle, 0, sizeof(middle));

    while ((input = getchar()) != EOF) {
        if (isdigit(input)) {
            n1 = input - '0';
            input = getchar();
            if (isdigit(input)) {
                n2 = input - '0';
                newDigit = n1 * 10 + n2;
                middle[s] = newDigit;
                s++;
            }
        }

        if (input == ',') {
            if (lastDigit != -1) {
                if (ord[lastDigit][newDigit] != 1) error++;
            }
            lastDigit = newDigit;
        } else if (input == '\n') {
            if (error > 0) {
                qsort(middle, s, sizeof(int), compare);
                sum += middle[s / 2];
            } else {
                sum1 += middle[s / 2];
            }
            error = 0;
            s = 0;
            lastDigit = -1;
        }
    }

    printf("First sum %d\n", sum1);
    printf("Second sum %d\n", sum);

    return 0;
}
