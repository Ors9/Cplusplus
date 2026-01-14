#include "Data.h"

#include <iostream>

Data::Data()
    : data{0}
{
    std::cout << "constructor" << std::endl;
}

Data::Data(int data)
    : data{data}
{
    std::cout << "constructor" << std::endl;
}

Data::~Data()
{
    std::cout << "destructor (" << getData() << ")" << std::endl;
}

std::unique_ptr<std::vector<std::shared_ptr<Data>>> Data::make()
{
    std::unique_ptr<std::vector<std::shared_ptr<Data>>> obj = std::make_unique<std::vector<std::shared_ptr<Data>>>();
    return obj;
}

void Data::fill(std::vector<std::shared_ptr<Data>> &my_list, int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << "Enter data point [" << i + 1 << "] :" << std::endl;

        int data;
        std::cin >> data; // assume valid input

        std::shared_ptr<Data> ptr_data = std::make_shared<Data>(data);

        my_list.push_back(ptr_data);
    }
}

int Data::getData()
{
    return data;
}

void Data::display(const std::vector<std::shared_ptr<Data>> &my_list)
{
    for (const std::shared_ptr<Data> &curr : my_list)
    {
        std::cout << curr->getData() << std::endl;
    }
}