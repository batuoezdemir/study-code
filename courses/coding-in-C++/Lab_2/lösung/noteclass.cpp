#include <iostream>
#include <string>

class Note
{
    private:
    std::string* text;
    public:
    Note(std::string message)
    {
        text = new std::string(message);
    }
    Note(const Note& other)
    {
        text = new std::string(*other.text);
    }
    ~Note()
    {
    delete text;
    text = nullptr;
    std::cout << "Memory released" << std::endl;
    }
    void display()
    {
        std::cout<<*text<<std::endl;
    }
};
int main()
{
    Note notiz("hallo was geht");
    Note notiz2 = notiz;
    notiz.display();
    notiz2.display();
}