#include <iostream>
#include <string>
using namespace std;

class Human
{
protected:
    // Protected members can be accessed within this class and its derived classes.
    string name;
    int age;

public:
    Human()
    {
        name = "";
        age = 0;
    }

    Human(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

// Learner publicly inherits from Human.
class Learner : public Human
{
protected:
    string Id, course;

public:
    Learner()
    {
        this->name = "";
        this->age = 0;
        this->Id = "";
        this->course = "";
    }

    Learner(string name, int age, string Id, string course)
    {
        this->name = name;
        this->age = age;
        this->Id = Id;
        this->course = course;
    }

    void display()
    {
        Human::display();
        cout << "Id: " << Id << "\n";
        cout << "Course: " << course << "\n";
    }
};

// ResearchStudent publicly inherits from Learner.
// This forms multilevel inheritance:
// Human -> Learner -> ResearchStudent.
class ResearchStudent : public Learner
{
private:
    string research;

public:
    ResearchStudent(string name, int age, string Id, string course, string research)
    {
        this->name = name;
        this->age = age;
        this->Id = Id;
        this->course = course;
        this->research = research;
    }

    void display()
    {
        Learner::display();
        cout << "Research Topic: " << research << "\n";
    }
};

int main()
{
    cout << "Student name: RAMESH KUMAR\nURN: E25B001202\n\n";
    Human a("Apple", 2);
    a.display();
    cout << "\n";

    // Single Inheritance
    Learner b("Banana", 12, "A2026F", "CSE");
    b.display();
    cout << "\n";

    // Multi-level Inheritance
    ResearchStudent c("Cherry", 12, "A2026F", "CSE", "Fruits");
    c.display();
    cout << "\n";

    return 0;
}
