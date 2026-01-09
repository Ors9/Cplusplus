#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    double radius;
    const double PI = 3.14159265358979323846;

    cout << "Please enter Radius" << endl;

    while (!(cin >> radius) || radius < 0)
    {
        cout << "Invalid input! Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double shetah = pow(radius, 2) * PI;
    double eikef = 2 * radius * PI;

    cout << fixed << setprecision(4);

    cout << "The shetah is: " << shetah << endl;
    cout << "The eikef is : " << eikef << endl;

    return 0;
}