#include <iostream>
#include <string>
class User
{
    protected:
    int id;
    std::string name;
    public:
    User(int id, std::string name): id(id), name(name)
    {};
    void printInfo()
    {
        std::cout<<"Id: "<<id<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
    }
};
class Student : public User
{
    private:
    int score;
    public:
    Student(int id, int score, std::string name) : score(score), User(id, name){};
    void printRole()
    {
        std::cout<<"Role: Student"<<std::endl;
        printInfo();
    }
};
class Instructor : public User
{
    private:
    int salary;
    public:
    Instructor(int salary, int id, std::string name): salary(salary), User(id, name){};
   void printRole()
    {
        std::cout<<"Role: Instructor"<<std::endl;
        printInfo();
    }
};
int main()
{
    Student schüler(13, 222, "James");
    Instructor Siggi(1967, 205087, "Patrick Sieger");
    Siggi.printRole();
    schüler.printRole();
}