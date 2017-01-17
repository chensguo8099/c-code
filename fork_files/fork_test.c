#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	printf("start fork\n");
//  printf("start fork");
	pid = fork();
	if(pid < 0)
		printf("error fork\n");
	if(pid == 0)
		printf("i am child process, my id:%d\n", getpid());
	if(pid > 0)
		printf("i am parent process, my id:%d\n", getpid());
	printf("process exit\n");

	return 0;
}
