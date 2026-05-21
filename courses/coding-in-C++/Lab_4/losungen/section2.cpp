#include <iostream>

class Shape {
public:
virtual double area() const {
return 0.0;}
virtual ~Shape(){};
};
class circle : public Shape
{
    private:
    double radius;
    public:
    circle(double radius) : radius(radius)
    {};
    double area() const override
    {
        return 3.141 * radius * radius;
    }
};
class rectangle : public Shape{
    private:
    double height;
    double width;
    public:
    rectangle(double height, double width): height(height), width(width)
    {};
    double area() const override
    {
        return width * height;
    }
};
int main()
{
    circle c(2.0);
    circle g(2.0);
    rectangle r(2.0, 5.0);
    rectangle s(2.0, 5.0);
    Shape* shapes[4];
    shapes[0] = &c;
    shapes[1] = &r;
    shapes[2] = &g;
    shapes[3] = &s;
    for (int i=0; i<4; i++)
    {
        std::cout<<shapes[i]->area()<<std::endl;
    }
}