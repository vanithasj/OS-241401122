#include <stdio.h>
#include <unistd.h>
int main(){
	if(fork() == 0){
		printf("This is child processes\n");
	}
	else{
		printf("This is parent processes\n");
	}
	fork();
	fork();
	fork();
	printf("PID: %d\n",getpid());
	return 0;
}
