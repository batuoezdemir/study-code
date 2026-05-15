#include <iostream>
#include <string>

template <typename T, typename U>
class Pair {
private:
    T value1;
    U value2;
public:
    Pair(T value1, U value2) : value1(value1), value2(value2) 
    {
        std::cout << "Constructor of Pair" << std::endl;
    }
    T getvalue1() { return this->value1; }
    void setvalue1(T value1) { this->value1 = value1; }
    U getvalue2() { return this->value2; }
    void setvalue2(U value2) { this->value2 = value2; }
};
int main() {
    Pair<std::string, int> myPair("Hello", 42);
    std::cout << "First: " << myPair.getvalue1() << std::endl;
    std::cout << "Second: " << myPair.getvalue2() << std::endl;
    return 0;
}
