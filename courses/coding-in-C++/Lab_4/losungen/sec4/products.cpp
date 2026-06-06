#include <iostream>
#include "products.hpp"
#include <string>
Product::Product(int Id, std::string name, int weight, int temp, bool vsds): Id(Id), Name(name), weight(weight), temp(temp), vsds(vsds)
{
    std::cout<<"Constructor of Product"<<std::endl;
}
Product::productReport()
{
    std::cout<<
}