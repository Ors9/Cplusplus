#include <iostream>
#include <thread>

void Test(){
    printf("Hello from Test\n");
}

void funcA(){
    printf("Hello from FuncA\n");
    std:: thread threadC(Test);
    threadC.join();
}

void funcB(){
    printf("Hello from FuncB\n");
}

int main(){

    std::thread threadA(funcA);
    std::thread threadB(funcB);

    threadA.join();
    threadB.join();

    printf("Hello from main\n");

    return 0;
}