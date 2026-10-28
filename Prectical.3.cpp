#include <iostream>
#include <utility>
using namespace std;

class DynamicArray
{
    int *data;
    int size;

public:
    // Default Constructor
    DynamicArray()
    {
        size = 0;
        data = nullptr;
    }

    // Parameterized Constructor
    DynamicArray(int n)
    {
        if (n > 0)
        {
            size = n;
            data = new int[size]();
        }
        else
        {
            size = 0;
            data = nullptr;
        }
    }

    // Copy Constructor
    DynamicArray(const DynamicArray &obj)
    {
        size = obj.size;

        if (size > 0)
        {
            data = new int[size]();

            for (int i = 0; i < size; i++)
            {
                data[i] = obj.data[i];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    // Copy Assignment Operator
    DynamicArray &operator=(const DynamicArray &obj)
    {
        if (this != &obj)
        {
            int *newData = nullptr;

            if (obj.size > 0)
            {
                newData = new int[obj.size];

                for (int i = 0; i < obj.size; i++)
                {
                    newData[i] = obj.data[i];
                }
            }

            delete[] data;

            size = obj.size;
            data = newData;
        }

        return *this;
    }

    // Move Constructor
    DynamicArray(DynamicArray &&obj)
    {
        size = obj.size;
        data = obj.data;

        obj.size = 0;
        obj.data = nullptr;
    }

    // Move Assignment Operator
    DynamicArray &operator=(DynamicArray &&obj)
    {
        if (this != &obj)
        {
            delete[] data;

            size = obj.size;
            data = obj.data;

            obj.size = 0;
            obj.data = nullptr;
        }

        return *this;
    }

    // Destructor
    ~DynamicArray()
    {
        delete[] data;
    }

    // Input Elements
    void inputElements()
    {
        cout << "Enter " << size << " array elements: ";

        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
    }

    // Display Elements
    void showElements()
    {
        cout << "Array elements: ";

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << "\n";
    }
};

int main()
{
    cout << "Student Name: Ramesh Kumar\n";
    cout << "URN: E25B001202\n\n";

    DynamicArray first; // Default Constructor

    DynamicArray second(5); // Parameterized Constructor
    second.inputElements();
    second.showElements();

    DynamicArray third(second); // Copy Constructor
    third.showElements();

    first = second; // Copy Assignment Operator
    first.showElements();

    DynamicArray fourth(move(second)); // Move Constructor
    fourth.showElements();

    DynamicArray fifth;
    fifth = move(third); // Move Assignment Operator
    fifth.showElements();

    return 0;
}
