#include <iostream>
#include <string>

class Course
{
    private:
    std::string title;
    std::string description;
    int maxLessons = 100;
    int lessonCount = 0;
    Lesson lessons[100];
    public:
    Course() {}
    Course(std::string title, std::string description)
    : title(title), description(description) {}
    void createLesson(std::string title)
            {
        if (lessonCount < 100)
        {
            lessons[lessonCount] = Lesson(title);
            lessonCount++;
        }
    }
    void deleteLesson(std::string title)
        {
    for (int i = 0; i < lessonCount; i++)
    {
        if (lessons[i].getTitle() == title)
        {
            for (int j = i; j < lessonCount - 1; j++)
            {
                lessons[j] = lessons[j + 1];
            }

            lessonCount--;
            std::cout << "Lesson deleted: " << title << std::endl;
            return;
        }
    }
    std::cout << "Course not found: " << title << std::endl;
}
    std::string getTitle()
    {
        return title;
    }
    void setTitle(std::string title)
    {
        this->title = title;
    }
    std::string getDescription()
    {
        return description;
    }
    void setDescription(std::string description)
    {
        this->description = description;
    }
};
class Platform 
{
    private:
    int maxCourses = 100;
    int courseCount = 0;
    Course Courses[100];
    public:
    Platform(){};
    void createCourse(std::string title, std::string description)
        {
        if (courseCount < 100)
        {
            Courses[courseCount] = Course(title, description);
            courseCount++;
        }
    }
    void deleteCourse(std::string title)
    {
    for (int i = 0; i < courseCount; i++)
    {
        if (Courses[i].getTitle() == title)
        {
            for (int j = i; j < courseCount - 1; j++)
            {
                Courses[j] = Courses[j + 1];
            }

            courseCount--;
            std::cout << "Course deleted: " << title << std::endl;
            return;
        }
    }
    std::cout << "Course not found: " << title << std::endl;
}
    void registerUser();
};
class Content
{
    private:
    std::string type;
    std::string title;
    public:
    Content() {}
    Content(std::string type, std::string title)
    : type(type), title(title) {}    
    std::string getTitle()
    {
        return title;
    }
    void setTitle(std::string title)
    {
        this->title = title;
    }
    void displayContent()
    {
        std::cout<<"title: "<<getTitle()<<"Type: "<<type<<std::endl;
    }
};
class Lesson
{
    private: 
    std::string title;
    int maxContents = 100;
    int contentCount = 0;
    Content contents[100];
    public:
    Lesson() {}
    Lesson(std::string title): title(title){};
    void setTitle(std::string title)
    {
        this->title = title;
    }
    std::string getTitle()
    {
        return title;
    }
    std::string createContent(std::string type, std::string title)
    {
        if (contentCount < 100)
        {
            contents[contentCount] = Content(type,  title);
            contentCount++;

        }
    }
    void deleteContent(std::string title)
{
    for (int i = 0; i < contentCount; i++)
    {
        if (contents[i].getTitle() == title)
        {
            for (int j = i; j < contentCount - 1; j++)
            {
                contents[j] = contents[j + 1];
            }

            contentCount--;
            std::cout << "Content deleted: " << title << std::endl;
            return;
        }
    }

    std::cout << "Content not found: " << title << std::endl;
}};
class User
{
private:
    std::string name;
    std::string address;

    Course* enrolledCourses[100];
    int enrolledCount = 0;

public:
    User(std::string name, std::string address)
        : name(name), address(address) {}

    void joinPlatform()
    {
        std::cout << name << " joined the platform." << std::endl;
    }

    void leavePlatform()
    {
        std::cout << name << " left the platform." << std::endl;
    }

    void enroll(Course* course)
    {
        if (enrolledCount < 100)
        {
            enrolledCourses[enrolledCount] = course;
            enrolledCount++;
            std::cout << name << " enrolled in course: "
                      << course->getTitle() << std::endl;
        }
    }

    void leaveCourse(std::string title)
    {
        for (int i = 0; i < enrolledCount; i++)
        {
            if (enrolledCourses[i]->getTitle() == title)
            {
                for (int j = i; j < enrolledCount - 1; j++)
                {
                    enrolledCourses[j] = enrolledCourses[j + 1];
                }

                enrolledCount--;
                std::cout << name << " left course: " << title << std::endl;
                return;
            }
        }

        std::cout << "Course not found for user: " << title << std::endl;
    }
};
int main()
{
    Platform platte;
    platte.createCourse("maths", "difficult");
    platte.createCourse("deutsch", "difficult");
    platte.deleteCourse("maths");
    Course deutsch;
    deutsch.createLesson("e technik");
    deutsch.setTitle("kake");
    deutsch.setDescription("sehr kake");
    deutsch.deleteLesson("e technik");
}