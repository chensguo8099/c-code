#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t fpid;
	int count = 0;
	fpid = fork();
	if(fpid < 0)
		printf("error in fork!");
	else if(fpid == 0){
		printf("i am the child process, my process id is %d\n", getpid());
		printf("我是爹的儿子\n");
		count++;
	}
	else{
		printf("i am the parent process, my process id is %d\n", getpid());
		printf("我是孩子他爹\n");
		count++;
	}
	printf("统计结果是: %d\n", count);
	return 0;
}
