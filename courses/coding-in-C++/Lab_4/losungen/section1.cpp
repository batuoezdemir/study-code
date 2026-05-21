#include <iostream>
#include <cmath>

class Vector2D
{
    private:
    double x;
    double y;
    public:
    Vector2D(double x, double y) : x(x), y(y)
    {
        std::cout << "Constructor of Vector2D" << std::endl;
    }
    void printInfo()
    {
        std::cout << "x: " << this->x << '\n';
        std::cout << "y: " << this->y << '\n';
        std::cout << "Magnitude: " << this->getMagnitude() << '\n';
    }
    double getx()
    {
        return this->x;
    }
    double gety()
    {
        return this->y;
    }
    double getMagnitude()
    {
        return sqrt((x * x) + (y * y));
    }
};
int main()
{
    Vector2D v1(1.0, 2.0);
    v1.printInfo();
}



