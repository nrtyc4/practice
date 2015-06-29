#include <iostream>
using namespace std;

//Base class
class Shape {
    public:
        // pure virtual function providing interface
        virtual int getArea() = 0;
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }

    protected:
        int width;
        int height;
};

//Derived class
class Rectangle: public Shape {
    public:
        int getArea() {
            return (width * height);
        }
};

class Triangle: public Shape {
    public:
        int getArea() {
            return (width * height) / 2;
        }
};

int main() {
    Rectangle r;
    Triangle t;

    r.setWidth(5);
    r.setHeight(7);
    cout << "Total Rectangle area: " << r.getArea() << endl;

    t.setWidth(5);
    t.setHeight(7);
    cout << "Total Triangle area: " << t.getArea() << endl;

    return 0;
}
