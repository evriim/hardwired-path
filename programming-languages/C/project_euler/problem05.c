#include <stdio.h>

int main(void) {
    int answer = 0;
    for (int j = 2521; j > 20; j++){
        for (int i = 11; i <= 20; i++) {
            if (j % i != 0){
                break;
            }else{
                if (i == 20) {
                    printf("%d\n", j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
