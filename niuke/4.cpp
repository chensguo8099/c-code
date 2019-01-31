/*回文判断*/
#include <stdio.h>
#include <string.h>

int main(){
	char str[1005];
	int flag = 1;
	while(scanf("%s", str) != EOF){
		for(int i = 0; i < strlen(str)/2; i++){
			if(str[i] == str[strlen(str)-i-1])
				continue;
			else
				flag = 0;
		}
		if(flag == 0)
			printf("No!\n");
		else
			printf("Yes!\n");
		flag = 1;
	}
	return 0;
}
