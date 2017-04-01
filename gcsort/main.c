#include "gcsort.h"
#include "generate_data.h"

int main(int argc, char **argv){
	SoftArray *tmp = NULL;
	int start = 0;	//argv[1]为随机数总数argv[2]随机数最大值

	tmp = generate_data(atoi(argv[1]), atoi(argv[2]));//创建随机数

	msort(tmp, atoi(argv[1]), compar_num);//随机化产生数并且由小到大排序

	for(start = 0; start < atoi(argv[1]); start++)
		printf("%d ", tmp->array[start]);

	return 0;
}
