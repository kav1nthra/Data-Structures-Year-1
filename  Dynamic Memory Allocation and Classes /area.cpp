#include <iostream>
using namespace std;

class Area {
public:
    int length, breadth, height;

    // Function declarations for different area calculations
    int square(int side);
    int cuboid(int l, int b, int h);
    int cube(int side);
    int rectangle(int length, int breadth);
};

// Calculates area of square
int Area::square(int side) {
    int area = side * side;
    cout << "Area of the given Square is " << area << endl;
    return 0;
}

// Calculates surface area of cuboid
int Area::cuboid(int l, int b, int h) {
    int area = 2 * (h * b + h * l + l * b);
    cout << "Area of the given Cuboid is " << area << endl;
    return 0;
}

// Calculates surface area of cube
int Area::cube(int side) {
    int area = 6 * side * side;
    cout << "Area of the given Cube is " << area << endl;
    return 0;
}

// Calculates area of rectangle
int Area::rectangle(int length, int breadth) {
    int area = length * breadth;
    cout << "Area of the given Rectangle is " << area << endl;
    return 0;
}

int main() {
    int choice;
    Area obj;

    // Infinite loop for menu-driven area calculation
    while (true) {
        cout << "Menu card" << endl;
        cout << "Enter 1 : To find the Area of Square" << endl;
        cout << "Enter 2 : To find the Area of Cube" << endl;
        cout << "Enter 3 : To find the Area of Rectangle" << endl;
        cout << "Enter 4 : To find the Area of Cuboid" << endl;
        cout << "Enter 5 : To Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case to handle different area options
        switch (choice) {
            case 1:
                cout << "Enter the side of the Square: ";
                cin >> obj.length;
                obj.square(obj.length);
                break;
            case 2:
                cout << "Enter the side of the Cube: ";
                cin >> obj.length;
                obj.cube(obj.length);
                break;
            case 3:
                cout << "Enter the length of the Rectangle: ";
                cin >> obj.length;
                cout << "Enter the breadth of the Rectangle: ";
                cin >> obj.breadth;
                obj.rectangle(obj.length, obj.breadth);
                break;
            case 4:
                cout << "Enter the length of the Cuboid: ";
                cin >> obj.length;
                cout << "Enter the breadth of the Cuboid: ";
                cin >> obj.breadth;
                cout << "Enter the height of the Cuboid: ";
                cin >> obj.height;
                obj.cuboid(obj.length, obj.breadth, obj.height);
                break;
            case 5:
                cout << "Program Ended" << endl;
                cout << "Thank You";
                return 0;
            default:
                cout << "Please enter a number between 1 to 5" << endl;
        }
    }
}
