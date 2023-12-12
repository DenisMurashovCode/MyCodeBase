#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


int main() {
pid_t pid1, pid2, pid3;


pid1 = fork();

if (pid1 == 0) {
fprintf( stdout,"Child process 1 (PID: %i\n" , (int)getpid());
    execl("/home/denis/Рабочий стол/ОС/lab 4/H1", "./H1", NULL);
} else {


pid2 = fork();

if (pid2 == 0) {
fprintf( stdout,"Child process 2 (PID: %i\n" ,(int)getpid());
    execl("/home/denis/Рабочий стол/ОС/lab 4/H2", "./H2", NULL);
} else {


pid3 = fork();

if (pid3 == 0) {
fprintf(stdout, "Child process 3 (PID: %i\n" , (int)getpid());
    execl("/home/denis/Рабочий стол/ОС/lab 4/H3", "./H3", NULL);
} else {
fprintf(stdout, "Parent process (PID: %i\n" , (int)getpid());
fprintf(stdout, "Child processes: %d%s%d%s%d\n" , pid1 , ", " , pid2 , ", " , pid3);
}
}
}

return 0;
} 