#include <stdio.h>

void greetUser(char* name) {
    printf("Hello %s\n", name);
}

int main(int argc, char** args) {
    greetUser("Alice");
}

