#include <iostream>
using namespace std;

class GeometricShape
{
public:
    // Pure virtual function makes GeometricShape an abstract class.
    virtual void area() = 0;

    // Virtual destructor ensures proper cleanup of derived objects using base pointers.
    virtual ~GeometricShape() = default;
};

class RoundShape : public GeometricShape
{
private:
    double radius;

public:
    RoundShape(double radius)
    {
        this->radius = radius;
    }

    void area() override
    {
        if (radius <= 0)
        {
            cout << "Invalid radius for circle.\n";
            return;
        }
        cout << "Area of circle: " << 3.14 * radius * radius << "m^2\n";
    }
};

class TriangularShape : public GeometricShape
{
private:
    double height, base;

public:
    TriangularShape(double height, double base)
    {
        this->height = height;
        this->base = base;
    }

    void area() override
    {
        if (height <= 0 || base <= 0)
        {
            cout << "Invalid dimensions for triangle.\n";
            return;
        }
        cout << "Area of Triangle: " << 0.5 * base * height << "m^2\n";
    }
};

class RectangularShape : public GeometricShape
{
private:
    double height, width;

public:
    RectangularShape(double height, double width)
    {
        this->height = height;
        this->width = width;
    }

    void area() override
    {
        if (height <= 0 || width <= 0)
        {
            cout << "Invalid dimensions for rectangle.\n";
            return;
        }
        cout << "Area of Rectangle: " << height * width << "m^2\n";
    }
};

int main()
{
    cout << "Student name: RAMESH KUMAR\nURN: E25B001202\n\n";

    RoundShape a(2);
    TriangularShape b(4, 2);
    RectangularShape c(10, 20);

    // GeometricShape cannot be instantiated because it is abstract:
    // GeometricShape s;  // Compilation error: area() is pure virtual.

    GeometricShape *ptrs[] = {&a, &b, &c};

    ptrs[0]->area();
    ptrs[1]->area();
    ptrs[2]->area();

    return 0;
}
