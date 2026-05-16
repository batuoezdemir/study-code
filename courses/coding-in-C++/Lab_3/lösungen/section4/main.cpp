#include "System.hpp"
#include <iostream>

int main()
{
    Warrior krieger("John", 5, 5);
    Mage magier("Porky", 2, 4);
    Healer heiler("James", 3, 6);
    Thief dieb("Johannes", 6, 7);

    Weapon waffe("Käsekuchen", 7);

    Character* characters[4];

    characters[0] = &krieger;
    characters[1] = &magier;
    characters[2] = &heiler;
    characters[3] = &dieb;

    krieger.getInventory().addItem("Sword");
    krieger.getInventory().addItem("Shield");

    dieb.getInventory().addItem("Dagger");

    krieger
        .damageTaken(20)
        .earnExperience(150);

    magier
        .regenerateMagicPoints(50)
        .earnExperience(300);

    heiler
        .heal(krieger)
        .earnExperience(200);

    dieb
        .steal(krieger)
        .earnExperience(100);

    std::cout << "\n=== Edge Cases ===\n";

    krieger.damageTaken(1000);

    dieb.steal(magier);

    heiler.heal(heiler);

    krieger.displayStatus();
    std::cout << std::endl;

    magier.displayStatus();
    std::cout << std::endl;

    heiler.displayStatus();
    std::cout << std::endl;

    dieb.displayStatus();

    return 0;
}