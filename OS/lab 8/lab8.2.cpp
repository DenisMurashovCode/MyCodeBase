#include <pthread.h>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstdlib>

const int numThreads = 4;
const int size = 1000000;
int numbers[size];
int partialSums[numThreads] = {0};
std::mutex mutex;

void calculatePartialSum(int threadIndex) {
int start = threadIndex * (size / numThreads);
int end = (threadIndex + 1) * (size / numThreads);

for (int i = start; i < end; i++) {
std::lock_guard lock(mutex);
partialSums[threadIndex] += numbers[i];
}
}

int calculateSumWithThreads() {
std::thread threads[numThreads];

for (int i = 0; i < numThreads; i++) {
threads[i] = std::thread(calculatePartialSum, i);
}

int sum = 0;

for (int i = 0; i < numThreads; i++) {
threads[i].join();
sum += partialSums[i];
}

return sum;
}

int main() {
for (int i = 0; i < size; i++) {
numbers[i] = i + 1;
}

auto startTime = std::chrono::steady_clock::now();
int sum = calculateSumWithThreads();
auto endTime = std::chrono::steady_clock::now();

std::cout << "Сумма чисел: " << sum << std::endl;
std::chrono::duration deltaTime = endTime - startTime;
std::cout << "Время выполнения: " << deltaTime.count() << " сек." << std::endl;

return 0;
}
