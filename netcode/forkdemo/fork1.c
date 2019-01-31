#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int max = 10;

int main(){
	int i = 0;
	pid_t pid = fork();
	if(pid == 0){
		for(i; i < max; i++){
			printf("child : %d\n", i);
			usleep(900);
		}
	}
	else{
		for(i = 5; i < max; i++){
			printf("parent : %d\n", i);
			sleep(1);
		}
	}
	return 0;
}
