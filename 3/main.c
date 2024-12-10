#include "stdio.h"
#include <ctype.h>
//TOO DO PART1 REMOVE d AND ITS LOGIC
int main(){
    long input;
    long c, n1;
    long nbr = -1;
    c = 0;
    int d = 1;
    while((input = getchar()) != EOF){
        n1 = 0;
        if(input == 'd'){
            input = getchar();
            if(input == 'o'){
                input = getchar();
                if(input == '('){
                    input = getchar();
                    if(input == ')') d =1;
                }
                else if(input == 'n'){
                    input = getchar();
                    if(input == '\''){
                        input = getchar();
                        if(input == 't'){
                            input = getchar();
                            if(input == '('){
                                input = getchar();
                                if(input == ')') d = 0;
                            }
                        }
                    }
                }
            }
        }
        if(input == 'm' && d == 1){
            input = getchar();
            if(input == 'u'){
                input = getchar();
                if(input == 'l'){
                    input = getchar();
                    if(input == '('){
                        input = getchar();
                        if(isdigit(input)){
                            if(nbr = -1) nbr = 0;
                            n1:
                            nbr = 10 * nbr + input - '0';
                            input = getchar();
                            if(isdigit(input)) goto n1;
                            else if(input == ','){
                                
                                n1 = nbr;
                                nbr = -1;
                                input = getchar();
                                if(isdigit(input)){
                                    if(nbr = -1) nbr = 0;
                                    n2:
                                    nbr = nbr * 10 + input - '0';
                                    input = getchar();
                                    if(isdigit(input)) goto n2;
                                    else if(input == ')'){
                                        c += n1 * nbr;
                                        nbr = -1;
                                    }
                                }
                            }
                        }
                    }
                }
        }
        }
        
    }
    printf("%ld\n", c);
}