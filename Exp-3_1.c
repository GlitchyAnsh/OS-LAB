#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
	printf("Welcome to CSE dept. MIET\n");
}

void parentProcess(){
	printf("Main task in execution\n");
}

int main(){
	pid_t pid = fork();
	if (pid == 0){
		childTask();
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0){
		wait(NULL);
	}
	return EXIT_SUCCESS;
} 
 23  
Exp-3/Experiment-3_2.c
@@ -0,0 +1,23 @@
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	for (int i=1; i<=5; i++){
		pid_t pid = fork();
		if (pid == 0){
			printf("Child PPID: %d PID: %d\n", getppid(), getpid());
			exit(0);
		}
		else if (pid > 0){
			printf("Parent PID: %d\n", getpid());
			printf("Waiting for Child process to finish.\n");
			wait(NULL);
			printf("Child process finished.\n");
		}
	}
	return EXIT_SUCCESS;
} 
