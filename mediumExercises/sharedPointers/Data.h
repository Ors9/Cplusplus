#ifndef DATA_H
#define DATA_H

#include <memory>
#include <vector>

class Data
{

private:
    int data;

public:
    Data(); // constructor
    Data(int data);// constructor
   static std::unique_ptr<std:: vector< std::shared_ptr<Data> >> make();
   static void fill(std::vector<std::shared_ptr<Data>> & my_list, int num);
   static void display(const std:: vector< std::shared_ptr<Data>> & my_list);
   int getData();
    ~Data(); //Destructor
};

#endif // DATA_H