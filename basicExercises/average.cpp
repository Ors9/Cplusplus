#include <iostream>

using namespace std;

int main(){

    int sum = 0;


    for(int i = 0 ; i < 3 ; i++){
        int nNumber ;
        cout << "Please enter " << i + 1 << " number" << endl;
        cin >> nNumber;
        sum += nNumber;
    }

    cout << "The average is: " << sum / 3 << endl;


    return 0;
}