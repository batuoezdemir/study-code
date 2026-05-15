#include <iostream>
#include <string>

class User
{
    protected:
    std::string name;
    int id;
    public:
    User(std::string name, int id): name(name), id(id)
    {
        std::cout<<"Constructor of User"<<std::endl;
    }
    void printinfo();
};
void User::printinfo()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Id: "<<id<<std::endl;
}
class Student : public User
{
    private :
    int matNr;
    public:
    Student(int matNr, std::string name, int id) : User(name, id), matNr(matNr)
    {
        std::cout<<"Constructor of Student"<<std::endl;
    }
    void printRole()
    {
        std::cout<<"Role: "<<"Student"<<std::endl;
        std::cout<<"Id: "<< this->id<< std::endl;
        std::cout<<"Name: "<< this->name <<std::endl;
        std::cout<<"Matrikelnummer: "<< this-> matNr <<std::endl;
    }
};
class Instructor : public User
{
    private:
    const int defaultsalary = 3000;
    int salary = defaultsalary;
    public:
    Instructor(int salary, std::string name, int id) : User(name, id), salary(salary)
    {
        std::cout<<"Constructor of Instructor"<<std::endl;
    }
    void printRole()
    {
        std::cout<<"Role: "<<"Instructor"<<std::endl;
        std::cout<<"Id: "<< this->id<< std::endl;
        std::cout<<"Name: "<< this->name <<std::endl;
        std::cout<<"Salary: "<< this->salary <<std::endl;
    }
};
int main()
{
    Student stududent(3489, "jason", 22);
    Instructor instructore(4000, "James", 23);
    stududent.printinfo();
    stududent.printRole();
    instructore.printinfo();
    instructore.printRole();
    return 0;
}