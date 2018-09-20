#include <stdio.h>

//As I am writing this code ahead of watching the lecture, I am using https://www.tutorialspoint.com/cprogramming to help me
//with input methods and type conversion

int main(void){
    while(1) {
        int startValue = -1;
        int * input = &startValue;
        while((*input < 0) || (*input > 23)) {
            printf("\nHeight: ");
            scanf("%d", input);
        }

        for(int i = 0; i < *input; i++) {
            for(int j = 0; (j < (*input - 1 - i)); j++) {
                printf(" ");
            }
            for(int j = 0; j < i + 2; j++) {
                printf("#");
            }
            printf("\n");
        }

        break;
    }

}


