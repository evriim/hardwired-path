#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    int j;
    double num = 300425737572;
    int max = 0;
    for (j = 2; j*j < num; j++){
        if(primeNum(j)){
                if(fmod(600851475143, j) == 0){
                    printf("%d \n", j);
                }
        }
    }
    return 0;
}
