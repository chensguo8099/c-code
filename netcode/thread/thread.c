#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

struct luckyMoney {
	float money;
	int num;
};//红包

float *randMoney(float money, int num){
	float *p;
	int i;

	p = (float*)malloc(sizeof(float) * num);

	srand(time(NULL));
	for(i=0; i<num; i++){
		p[i] = rand()%num;
	}
	return p;
}//生成随机数X

void *pthread_func(void *lm){
	pthread_mutex_lock(&mutex);
	int i = 0, sum = 0;
	float *prandnum;
	prandnum = randMoney(((struct luckyMoney*)lm)->money,((struct luckyMoney*)lm)->num);

	for(i=0; i<((struct luckMoney*)lm)->num; i++){
		sum += prandnum[i];
	}
	//随机的红包金额 = 随机数X * ( 红包总金额 / 随机数总和X1+X2+...+Xn )
	printf("money:%f\n", prandnum[0]*((struct luckyMoney*)lm)->money/sum);

	prandnum = prandnum + 1;
	pthread_detach(pthread_self());
	pthread_mutex_lock(&mutex);

	return (void*)0;
}

int main(){
	int cval, jval;
	int *retval;
	struct luckyMoney *lm;
	lm->money = 100;
	lm->num = 20;

#if 0
	printf("红包金额：");
	scanf("%d", &(lm->money));
	printf("红包个数：");
	scanf("%d", &(lm->num));
#endif
	pthread_t tid[lm->num];

	int i;
	for(i=0; i<lm->num; i++){
		cval = pthread_create(&tid[i], NULL, pthread_func, (void *)lm);
		if(cval != 0)
		{
			printf("create pthread failed\n");
		}
	}
	pthread_exit(retval);
}
