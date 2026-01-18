#include <queue>
#include <memory>
#include <iostream>
#include <mutex>
#include <condition_variable>

template <typename T>
class ParallelQueue
{
public:
    std::queue<std::shared_ptr<T>> my_q;
    std::condition_variable cv;
    mutable std::mutex m;

    ParallelQueue() {};
    ParallelQueue(const ParallelQueue &) = delete;
    ParallelQueue &operator=(const ParallelQueue &) = delete;

    void Push(T value)
    {
        std::lock_guard<std::mutex> lg(m);
        my_q.push(std::make_shared<T>(std::move(value)));
        cv.notify_one();
    }

    std::shared_ptr<T> Pop()
    {
        std::lock_guard<std::mutex> lg(m);
        if (my_q.empty())
        {
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> to_pop(my_q.front());
        my_q.pop();
        return to_pop;
    }
    void wait_pop(T &value)
    {
        std::unique_lock<std::mutex> lu(m);
        cv.wait(lu, [this]
                { return !my_q.empty(); });
        value = std::move(*my_q.front());
        my_q.pop();
    }
    std::shared_ptr<T> wait_pop()
    {
        std::unique_lock<std::mutex> lu(m);
        cv.wait(lu, [this]
                { return !my_q.empty(); });
        std::shared_ptr<T> ref = std::move(my_q.front());
        my_q.pop();
        return ref;
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lg(m);
        return my_q.empty();
    }
    size_t size() const
    {
        std::lock_guard<std::mutex> lg(m);
        return my_q.size();
    }
};




#include <thread>
#include <chrono>
#include <string>
#include <vector>

int main() {
    ParallelQueue<std::string> pq;

  
    std::thread consumer([&pq]() {
        std::cout << "[Consumer] Starting... waiting for data." << std::endl;
        for (int i = 0; i < 5; ++i) {
     
            std::shared_ptr<std::string> data = pq.wait_pop();
            std::cout << "[Consumer] Got: " << *data << " (Size: " << pq.size() << ")" << std::endl;
        }
        std::cout << "[Consumer] Finished." << std::endl;
    });


    std::thread producer([&pq]() {
        std::vector<std::string> messages = {"Hello", "from", "the", "other", "side"};
        for (auto& msg : messages) {
            std::this_thread::sleep_for(std::chrono::milliseconds(800)); 
            std::cout << "[Producer] Pushing: " << msg << std::endl;
            pq.Push(std::move(msg)); 
        }
    });

    producer.join();
    consumer.join();

    std::cout << "All done. Final queue size: " << pq.size() << std::endl;
    return 0;
}