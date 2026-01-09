#include <iostream>
#include <limits>

using namespace std;


int main(){

    char c;

    cout << "Please enter a small character" << endl;
    while(!(cin >> c) || c < 'a' || c > 'z'){
        cout << "Invalid input please enter only small characeter" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
    }

    char upperC = c - 32;

    cout << "The upper is " << upperC << endl;


    return 0;
}