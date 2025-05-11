#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** args) {
    int sum = 0;
    srand(time(NULL));
    
    int n = rand() % 100;
    for (int i = 0; i < n; i++) {
        if (i % 3 == 1) {
            sum += rand() % 20;
        }
    };

    printf("Sum is: %d\n", sum);

    return 0;
}
