#include <stdio.h>

int main(void) {
    int sum, sqr = 0;
    for (int i = 1; i <= 100; i++) {
        sum +=i;
        sqr = sqr + (i*i);
    }
    printf("%d\n", ((sum*sum)-sqr));
    return 0;
}
