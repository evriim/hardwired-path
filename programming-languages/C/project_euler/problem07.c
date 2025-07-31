#include <iso646.h>
#include <stdio.h>
#include <math.h>

int primeNum(int x){
    int i;
    for(i = 2; i < x; i++){
        if(fmod(x, i) == 0){
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int counter = 0;
    int i, answer = 0;
    for (i = 2; counter < 10001; i++) {
        if(primeNum(i)) {
            counter++;
            answer = i;
        }
    }
    printf("%d\n", answer);
    return 0;
}
