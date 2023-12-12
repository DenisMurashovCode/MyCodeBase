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
pthread_mutex_t mutex;

void* calculatePartialSum(void* arg) {
int threadIndex = *(int*)arg;
int start = threadIndex * (size / numThreads);
int end = (threadIndex + 1) * (size / numThreads);

for (int i = start; i < end; i++) {
pthread_mutex_lock(&mutex);
partialSums[threadIndex] += numbers[i];
pthread_mutex_unlock(&mutex);
}

return NULL;
}

int calculateSumWithPthreads() {
pthread_t threads[numThreads];
int threadIndexes[numThreads];

for (int i = 0; i < numThreads; i++) {
threadIndexes[i] = i;
pthread_create(&threads[i], NULL, calculatePartialSum, &threadIndexes[i]);
}

int sum = 0;

for (int i = 0; i < numThreads; i++) {
pthread_join(threads[i], NULL);
sum += partialSums[i];
}

return sum;
}

int main() {
for (int i = 0; i < size; i++) {
numbers[i] = i + 1;
}

auto startTime = std::chrono::steady_clock::now();
int sum = calculateSumWithPthreads();
auto endTime = std::chrono::steady_clock::now();

std::cout << "Сумма чисел: " << sum << std::endl;
std::chrono::duration deltaTime = endTime - startTime;
std::cout << "Время выполнения: " << deltaTime.count() << " сек." << std::endl;

return 0;
}
