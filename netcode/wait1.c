#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid, tmp;
	pid = fork();
	int i = 0;
	int status = -1;
	if(pid < 0)
		printf("error ocurred!\n");
	else if(pid == 0)
		printf("child : my pid is : %d\n", getpid());
	else{
		tmp = wait(&status);
		printf("parent : i catched a child pid with %d\n", tmp);
	}
	return 0;
}
