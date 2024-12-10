#include <stdio.h>
#include <string.h>

#define N 100000

void part1(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) { 
            for (int j = 0; j < i; j++) {
                if (arr[j] == -1) {
                    arr[j] = arr[i];
                    arr[i] = -1;
                    break;
                }
            }
        }
    }
}

void part2(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            int file_id = arr[i];
            int block_size = 0;

            int j = i;
            while (j >= 0 && arr[j] == file_id) {
                block_size++;
                j--;
            }

            int space_start = -1;
            int free_count = 0;
            for (int k = 0; k < i; k++) {
                if (arr[k] == -1) {
                    if (space_start == -1) {
                        space_start = k;
                    }
                    free_count++;
                    if (free_count == block_size) {
                        for (int l = 0; l < block_size; l++) {
                            arr[space_start + l] = file_id;
                        }
                        for (int l = i - block_size + 1; l <= i; l++) {
                            arr[l] = -1;
                        }
                        break;
                    }
                } else {
                    space_start = -1;
                    free_count = 0;
                }
            }

            i = j + 1;
        }
    }
}

int main() {
    int input;
    int comp[N];
    int s = 0;     
    int index = 0;  

    for (int i = 0; i < N; i += 2) {
        input = getchar();
        if (input == '\0') break;
        int file_blocks = input - '0';
        input = getchar();
        int free_blocks = input - '0';

        for (int j = 0; j < file_blocks; j++) {
            comp[s++] = index;
        }
        index++; 

        for (int j = 0; j < free_blocks; j++) {
            comp[s++] = -1;
        }
    }

    part1(comp, s);

    unsigned long long checksum = 0;
    for (int i = 0; i < s; i++) {
        if (comp[i] != -1) {
            checksum += (unsigned long long)comp[i] * i;
        }
    }

    printf("Sum %llu\n", checksum);

    return 0;
}
