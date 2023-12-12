#include <stdio.h>
#include <pthread.h>

#define FALSE 0
#define TRUE 1
#define N 2 /* количество потоков */

int interested[N];
int turn;
char sh[6];

void enter_region(int process) {
int other = 1 - process;
interested[process] = TRUE;
turn = process;
while (turn == process && interested[other] == TRUE) ;
}

void leave_region(int process) {
interested[process] = FALSE;
}

void* Thread(void* pParams) {
int process = *(int*)pParams;
int counter = 0;
while (1) {
enter_region(process);
if (counter % 2) {
sh[0] = 'H';
sh[1] = 'e';
sh[2] = 'l';
sh[3] = 'l';
sh[4] = 'o';
sh[5] = '\0';
} else {
sh[0] = 'B';
sh[1] = 'y';
sh[2] = 'e';
sh[3] = '_';
sh[4] = 'u';
sh[5] = '\0';
}
leave_region(process);
counter++;
}
return NULL;
}

int main(void) {
pthread_t thread_id[N];
int process_ids[N] = {0, 1};

for (int i = 0; i < N; i++) {
pthread_create(&thread_id[i], NULL, &Thread, &process_ids[i]);
}

while (1) {
enter_region(0);
printf("%s\n", sh);
leave_region(0);
}

return 0;
}
