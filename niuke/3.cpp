/*找位置*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str[105];
	int buf[105];
	int flag = 1;
	memset(buf, 0, sizeof(buf));

	while(scanf("%s", str) != EOF){
		for(int s = 0; s < strlen(str)-1; s++){
			if(buf[s] == 1)
				continue;
			flag = 1;
			for(int i = s + 1; i < strlen(str); i++){
				if(str[i] == str[s]){
					if(flag == 1){
						printf("%c:%d", str[s], s);
						flag = 0;
					}
					if(buf[i] != 1){
						printf(",%c:%d", str[i], i);
						buf[i] = 1;
					}
				}
			}
			if(flag == 0)
			printf("\n");
		}
	}
	return 0;
}
