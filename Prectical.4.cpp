
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Learner
{
    string name;

public:
    Learner(string name)
    {
        this->name = name;
    }

    void display()
    {
        cout << "Name of Student: " << name << "\n";
    }

    ~Learner()
    {
        cout << "Object destroyed: " << name << "\n";
    }
};

int main()
{
    cout << "Student name: Ramesh Kumar\nURN: E25B001202\n\n";
    {                                                          // Empty scope
        unique_ptr<Learner> a = make_unique<Learner>("Apple"); // This object is a resource uniquely owned.
        a->display();
    }
    cout << "The unique pointer and the its owned object gets destroyed upon leaving the scope.\n";

    {
        shared_ptr<Learner> b;
        {
            shared_ptr<Learner> c = make_shared<Learner>("Banana");
            b = c; // The object owned by c is now also owned by b. Thus, it is a shared resource.
        }
        cout << "The object owned by the shared pointer does not get destroyed upon leaving the inner scope \n as one of the shared pointer is still alive, despite c being destroyed";
    }
    cout << "The object now gets destroyed because all shared pointers related to the object are out of scope.";

    return 0;
}
