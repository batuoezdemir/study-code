#include <stdio.h>
#include <string.h>

struct Car {
    float fuel_level;
    float max_fuel_level;
    char model[50];
};

void refuel(struct Car *car, float amount) {
    if (car->fuel_level + amount <= car->max_fuel_level) {
        car->fuel_level += amount;
    } else {
        car->fuel_level = car->max_fuel_level;
    }
}

int main() {
    struct Car Auto;
    float amount;

    strcpy(Auto.model, "Volkswagen Polo");
    Auto.max_fuel_level = 50.0;

    // ✅ zuerst Eingaben
    printf("Tankstand eingeben: ");
    scanf("%f", &Auto.fuel_level);

    printf("Hinzugefügter Kraftstoff: ");
    scanf("%f", &amount);

    // ✅ Zustand davor anzeigen
    printf("\nZuvor:\n");
    printf("Modell: %s\n", Auto.model);
    printf("Tank: %.2f / %.2f\n",
           Auto.fuel_level,
           Auto.max_fuel_level);

    // Tanken
    refuel(&Auto, amount);

    // ✅ danach anzeigen
    printf("\nDanach:\n");
    printf("Modell: %s\n", Auto.model);
    printf("Tank: %.2f / %.2f\n",
           Auto.fuel_level,
           Auto.max_fuel_level);

    return 0;
}