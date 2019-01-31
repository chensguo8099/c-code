/*fork写时拷贝*/
#include <stdio.h>
#include <unistd.h>

int main(){
	int i = 1;
	pid_t pid = fork();
	int j = 1;
	if(pid == 0)
	{
		i++;
		pid_t pid2 = fork();
		if(pid2 == 0)
		{
			i++;
			printf("cchild:i:%d\n", i);
		}
		else{
			i = 200;
			printf("fchild:i:%d\n", i);
		}
	}
	else{
		i++;
		printf("father:i:%d\n", i);
	}
	exit(0);
}
