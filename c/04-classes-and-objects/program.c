#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

struct Car {
    int year, kilometers;
    char *model;
    char *brand;
};
struct Car* createCar(int year, int kilometers, char* model, char* brand) {
    struct Car* car = malloc(sizeof(struct Car));
    car -> year = year;
    car -> kilometers = kilometers;
    car -> model = model;
    car -> brand = brand;
    return car;
}

void beep(const struct Car* car) {
    if (strcmp(car->brand, "Fiat") == 0) puts("Beeep!");
    else puts("Beep!");
}

void revertKilometers(struct Car* car) {
    car -> kilometers -= 50000;
}

char* getDescriptor(const struct Car* car) {
    // formatted string: %s %s %d (%d km)
    // 8 predefined characters + null character
    int buffLen = 9 + strlen(car->brand) + strlen(car->model) + ((int)floor(log10(car->year)) + 1) + ((int)floor(log10(car->kilometers)) + 1);
    char* str = malloc(buffLen);
    snprintf(str, buffLen, "%s %s %d (%d km)", car->brand, car->model, car->year, car->kilometers);
    return str;
}

int main(int argc, char** args) {
    struct Car* car = createCar(1998, 235000, "Golf IV", "VW");
    beep(car);

    char* description = getDescriptor(car);
    puts(description);
    free(description);

    revertKilometers(car);

    description = getDescriptor(car);
    puts(description);
    free(description);
    
    free(car);
    return 0;
}