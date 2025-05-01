#include <stdio.h>
#include <time.h>

int main(int argc, char** args) {
    for (int i = 0; i < 5; i++) {
        printf("Count: %d\n", i);

        if (i > 3) {
            puts("More than 3");
        } else if (i == 3) {
            printf("%d\n", 3);
        } else {
            puts("Less than 3");
        }
    }
    
    struct tm* timeinfo;
    time_t rawtime;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int hours = timeinfo->tm_hour;
    if (hours < 12) {
        puts("Good morning!");
    } else {
        puts("Good afternoon!");
    }
    return 0;
}