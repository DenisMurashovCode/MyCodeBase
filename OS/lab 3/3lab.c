#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
void oldman(){
fprintf(stdout, "I'm not yet dead! ID is %i\n", (int) getpid());
}
void recreation(){
fprintf(stdout, "Who I am? ID is %i\n", (int) getpid());
}

int main(){
pid_t child_pid, parent_pid;
int i=0;
parent_pid=(int) getpid();
child_pid=fork();

while(i++<5)
if(child_pid!=0){
oldman();
usleep(100);
if(i==3) kill(parent_pid,SIGTERM);
}
else{
recreation();
usleep(100);
}
if(child_pid!=0) pause();
return 0;
}
