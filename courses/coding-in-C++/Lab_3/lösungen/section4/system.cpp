#include "System.hpp"
#include <iostream>

Inventory::Inventory()
{
    itemCount = 0;
    std::cout << "Constructor of Inventory" << std::endl;
}

bool Inventory::isEmpty()
{
    return itemCount == 0;
}

bool Inventory::isFull()
{
    return itemCount == maxSlots;
}

bool Inventory::addItem(const std::string& item)
{
    if (isFull())
        return false;

    items[itemCount] = item;
    itemCount++;
    return true;
}

bool Inventory::removeLastItem(std::string& item)
{
    if (isEmpty())
        return false;

    itemCount--;
    item = items[itemCount];
    return true;
}

unsigned int Weapon::getDmg()
{
    return damageValue;
}

std::string Weapon::getName()
{
    return name;
}

Character& Character::damageTaken(int damage)
{
    if (damage < 0)
        return *this;

    if ((unsigned int)damage >= healthPoints)
        healthPoints = 0;
    else
        healthPoints -= damage;

    return *this;
}

Inventory& Character::getInventory()
{
    return inventory;
}

int Character::getLevel()
{
    return level;
}

void Character::levelUp()
{
    if (level < maxLevel)
        level++;
}

Character& Character::earnExperience(int exp)
{
    if (exp < 0)
        return *this;

    experiencePoints += exp;

    while (level < maxLevel &&
           experiencePoints >= levelLimits[level - 1])
    {
        levelUp();
    }

    return *this;
}

int Character::getHealthPoints()
{
    return healthPoints;
}

Warrior& Warrior::regenerateWeaponSkillPoints(int points)
{
    weaponSkillPoints += points;
    return *this;
}

Warrior& Warrior::displayStatus()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: Warrior" << std::endl;
    std::cout << "HP: " << getHealthPoints() << std::endl;
    std::cout << "Weapon skill points: " << weaponSkillPoints << std::endl;
    std::cout << "Level: " << level << std::endl;

    if (weapon != nullptr)
        std::cout << "Current weapon: " << weapon->getName() << std::endl;
    else
        std::cout << "Current weapon: None" << std::endl;

    return *this;
}

Mage& Mage::regenerateMagicPoints(int points)
{
    magicPoints += points;
    return *this;
}

Mage& Mage::displayStatus()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: Mage" << std::endl;
    std::cout << "HP: " << getHealthPoints() << std::endl;
    std::cout << "Magic points: " << magicPoints << std::endl;
    std::cout << "Level: " << level << std::endl;

    if (weapon != nullptr)
        std::cout << "Current weapon: " << weapon->getName() << std::endl;
    else
        std::cout << "Current weapon: None" << std::endl;

    return *this;
}

Healer& Healer::heal(Character& target)
{
    target.healthPoints += 20;
    return *this;
}

Thief& Thief::steal(Character& target)
{
    std::string item;

    if (target.getInventory().removeLastItem(item))
    {
        getInventory().addItem(item);
    }

    return *this;
}