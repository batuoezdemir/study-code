#include <iostream>

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
    virtual ~Shape() {}
};

class Circle : public Shape 
{
    private:
    double radius;
    public:
    Circle(double r): radius(r) {}
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    private: 
    double height;
    double width;
    public:
    Rectangle(double h, double w): height(h), width(w) {}
    double area() const override {
        return 0,5*h*w;
    }
};
int main()
{
    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    std::cout << "Area of Circle: " << c.area() << std::endl;
    std::cout << "Area of Rectangle: " << r.area() << std::endl;
    return 0;
    Shape* shapes[4];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Circle(2.0);

    shapes[2] = new Rectangle(4, 5);
    shapes[3] = new Rectangle(2, 6);
    for (int i; i<4; i++)
    {
        cout << shapes[i]->area() << endl;

    }
}
