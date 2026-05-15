#include <iostream>
#include <string>

class Weapon
{
protected:
std::string name;
int damagevalue;
public
Weapon(std::string name, int damagevalue)
{
    std::cout<<"Constructor of Weapon"<<std::endl;
}
};
class Inventory 
{
    private:
    int maxSlots = 10;
    std::string items [maxSlots];
    unsigned int itemCount;
    public:
    Inventory(std::string items, unsigned int itemCount, int maxSlots) : items(items), itemCount(itemCount), maxSlots(maxSlots)
    {
        std::cout<<"Constructor of Inventory"<<std::endl;
    }
    bool isEmpty()
    {
        if 
    }
}
class Character
{
    protected:
    std::string name;
    int minlevel = 1;
    int maxlevel = 10;
    int level;
    private: 
    int minhealthpoints = 0;
    int healthpoints = minhealthpoints;
    public:
    Character(std::string name, int level, int healthpoints) : name(name), level(level), healthpoints(healthpoints)
    {
        std::cout<<"Constructor of Character"<<std::endl;
    }
    Inventroy& getInventory();
    void levelUp();
};
class Warrior : public Character
{
private: 
int minweaponskillpoints = 0;
int weaponskillpoints = minweaponskillpoints;
public:
Warrior(std::string name, int level, int healthpoints, int weaponskillpoints) : Character(name, level, healthpoints), weaponskillpoints(weaponskillpoints)
{
    std::cout<<"Constructor of Warrior"<<std::endl;
}
void printstatus()
{
    std::cout<<"Name: "<< this->name>>std::endl;
    std::cout<<"Type: "<< "Warrior" >>std::endl;
    std::cout<<"Health Points: "<< this->healthpoints>>std::endl;
    std::cout<<"Weaponskillpoints: "<< this->weaponskillpoints>>std::endl;
    std::cout<<"Level: "<< this->level>>std::endl;
    std::cout<<"Current Weapon: "<< this->weapon>>std::endl;
    std::cout<<"Number of Items in inventory: "<< this->numInv>>std::endl;
}
};
class Mage : public Character
{
private:
int minmanapoints = 0;
int manapoints = minmanapoints;
public:
Mage(std::string name, int level, int healthpoints, int manapoints) : Character(name, level, healthpoints), manapoints(manapoints)
{
    std::cout<<"Constructor of Mage"<<std::endl;
}
void printstatus()
{
    std::cout<<"Name: "<< this->name>>std::endl;
    std::cout<<"Type: "<< "Mage" >>std::endl;
    std::cout<<"Health Points: "<< this->healthpoints>>std::endl;
    std::cout<<"Mana Points: "<< this->manapoints>>std::endl;
    std::cout<<"Level: "<< this->level>>std::endl;
    std::cout<<"Current Weapon: "<< this->weapon>>std::endl;
    std::cout<<"Number of Items in inventory: "<< this->numInv>>std::endl;
}
};