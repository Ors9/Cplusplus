#include <thread> 
#include <iostream>
#include <array>
#include <mutex>

std::mutex coutMutex; 

void printer(int i) {
    std::lock_guard<std::mutex> lock(coutMutex); 
    std::cout << "Hello from printer-" << i << "-" << std::endl;
}

int main(){

    std::array<std:: thread , 10> myThreads;

    for(int i = 0 ; i < myThreads.size() ; i++){
        myThreads.at(i) = std::thread(printer,i);
    }

    std::thread lambadaT([] {
        std::lock_guard<std::mutex> lock(coutMutex); 
        printf("Hello From lambda\n");
    });

    for(int i = 0 ; i < myThreads.size() ; i++){
        myThreads.at(i).join();
    }
    lambadaT.join();


    std::cout << "Hello from main" << std::endl;
    

    return 0;
}