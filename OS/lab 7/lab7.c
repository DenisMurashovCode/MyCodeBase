#define _CRT_SECURE_NO_WARNINGS

#define LIBRARY_PATH "./list.so"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>




char* getProcessID() {
pid_t pid = getpid();
char* str = (char*) malloc(sizeof(char) * 10);
sprintf(str, "%d", pid);
return str;
}




void printFileContent(const char* filename) {
FILE* file = fopen(filename, "r");
if (file) {
char ch;
while ((ch = fgetc(file)) != EOF) {
putchar(ch);
}
fclose(file);
} else {
printf("Ошибка открытия файла: %s\n", filename);
}
}

int main() {

void* handle = dlopen("./list.so", RTLD_LAZY);
if (!handle) {
fprintf(stderr, "Ошибка загрузки библиотеки: %s\n", dlerror());
return 1;
}

printf("Библиотека успешно загружена!\n");




char* pid = getProcessID();
char mapsFilename[100];
sprintf(mapsFilename, "/proc/%s/maps", pid);
free(pid);

printf("Содержимое файла %s:\n", mapsFilename);
printFileContent(mapsFilename);


dlclose(handle);

printf("Библиотека успешно выгружена!\n");

printf("Содержимое файла %s после выгрузки библиотеки:\n", mapsFilename);
printFileContent(mapsFilename);

return 0;
}
