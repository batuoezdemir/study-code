# include <iostream>
#include <string>
class Product
{
    private:
    int Id;
    std::string name;
    int weight;
    int temp;
    bool vsds;
    public:
    Product(int Id, std::string name, int weight, int temp, bool vsds)
    {
        std::cout<<"Constructor of Products"<<std::endl;
    }
    int getId()
    {
        return Id;
    }
    std::string getName()
    {
        return name;
    }
    int getWeight()
    {
        return weight;
    }
    int getTemp()
    {
        return temp;
    }
    bool getVsds()
    {
        return vsds;
    }
    void productReport();

};
class CE : public Product
{
public:
    CE(int Id, std::string name, int weight, int temp, bool vsds): Product(Id, name, weight, temp, vsds)
    {
        std::cout<<"Constructor of Combustion Engine"<<std::endl;
    }
std::string getProductType()
{
    return "Combustion Engine";
}
};
class EE : public Product
{
private:
double voltage;
public:
    EE(int voltage, int Id, std::string name, int weight, int temp, bool vsds): voltage(voltage), Product(Id, name, weight, temp, vsds)
    {
        std::cout<<"Constructor of Combustion Engine"<<std::endl;
    }
std::string getProductType()
{
    return "Electrical Engine";
}
};