#include<iostream>
#include <string>

class Bankaccount
{
    private:
    std::string Owner;
    double balance = 0.0;

    public:
void setOwner(std::string ownerName)
{
    Owner = ownerName;
}
std::string getOwner()
{
    return Owner;
}
double deposit(double dAmount)
{
    if (dAmount > 0)
    {
    balance += dAmount;
    std::cout << "new Balance: " << balance << std::endl;
    return balance;
    }
    else
    {
        std::cout<<"deposits have to be > 0 "<<std::endl;
        return balance;
    }
}
    double withdraw(double wAmount)
    {
        if (wAmount > 0 && wAmount <= balance)
        {
            balance -= wAmount;
            std::cout << "new Balance: " << balance << std::endl;
            return balance;
        }
        else
        {
            std::cout<<"invalid amount"<<std::endl;
            return balance;
        }
    }
    double getBalance();
    void getAccountInfo();
};
double Bankaccount::getBalance()
{
    return balance;
}
void Bankaccount::getAccountInfo()
{
    std::cout << "Owner: " << getOwner() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
}
int main()
{
    Bankaccount myAcc;
    myAcc.setOwner("Batu");
    myAcc.deposit(33.6);
    myAcc.withdraw(32.8);
    myAcc.getAccountInfo();
}