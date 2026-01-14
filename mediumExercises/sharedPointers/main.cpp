#include <iostream>
#include "Data.h"


int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Data>>> vec_ptr;
    vec_ptr = Data::make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    Data::fill(*vec_ptr, num);
    Data::display(*vec_ptr);
    return 0;
}
