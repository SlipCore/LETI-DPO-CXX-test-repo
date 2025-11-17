#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>
#include <iostream>

// Потокобезопасная очередь
class ThreadSafeQueue {
    std::queue<int> queue_;
    std::mutex mutex_;
    std::condition_variable condition_;
    size_t capacity_;
public:

    ThreadSafeQueue(size_t capacity) : capacity_(capacity) {};

    void push(int item) {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] {return queue_.size() < capacity_; });
        queue_.push(item);
        condition_.notify_one();
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        condition_.wait(lock, [this] { return !queue_.empty(); });
        int result = queue_.front();
        queue_.pop();
        condition_.notify_one();
        return result;
    }

    bool empty() {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }
};

int main() {
    ThreadSafeQueue q(2);

    std::thread producer([&q]{
        for (int i = 0; i < 10; ++i) {
            q.push(i);
            std::cout << "Produced-1: " << i << std::endl;
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    std::thread producer2([&q]{
        for (int i = 0; i < 10; ++i) {
            q.push(i);
            std::cout << "Produced-2: " << i << std::endl;
            // std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::thread consumer([&q]{
        for (int i = 0; i < 10; ++i) {
            int value = q.pop();
            std::cout << "Consumed-1: " << value << std::endl;
        }
    });

    std::thread consumer2([&q]{
        for (int i = 0; i < 10; ++i) {
            int value = q.pop();
            std::cout << "Consumed-2: " << value << std::endl;
        }
    });

    producer.join();
    producer2.join();
    consumer.join();
    consumer2.join();
    
    return 0;
}
