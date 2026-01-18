#include <iostream>
#include <thread>
#include <stack>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <utility>

template <typename T>
class ParallelStack
{
    std::stack<std::shared_ptr<T>> stk;
    mutable std::mutex m;

public:
    void push(T element)
    {
        std::lock_guard<std::mutex> lg(m);
        stk.push(std::make_shared<T>(std::move(element)));
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lg(m);

        if (stk.empty())
        {
            throw std::runtime_error("Stack is empty");
        }

        std::shared_ptr<T> res = stk.top();
        stk.pop();
        return res;
    }

    void pop(T &value)
    {
        std::lock_guard<std::mutex> lg(m);

        if (stk.empty())
        {
            throw std::runtime_error("Stack is empty");
        }

        value = std::move(*stk.top());
        stk.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lg(m);
        return stk.empty();
    }

    size_t size() const
    {
        std::lock_guard<std::mutex> lg(m);
        return stk.size();
    }
};



#include <iostream>
#include <vector>
#include <thread>
#include <cassert>
#include <atomic>


void test_parallel_stack() {
    ParallelStack<int> stack;
    const int num_threads = 8;        
    const int ops_per_thread = 1000;  
    std::atomic<int> successful_pops{0}; 

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    std::cout << "Starting test with " << num_threads << " producers and consumers..." << std::endl;

    for (int i = 0; i < num_threads; ++i) {
        producers.emplace_back([&stack, ops_per_thread, i]() {
            for (int j = 0; j < ops_per_thread; ++j) {
                stack.push(i * ops_per_thread + j);
            }
        });
    }

    // 2. יצירת תהליכונים שמוציאים מהמחסנית (Consumers)
    for (int i = 0; i < num_threads; ++i) {
        consumers.emplace_back([&stack, ops_per_thread, &successful_pops]() {
            for (int j = 0; j < ops_per_thread; ++j) {
                try {
                    stack.pop();
                    successful_pops++;
                } catch (const std::runtime_error&) {
                }
            }
        });
    }

    // המתנה לסיום כל התהליכונים
    for (auto& t : producers) t.join();
    for (auto& t : consumers) t.join();

    // 3. סיכום תוצאות
    int remaining = stack.size();
    std::cout << "--- Test Results ---" << std::endl;
    std::cout << "Total items pushed: " << (num_threads * ops_per_thread) << std::endl;
    std::cout << "Successful pops: " << successful_pops << std::endl;
    std::cout << "Items remaining in stack: " << remaining << std::endl;

    // בדיקת לוגיקה: מה שהוכנס חייב להיות או בחוץ או בפנים
    assert(successful_pops + remaining == num_threads * ops_per_thread);
    
    if (successful_pops + remaining == num_threads * ops_per_thread) {
        std::cout << "SUCCESS: Data consistency maintained!" << std::endl;
    } else {
        std::cout << "FAILURE: Data loss detected!" << std::endl;
    }
}

int main() {
    try {
        test_parallel_stack();
    } catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
    return 0;
}