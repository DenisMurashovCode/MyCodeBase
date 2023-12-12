#include "iostream"
#include "fstream"
#include "string"
#include "csignal"



void ReadFile(const std::string& filePath) {
std::ifstream file(filePath);
if (file.is_open()) {
std::string line;
while (getline(file, line)) {
std::cout << line << std::endl;
}
file.close();
} else {
std::cout << "File not found" << std::endl;
}
}

void sigint_handler(int signum)
{
    exit(0);
}



int main(int argc, char* argv[]) {
const char* filePath = std::getenv("FILE_PATH");
if (filePath != nullptr) {
ReadFile(filePath);
} else if (argc > 1) {
ReadFile(argv[1]);
} else {
std::cout << "No file path provided" << std::endl;
}

signal(SIGINT, sigint_handler);

while (1) {
// Программа не завершает свою работу до получения сигнала остановки
}

return 0;
}


