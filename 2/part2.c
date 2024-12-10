#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;
    int c = 0, n = -1, n1 = 0, n2 = 0, n3 = 0, a1 = 0, a2 = 0;
    int has_bad_level = 0, r_count = 0, r_flag = 0;

new:
    while ((input = getchar()) != EOF) {
        if (input - '0' >= 0 && input - '0' <= 9) {
            if (n == -1) n = 0;
            n = n * 10 + input - '0';
            continue;
        } else {
            r_count++;
            n1 = n2;
            n2 = n3;
            n3 = n;
            n = -1;
            a1 = abs(n1 - n2);
            a2 = abs(n1 - n3);

            if (r_count > 2) {
                if (a1 == 0 || a1 > 3) {
                    if (a2 == 0 || a2 > 3) goto error;
                    has_bad_level++;
                    if (has_bad_level == 2) goto error;
                }

                if (r_count == 3) {
                    if (n1 < n2) {
                        if (n2 > n3) has_bad_level++;
                        r_flag = 1;
                    } else if (n1 == n2) {
                        has_bad_level++;
                        r_flag = (n2 < n3) ? 1 : -1;
                    } else {
                        if (n3 > n2) has_bad_level++;
                        r_flag = -1;
                    }
                } else {
                    if (n1 < n2 && r_flag == -1) {
                        if (n1 < n3) goto error;
                        has_bad_level++;
                        if (has_bad_level == 2) goto error;
                    } else if (n1 > n2 && r_flag == 1) {
                        if (n1 > n3) goto error;
                        has_bad_level++;
                        if (has_bad_level == 2) goto error;
                    }
                }
            }

            if (input == '\n') {
                if (has_bad_level < 2) c++;
                has_bad_level = 0;
                r_count = 0;
            }
            continue;
        }
    error:
        has_bad_level = 0;
        r_count = 0;
        while ((input = getchar()) != '\n');
        goto new;
    }

    printf("%d\n", c);
    return 0;
}
