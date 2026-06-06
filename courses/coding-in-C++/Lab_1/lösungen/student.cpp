#include <iostream>
#include <string>   // BEARBEITET
#include <limits>   // BEARBEITET

void readScore(const std::string& text, int& value) // BEARBEITET
{
    int maxScore = 100;
    int minScore = 0;

    while (true) // BEARBEITET
    {
        std::cout << text << std::endl;

        if (!(std::cin >> value)) // BEARBEITET
        {
            std::cout << "Invalid, try again" << std::endl;
            std::cin.clear(); // BEARBEITET
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BEARBEITET
        }
        else if (value < minScore || value > maxScore) // BEARBEITET
        {
            std::cout << "Invalid, try again" << std::endl;
        }
        else
        {
            break; // BEARBEITET
        }
    }
}

void readStudentData(std::string& name, int& homework, int& midterm, int& finalExam) // BEARBEITET
{
    std::cout << "Your name: " << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BEARBEITET

    if (!(std::getline(std::cin, name)))
    {
        std::cout << "Invalid, try again" << std::endl;
    }

    readScore("Your homework grade: ", homework);
    readScore("Your midterm grade: ", midterm);
    readScore("Your final exam grade: ", finalExam);
}

void calculateGrade(int homework, int midterm, int finalExam, int& finalGrade, char& letterGrade) // BEARBEITET
{
    finalGrade = homework * 0.4 + midterm * 0.25 + finalExam * 0.35; // BEARBEITET

    if (finalGrade >= 90)
    {
        letterGrade = 'A'; // BEARBEITET
    }
    else if (finalGrade >= 80) // BEARBEITET
    {
        letterGrade = 'B';
    }
    else if (finalGrade >= 70)
    {
        letterGrade = 'C';
    }
    else if (finalGrade >= 60)
    {
        letterGrade = 'D';
    }
    else if (finalGrade >= 50)
    {
        letterGrade = 'E';
    }
    else
    {
        letterGrade = 'F';
    }
}

void printReport(std::string name,
                 int homework,
                 int midterm,
                 int finalExam,
                 int finalGrade,
                 char letterGrade) // BEARBEITET
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Homework: " << homework << std::endl;
    std::cout << "Midterm: " << midterm << std::endl;
    std::cout << "Final exam: " << finalExam << std::endl;
    std::cout << "Final grade: " << finalGrade << std::endl;
    std::cout << "Letter grade: " << letterGrade << std::endl;
}

int main()
{
    std::string name;
    int homework = 0;   // BEARBEITET
    int midterm = 0;    // BEARBEITET
    int finalExam = 0;  // BEARBEITET
    int finalGrade = 0; // BEARBEITET
    char letterGrade = 'F'; // BEARBEITET

    readStudentData(name, homework, midterm, finalExam); // BEARBEITET
    calculateGrade(homework, midterm, finalExam, finalGrade, letterGrade); // BEARBEITET
    printReport(name, homework, midterm, finalExam, finalGrade, letterGrade); // BEARBEITET

    return 0; // BEARBEITET
}