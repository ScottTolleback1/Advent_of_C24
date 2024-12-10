#include "stdio.h"
#include <stdlib.h>
#include "math.h"
#define N   (1000)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(){
    int l1[N] = {0};
    int l2[N] = {0};
    int res = 0;
    int res2 = 0;
    int n = 0;
    int i;
    for( i = 0; i< 1000; i++){
        scanf("%d", &l1[i]);
        scanf("%d", &l2[i]);
    }
 
    qsort(l1, N, sizeof(int), compare);

    qsort(l2, N, sizeof(int), compare);

    for(i = 0; i<1000;i++){
        n = 0;
        for(int j = 0; j <1000; j++){
            if(l1[i] == l2[j]) n++;
        }
        res2 += n * l1[i];
        res += abs(l1[i]-l2[i]);
        
    }
    printf("%d\n%d\n", res, res2);  
}



