#include <iostream>
#include <string>

class User
{
    protected:
    std::string name;
    int id;
    public:
    User (std::string name, int id) : name(name), id(id)
    {
        std::cout << "Constructor of User" << std::endl;
    }
    void printInfo()
};

void User::printInfo()
{
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name << '\n';
}
int main()
{
    class Student : public User
    {
        private:
        int matNr;
        public:
        Student (std::string name, int id, int matNr) : User(name, id), matNr(matNr)
        {
            std::cout << "Constructor of Student" << std::endl;
        }
        void printRole()
        {
            std::cout << "Rolle: " << "Student" << '\n';
            std::cout << "ID: " << this->id << '\n';
            std::cout << "Name: " << this->name << '\n';
    }
}
