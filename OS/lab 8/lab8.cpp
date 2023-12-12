#include <pthread.h>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <cstdlib>

int calculateSumSequentially(int* numbers, int size) {
int sum = 0;
for (int i = 0; i < size; i++) {
sum += numbers[i];
}
return sum;
}

int main() {
const int size = 1000000;
int numbers[size];
for (int i = 0; i < size; i++) {
numbers[i] = i + 1;
}

auto startTime = std::chrono::steady_clock::now();
int sum = calculateSumSequentially(numbers, size);
auto endTime = std::chrono::steady_clock::now();

std::cout << "Сумма чисел: " << sum << std::endl;
std::chrono::duration deltaTime = endTime - startTime;
std::cout << "Время выполнения: " << deltaTime.count() << " сек." << std::endl;

return 0;
}
