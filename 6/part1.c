#include "stdio.h"
#define N (130)

int main() {
    char map[N][N];
    int in, iteration = 0, sum = 1, flag = 3, c_i = 0;
    int dir[4][2] = {
        {-1, 0},  // Up
        {0, 1},   // Right
        {1, 0},   // Down
        {0, -1}   // Left
    };
    int pos[2];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in = getchar();
            if (in == '#') {
                map[i][j] = 1;
            } else if (in == '^') {
                map[i][j] = 2;
                pos[0] = i;
                pos[1] = j;
            } else if (in == '\n') {
                j--; 
            } else {
                map[i][j] = 0;
            }
        }
    }

    while (1) {
        if (pos[0] + dir[c_i][0] < 0 || pos[0] + dir[c_i][0] >= N ||
            pos[1] + dir[c_i][1] < 0 || pos[1] + dir[c_i][1] >= N) {
            break;
        }

        if (map[pos[0] + dir[c_i][0]][pos[1] + dir[c_i][1]] == 1) {
            c_i = (c_i + 1) % 4;  
        }

        pos[0] += dir[c_i][0];
        pos[1] += dir[c_i][1];

        if (map[pos[0]][pos[1]] != 2) {
            map[pos[0]][pos[1]] = 2;
            sum++;
        }
    }

    printf("sum %d\n", sum);

    return 0;
}
