#include "stdio.h"
#include <string.h>
#define N (130)

int main() {
    char map[N][N];
    int visited[N][N][4] = {0};
    int done[N][N] = {0};
    int in, iteration = 0, sum = 0, flag = 3, c_i = 0;
    int dir[4][2] = {
        {-1, 0},  // Up
        {0, 1},   // Right
        {1, 0},   // Down
        {0, -1}   // Left
    };
    int pos[2], start_pos[2];
    int start_c_i = c_i;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in = getchar();

            if (in == '#') {
                map[i][j] = 1;
            } else if (in == '^') {
                map[i][j] = 2;
                pos[0] = i;
                pos[1] = j;
                start_pos[0] = i;
                start_pos[1] = j;
            } else if (in == '\n') {
                j--;
            } else {
                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pos[0] = start_pos[0];
            pos[1] = start_pos[1];
            c_i = start_c_i;

            if (map[i][j] == 1 || (i == start_pos[0] && j == start_pos[1])) {
                continue;
            }

            if (map[i][j] != 1) {
                memset(visited, 0, sizeof(visited));
                map[i][j] = 1;

                while (1) {
                    if (visited[pos[0]][pos[1]][c_i]) {
                        if (done[i][j] == 0) {
                            sum++;
                            done[i][j] = 1;
                        }
                        break;
                    }

                    visited[pos[0]][pos[1]][c_i] = 1;

                    if (pos[0] + dir[c_i][0] < 0 || pos[0] + dir[c_i][0] >= N ||
                        pos[1] + dir[c_i][1] < 0 || pos[1] + dir[c_i][1] >= N) {
                        break;
                    }

                    if (map[pos[0] + dir[c_i][0]][pos[1] + dir[c_i][1]] == 1) {
                        c_i = (c_i + 1) % 4;
                    } else {
                        pos[0] += dir[c_i][0];
                        pos[1] += dir[c_i][1];
                    }
                }

                map[i][j] = 0;
            }
        }
    }

    printf("Sum %d\n", sum);

    return 0;
}
