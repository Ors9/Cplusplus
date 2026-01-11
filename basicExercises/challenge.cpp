#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum OP_RESULT
{
    QUIT,
    BAD_INPUT,
    GOOD_INPUT,
};

// Prototypes
void print_menu();
OP_RESULT check_op(char operation, vector<int> &my_list);
void display_largest(const vector<int> &my_list);
void display_smallest(const vector<int> &my_list);
void display_avarage(const vector<int> &my_list);
void print_list(const vector<int> &my_list);
void add_number(vector<int> &my_list);

int main()
{

    vector<int> my_list{};

    /*This challenge is for using collection list of integers and perform operation on the list*/
    print_menu();
    OP_RESULT result = GOOD_INPUT;
    char operation{' '};

    while (true)
    {

        if (!(cin >> operation) || (result = check_op(operation, my_list)) == BAD_INPUT)
        {
            cout << "Error insert only a character the operations are:" << endl;
            print_menu();
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (result == QUIT)
        {
            break;
        }

        if (result == GOOD_INPUT)
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return 0;
}

void print_menu()
{
    cout << "P - Print numbers" << endl;
    cout << "A - add a number " << endl;
    cout << "M - display mean of the numbers " << endl;
    cout << "S - Display the smallest number " << endl;
    cout << "L - Display the largest number " << endl;
    cout << "Q - Quit " << endl;
    cout << "Enter your choice: " << endl;
}

void print_list(const vector<int> &my_list)
{
    cout << "[";
    for (int l : my_list)
    {
        cout << " " << l;
    }
    cout << "]";
    if (my_list.empty())
    {
        cout << " - The list is empty" << endl;
    }
    else
    {
        cout << endl;
    }
}

OP_RESULT check_op(char operation, vector<int> &my_list)
{
    switch (operation)
    {
    case 'P':
    case 'p':
        print_list(my_list);
        break;
    case 'A':
    case 'a':
        add_number(my_list);
        break;
    case 'M':
    case 'm':
        display_avarage(my_list);
        break;
    case 'S':
    case 's':
        display_smallest(my_list);
        break;
    case 'L':
    case 'l':
        display_largest(my_list);
        break;
    case 'Q':
    case 'q':
        return QUIT;
    default:
        return BAD_INPUT;
        break;
    }

    return GOOD_INPUT;
}

void display_avarage(const vector<int> &my_list)
{

    if (my_list.empty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    int sum{0};
    for (int curr : my_list)
    {
        sum += curr;
    }
    double avarage = static_cast<double>(sum) / my_list.size();
    cout << "The Average is: " << avarage << endl;
}

void display_largest(const vector<int> &my_list)
{
    if (my_list.empty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    int max = my_list.at(0);
    for (int curr : my_list)
    {
        if (curr > max)
        {
            max = curr;
        }
    }
    cout << "The largest element: " << max << endl;
}

void display_smallest(const vector<int> &my_list)
{
    if (my_list.empty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    int smallest = my_list.at(0);
    for (int i = 1; i < my_list.size(); i++)
    {
        int curr = my_list.at(i);
        smallest = min(curr, smallest);
    }
    cout << "The smallest element: " << smallest << endl;
}

void add_number(vector<int> &my_list)
{
    int num{0};
    cout << "Enter only integer to add :" << endl;
    while (!(cin >> num))
    {
        cout << "Enter only integer try again:" << endl;
        cin.clear();
        cin.ignore();
    }

    my_list.push_back(num);
    cout << num << " added." << endl;
}
