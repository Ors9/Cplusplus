#include <iostream>

using namespace std;

#define SMALL_ROOM_PRICE 25
#define BIG_ROOM_PRICE 35
#define SALES_TAX_RATE 0.06
#define ESTIMATE_DAYS 30

int main()
{
    int smallRooms{0};
    int bigRooms{0};

    cout << "How mouch Big room you want clean? " << endl;

    while (!(cin >> bigRooms) || bigRooms < 0)
    {
        cout << "Enter only integer >= 0 " << endl;
    }

    cout << "How mouch Small room you want clean? " << endl;

    while (!(cin >> smallRooms) || smallRooms < 0)
    {
        cout << "Enter only integer >= 0 " << endl;
    }

    int totalSmallRooms = smallRooms * SMALL_ROOM_PRICE;
    int totalBigRooms = bigRooms * BIG_ROOM_PRICE;
    int cost = totalBigRooms + totalSmallRooms;

    cout << "Number of small rooms: " << smallRooms << endl;
    cout << "Number of big rooms: " << bigRooms << endl;
    cout << "price per small rooms: " << SMALL_ROOM_PRICE << endl;
    cout << "price per  big rooms: " << BIG_ROOM_PRICE << endl;
    cout << "cost" << cost << endl;
    cout << "tax "<< cost * SALES_TAX_RATE <<endl;
    cout << "===================" << endl;
    cout << "This  estimates  valid for " << ESTIMATE_DAYS << endl;
    return 0;
}