#include <iostream>
#include <limits>

using namespace std;

int main()
{

    int nFirst;
    int nSecond;

    cout << "Please enter first number" << endl;
    while (!(cin >> nFirst))
    {
        cout << "Invalid input! Please enter a whole number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter second Whole number" << endl;
    while (!(cin >> nSecond) || nSecond == 0)
    {
        cout << "Invalid input! Please enter a whole number: also not 0 ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "The sum is " << nFirst + nSecond << endl;
    cout << "The sub is " << nFirst - nSecond << endl;
    cout << "The * is " << nFirst * nSecond << endl;
    cout << "The / is " << nFirst / nSecond << endl;
    cout << "The % is " << nFirst % nSecond << endl;

    return 0;
}