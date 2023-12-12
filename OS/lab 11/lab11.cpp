#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int bufferSize = 5; 

std::queue<int> buffer; 
std::mutex mutex; 
std::condition_variable producerCV, consumerCV; 
int itemCount = 0; 

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mutex);

        
        producerCV.wait(lock, [] { return itemCount < bufferSize; });

        
        int item = i + 1;

        
        buffer.push(item);
        ++itemCount;

        std::cout << "Производитель добавил: " << item << std::endl;

        
        consumerCV.notify_one();
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mutex);

       
        consumerCV.wait(lock, [] { return itemCount > 0; });

        
        int item = buffer.front();
        buffer.pop();
        --itemCount;

        std::cout << "Потребитель извлек: " << item << std::endl;

        
        producerCV.notify_one();
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}

