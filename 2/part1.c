#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;
    int c = 0, n = -1, n1 = 0, n2 = 0, a = 0;
    int r_count = 0, r_flag = 0;

new:
    while ((input = getchar()) != EOF) {
        if (input - '0' >= 0 && input - '0' <= 9) {
            if (n == -1) n = 0;
            n = n * 10 + input - '0';
            continue;
        } else {
            r_count++;
            n1 = n2;
            n2 = n;
            n = -1;
            a = abs(n1 - n2);

            if (r_count > 1) {
                if (a == 0 || a > 3) goto error;

                if (r_count == 2) {
                    r_flag = (n1 - n2 < 0) ? 1 : -1;
                } else {
                    if ((n1 - n2 < 0 && r_flag == -1) || (n1 - n2 > 0 && r_flag == 1)) 
                        goto error;
                }
            }

            if (input == '\n') {
                c++;
                r_count = 0;
            }
            continue;
        }
    error:
        r_count = 0;
        while ((input = getchar()) != '\n');
        goto new;
    }

    printf("%d\n", c);
    return 0;
}
