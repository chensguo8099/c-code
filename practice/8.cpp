#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}Node;

Node* initlist(int N){
	Node *phead = (Node*)malloc(sizeof(Node));
	phead->data = 0;
	phead->next = NULL;
	return phead;
}

Node* createlist(Node *head, int *num){
	Node* tmp = (Node*)malloc(sizeof(Node));
	head->next = tmp;
	tmp->data = *num;
	tmp->next = NULL;
	return tmp;
}

void clean(Node *pclean, int N){
	Node *tmp;
	tmp = pclean->next;
	for(int num = 0; num < N; num++){
		free(pclean);
		pclean = tmp;
		tmp = tmp->next;
	}
}

int main(){
	int N;
	int arr[1000];
	memset(arr, 0, sizeof(arr));

	Node *head = NULL;
	Node *tmp = NULL;
	while(scanf("%d", &N) != 0){
		for(int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+N);

		head = initlist(N);
		tmp = head;
		for(int j = 0; j < N; j++)
			tmp = createlist(tmp, &arr[j]);
		tmp = head->next;
		for(int k = 0; k < N; k++){
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		cout << endl;
		clean(head, N);
		head = NULL;
		tmp = NULL;
	}
	return 0;
}
