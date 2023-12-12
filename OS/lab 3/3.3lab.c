#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
pid_t child_pid_1 = fork();

if (child_pid_1 == 0) {

pid_t child_pid_2 = fork();


if (child_pid_2 == 0) {
printf ("Child 2 (PID %i\n" , getpid() );
} else if (child_pid_2 > 0) {
printf ("Parent 1 (PID %i\n" , getpid());
wait(NULL); 
}

} else if (child_pid_1 > 0) {

pid_t child_pid_3 = fork();

if (child_pid_3 == 0) {
fprintf ( stdout,"Child 3 (PID %i\n" , (int)getpid());
} else if (child_pid_3 > 0) {
fprintf ( stdout,"Parent 2 (PID %i\n" , (int)getpid());
wait(NULL); 
}
}
	while(1){}
return 0;
	
}
