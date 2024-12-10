#include <stdio.h>
#include <string.h>

#define N 54

int visited[N][N];

int search(int map[N][N], int x, int y, int c) {
    if (x < 0 || x >= N || y < 0 || y >= N) 
        return 0;

    if (map[x][y] != c || visited[x][y]) 
        return 0;

    visited[x][y] = 1;

    if (c == 9) 
        return 1;

    int count = 0;
    count += search(map, x - 1, y, c + 1); 
    count += search(map, x + 1, y, c + 1); 
    count += search(map, x, y - 1, c + 1); 
    count += search(map, x, y + 1, c + 1); 

    return count;
}

int main() {
    int map[N][N];
    int input;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input = getchar();
            while (input == '\n') 
                input = getchar(); // Skip newlines
            
            map[i][j] = input - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                memset(visited, 0, sizeof(visited)); // Reset visited array
                int s = search(map, i, j, 0);
                sum += s;
            }
        }
    }

    printf("Sum: %d\n", sum);

    return 0;
}
