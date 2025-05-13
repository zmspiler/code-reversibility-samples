#include <stdio.h>
#include <time.h>

int main(int argc, char** args) {
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