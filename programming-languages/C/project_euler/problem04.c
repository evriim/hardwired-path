#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int palindrome(int x){
    char str[6];
    sprintf(str, "%d", x);
    int k = 0, l = 5;
    while(k != 3 && l != 2){
        if(str[k] != str[l]){
            return 0;
        }else{
            k++;
            l--;
        }
    }
    return 1;
}

int main()
{
    int answer = 0, x;
    int i = 100, j = 100;
    for(i = 100; i < 1000; i++){
        for(j = 100; j < 1000; j++){
            x = i * j;
            if(palindrome(x)){
                if(x > answer){
                    answer = x;
                }
            }
        }
    }
    printf("%d", answer);

    return 0;
}
