#include <iostream>
template <typename U , typename B>
class Paar
{
private:
    U value1;
    B value2;

public:
    Paar(U value1, B value2) : value1(value1), value2(value2) {};
    U getValue1() const { return value1; }
    B getValue2() const { return value2; }
    void setValue1(U value) { this->value1 = value; }
    void setValue2(B value) { this->value2 = value;}
};

int main()
{
    Paar paaar(222, "geilo");
    std::cout<< paaar.getValue1() <<std::endl;
    std::cout<< paaar.getValue2() <<std::endl;
}