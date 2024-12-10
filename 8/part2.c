#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ANTENNAS 150
#define MAX_GRID_SIZE 50

typedef struct {
    int size;
    int nodes[MAX_GRID_SIZE * MAX_GRID_SIZE][2];
} Antenna;

int main() {
    char input;
    Antenna *field[MAX_ANTENNAS];
    int map[MAX_GRID_SIZE][MAX_GRID_SIZE] = {0};

    for (int x = 0; x < MAX_ANTENNAS; x++) {
        field[x] = malloc(sizeof(Antenna));
        if (field[x] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        field[x]->size = 0;
    }

    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE + 1; j++) {
            input = getchar();
            if (input == EOF) break;
            if (input == '\n') continue;

            if (input != '.') {
                int index = (input >= 'a' && input <= 'z') ? input - 'a' :
                            (input >= 'A' && input <= 'Z') ? input - 'A' + 26 :
                            (input >= '0' && input <= '9') ? input - '0' + 52 : -1;

                if (index >= 0 && index < MAX_ANTENNAS) {
                    field[index]->nodes[field[index]->size][0] = i;
                    field[index]->nodes[field[index]->size][1] = j;
                    field[index]->size++;
                }
            }
        }
    }

    for (int x = 0; x < MAX_ANTENNAS; x++) {
        for (int s = 0; s < field[x]->size; s++) {
            int c = 0;
            for (int t = 0; t < field[x]->size; t++) {
                int n1_x = field[x]->nodes[s][0];
                int n1_y = field[x]->nodes[s][1];
                int n2_x = field[x]->nodes[t][0];
                int n2_y = field[x]->nodes[t][1];
                
                if (n1_x != -1 && n1_y != -1 && n2_x != -1 && n2_y != -1) {
                    map[n2_x][n2_y] = 1;
                    int dx = n2_x - n1_x;
                    int dy = n2_y - n1_y;

                    int antinode1_x = n1_x - dx;
                    int antinode1_y = n1_y - dy;
                    while (antinode1_x - dx != antinode1_x) {
                        if (antinode1_x > -1 && antinode1_y > -1 && antinode1_x < MAX_GRID_SIZE && antinode1_y < MAX_GRID_SIZE) {
                            map[antinode1_x][antinode1_y] = 1;
                            antinode1_x -= dx;
                            antinode1_y -= dy;
                            c++;
                            if (c == 2) map[n1_x][n1_y] = 1;
                        } else {
                            break;
                        }
                    }

                    int antinode2_x = n2_x + dx;
                    int antinode2_y = n2_y + dy;
                    while (antinode2_x + dx != antinode2_x) {
                        if (antinode2_x > -1 && antinode2_y > -1 && antinode2_x < MAX_GRID_SIZE && antinode2_y < MAX_GRID_SIZE) {
                            map[antinode2_x][antinode2_y] = 1;
                            antinode2_x += dx;
                            antinode2_y += dy;
                            c++;
                            if (c == 2) map[n1_x][n1_y] = 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            sum += map[i][j];
        }
    }

    printf("Sum %d\n", sum);
    return 0;
}
