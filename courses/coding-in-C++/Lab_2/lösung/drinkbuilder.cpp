#include <iostream>
#include <string>

class Drinkbuilder
{
    private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;
    public:
    Drinkbuilder(std::string name,int sugar, int temperature, bool withMilk): name(name), sugar(sugar), temperature(temperature), withMilk(withMilk){};
    Drinkbuilder &setName(const std::string& name)
    {
        this->name=name;
        return *this;
    }
    Drinkbuilder &setSugar(int sugar)
    {
        if (sugar>0)
        {
            this->sugar=sugar;
        }
        return *this;
    }
    Drinkbuilder &setTemperature(int temperature)
    {
        if (temperature > 0)
        {
            this->temperature=temperature;
        }
        return *this;
    }
    Drinkbuilder &setWithMilk(bool withMilk)
    {
        this->withMilk=withMilk;
        return *this;
    }
    Drinkbuilder &print();
};
Drinkbuilder& Drinkbuilder::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Sugar: " << this->sugar << std::endl;
    std::cout << "Temperature: " << this->temperature << std::endl;
    std::cout << "With milk: " << (this->withMilk ? "yes" : "no") << std::endl;
    return *this;
}
int main()
{
    Drinkbuilder getränk("cola", 22, 30, false);
    getränk.print();
}