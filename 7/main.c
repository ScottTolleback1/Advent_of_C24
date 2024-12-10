#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//PART2 BY INCLUDING THE COMMENT
int canMatchAll(unsigned long* vector, int size, unsigned long current, int index, unsigned long target) {
    if (index == size) {
        return current == target;
    }
    if (canMatchAll(vector, size, current + vector[index], index + 1, target)) {
        return 1;
    }
    if (canMatchAll(vector, size, current * vector[index], index + 1, target)) {
        return 1;
    }
 /*   char strA[20], strB[20];
    sprintf(strA, "%ld", current);
    sprintf(strB, "%ld", vector[index]);
    char result[40];
    strcpy(result, strA);
    strcat(result, strB);

    unsigned long concatenatedLong = atol(result);

    if (canMatchAll(vector, size, concatenatedLong, index + 1, target)) {
        return 1;
    }
    */

    return 0;
}


int main() {
    int input;
    unsigned long vector[15] = {0};  
    unsigned long temp = 0;         
    int size = 0;         
    long nbr = -1;          
    unsigned long sum = 0;
    while ((input = getchar()) != EOF) {
        if (isdigit(input)) {
            if (nbr == -1) nbr = 0;
            nbr = nbr * 10 + (input - '0');
        } else if (input == ':') {
            if (nbr != -1) {
                vector[0] = nbr;
                size = 1;  
                nbr = -1;
            }
        } else {
            if (nbr != -1) {
                vector[size] = nbr;
                size++;
                
            }
            if (input == '\n') {
                temp = vector[0];  
                if (canMatchAll(vector, size, vector[1], 2, temp)) {
                    sum += temp;
                } 

                memset(vector, 0, sizeof(vector));
                
            }
            nbr = -1;
        }
    }
    printf("this is sum: %ld\n", sum);

    return 0;
}
