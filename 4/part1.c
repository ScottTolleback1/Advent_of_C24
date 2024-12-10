#include <stdio.h>
#include <string.h>

int main() {
    char c[140][151];
    int count = 0;

    for (int i = 0; i < 140; i++) {
        if (scanf("%150s", c[i]) == EOF) {
            break;
        }
    }

    for (int i = 0; i < 140; i++) {
        for (int j = 0; j < 150; j++) {
                if (c[i][j] == 'X' && c[i][j + 1] == 'M' && c[i][j + 2] == 'A' && c[i][j + 3] == 'S') count++;
                if (c[i][j] == 'S' && c[i][j + 1] == 'A' && c[i][j + 2] == 'M' && c[i][j + 3] == 'X') count++;

            if (i < 137 && j < 147) {
                if (c[i][j] == 'X' && c[i + 1][j + 1] == 'M' && c[i + 2][j + 2] == 'A' && c[i + 3][j + 3] == 'S') count++;
                if (c[i][j] == 'S' && c[i + 1][j + 1] == 'A' && c[i + 2][j + 2] == 'M' && c[i + 3][j + 3] == 'X') count++;
            }

            if (i < 137 && j > 2) {
                if (c[i][j] == 'X' && c[i + 1][j - 1] == 'M' && c[i + 2][j - 2] == 'A' && c[i + 3][j - 3] == 'S') count++;
                if (c[i][j] == 'S' && c[i + 1][j - 1] == 'A' && c[i + 2][j - 2] == 'M' && c[i + 3][j - 3] == 'X') count++;
            }

            if (i < 137) {
                if (c[i][j] == 'X' && c[i + 1][j] == 'M' && c[i + 2][j] == 'A' && c[i + 3][j] == 'S') count++;
                if (c[i][j] == 'S' && c[i + 1][j] == 'A' && c[i + 2][j] == 'M' && c[i + 3][j] == 'X') count++;
            }
        }
    }

    printf("total %d\n", count);
    return 0;
}
