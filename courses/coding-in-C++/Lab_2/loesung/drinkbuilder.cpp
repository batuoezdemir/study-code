#include <iostream>
#include <string>

constexpr int MinS = 0;
constexpr int MinT = 0;

class DrinkBuilder
{
private:
    std::string name;
    int sugar = MinS;
    int temperature = MinT;
    bool withMilk;

public:
    DrinkBuilder(std::string name, int sugar, int temperature, bool withMilk);

    DrinkBuilder& setName(const std::string& name);
    DrinkBuilder& setSugar(int sugar);
    DrinkBuilder& setTemperature(int temperature);
    DrinkBuilder& setWithMilk(bool withMilk);

    const DrinkBuilder& print() const;
    bool isValid() const;
};

DrinkBuilder::DrinkBuilder(std::string name, int sugar, int temperature, bool withMilk)
    : name(name), sugar(sugar), temperature(temperature), withMilk(withMilk)
{
    if (this->sugar < MinS)
    {
        this->sugar = MinS;
    }

    if (this->temperature < MinT)
    {
        this->temperature = MinT;
    }
}

DrinkBuilder& DrinkBuilder::setName(const std::string& name)
{
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(int sugar)
{
    if (sugar >= MinS)
    {
        this->sugar = sugar;
    }
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature(int temperature)
{
    if (temperature >= MinT)
    {
        this->temperature = temperature;
    }
    return *this;
}

DrinkBuilder& DrinkBuilder::setWithMilk(bool withMilk)
{
    this->withMilk = withMilk;
    return *this;
}

const DrinkBuilder& DrinkBuilder::print() const
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Sugar: " << this->sugar << std::endl;
    std::cout << "Temperature: " << this->temperature << std::endl;
    std::cout << "Milk: " << this->withMilk << std::endl;

    return *this;
}

bool DrinkBuilder::isValid() const
{
    bool valid = true;

    if (this->sugar < MinS)
    {
        std::cout << "Hey - you should add more sugar" << std::endl;
        valid = false;
    }

    if (this->temperature <= MinT)
    {
        std::cout << "I have a sore throat - increase the temperature" << std::endl;
        valid = false;
    }

    if (valid)
    {
        std::cout << "That's perfect!" << std::endl;
    }

    return valid;
}

int main()
{
    DrinkBuilder getraenk("name", 5, 30, true);

    getraenk.print();

    getraenk.setName("anderes getraenk")
        .setSugar(10)
        .setTemperature(50)
        .setWithMilk(false)
        .print();

    getraenk.isValid();

    return 0;
}



