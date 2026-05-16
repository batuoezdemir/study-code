#include <iostream>
#include <string>

class Weapon
{
private:
    std::string name;
    unsigned int damageValue;

public:
    Weapon(std::string name, int damageValue)
        : name(name), damageValue(damageValue)
    {
        std::cout << "Constructor of Weapon" << std::endl;
    }

    unsigned int getDmg();
    std::string getName();
};

class Inventory
{
private:
    static const unsigned int maxSlots = 10;

    std::string items[maxSlots];
    unsigned int itemCount;

public:
    Inventory();

    bool isEmpty();
    bool isFull();

    bool addItem(const std::string& item);
    bool removeLastItem(std::string& item);
};

class Character
{
protected:
    std::string name;

    static const int minLevel = 1;
    static const int maxLevel = 10;

    int level;
    int experiencePoints;

    int levelLimits[maxLevel - 1];

    Weapon* weapon;
    Inventory inventory;

private:
    unsigned int healthPoints;

    friend class Healer;

public:
    Character(std::string name, int healthPoints)
        : name(name),
          level(1),
          experiencePoints(0),
          weapon(nullptr),
          inventory(),
          healthPoints(healthPoints)
    {
        std::cout << "Constructor of Character" << std::endl;
    }
    Character& damageTaken(int damage);
    Inventory& getInventory();

    int getLevel();

    void levelUp();

    Character& earnExperience(int exp);

    int getHealthPoints();
};

class Warrior : public Character
{
private:
    int minWeaponSkillPoints = 0;

    int weaponSkillPoints = minWeaponSkillPoints;

public:
    Warrior(std::string name,
             int healthPoints,
             int weaponSkillPoints)
        : Character(name, healthPoints),
          weaponSkillPoints(weaponSkillPoints)
    {
        std::cout << "Constructor of Warrior" << std::endl;
    }

    Warrior& regenerateWeaponSkillPoints(int points);

    Warrior& displayStatus();
};

class Mage : public Character
{
private:
    int minMagicPoints = 0;

    int magicPoints = minMagicPoints;

public:
    Mage(std::string name,
         int healthPoints,
         int magicPoints)
        : Character(name, healthPoints),
          magicPoints(magicPoints)
    {
        std::cout << "Constructor of Mage" << std::endl;
    }
    Mage& regenerateMagicPoints(int points);

    Mage& displayStatus();
};

class Healer : public Mage
{
public:
    Healer(std::string name,
           int healthPoints,
           int magicPoints)
        : Mage(name, healthPoints, magicPoints)
    {
        std::cout << "Constructor of Healer" << std::endl;
    }

    Healer& heal(Character& target);
};

class Thief : public Warrior
{
public:
    Thief(std::string name,
          int healthPoints,
          int weaponSkillPoints)
        : Warrior(name, healthPoints, weaponSkillPoints)
    {
        std::cout << "Constructor of Thief" << std::endl;
    }

    Thief& steal(Character& target);
};