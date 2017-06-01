#include <stdio.h>
#include <unistd.h>
int value = 100;
int main(){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("child : %4d %p\n", value, &value);
	}
	else{
		value = 10;
		printf("parent : %4d %p\n", value, &value);
	}
	
	return 0;
}
