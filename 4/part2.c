#include <stdio.h>
#include <string.h>

int main() {
    char c[140][151];
    int sum = 0;

    for (int i = 0; i < 140; i++) {
        if (scanf("%150s", c[i]) == EOF) break;
    }

    for (int i = 1; i < 139; i++) {
        for (int j = 1; j < 149; j++) {
            if (c[i][j] == 'A') {
                int m_c = 0, s_c = 0;
                char corners[] = {
                    c[i - 1][j - 1], c[i - 1][j + 1],
                    c[i + 1][j - 1], c[i + 1][j + 1]
                };

                for (int k = 0; k < 4; k++) {
                    if (corners[k] == 'M') m_c++;
                    if (corners[k] == 'S') s_c++;
                }

                if (m_c == 2 && s_c == 2 && corners[0] != corners[3] && corners[1] != corners[2]) {
                    sum++;
                }
            }
        }
    }

    printf("total %d\n", sum);
    return 0;
}
