#include <iostream>

using namespace std;

int main(){

    int nWorkingDays;
    int nWorkingHours;

    cout << "Please enter working days" << endl;
    cin >> nWorkingDays;

    cout << "Please enter working hours" << endl;
    cin >> nWorkingHours;

    int nTotalHours;
    nTotalHours = nWorkingDays * nWorkingHours;
    
    cout << "The result is: " << nTotalHours << endl;

    return 0;

}