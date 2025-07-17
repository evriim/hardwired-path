#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1, y = 1, z = 1, sum = 0;

    while(x < 4000000){
        x = y + z;
        z = y;
        y = x;
        if(x % 2 == 0){
            sum=sum+x;
        }
    }
    printf("%d", sum);
    return 0;
}
