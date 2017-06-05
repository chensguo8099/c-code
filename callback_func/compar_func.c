/*
 * 在一个单链表中查找一个指定值的函数，它的参数是一个指向链表第一节点
 * 的指针，一个指向我们需要查找的值的指针和一个函数指针，它所指向的函数
 * 用于比较存储于链表中的类型的值。
 *
 * 来源：<<C和指针>>
 */

#include <stdio.h>
#include "node.h"

int compare_ints(void const *a, void const *b){
	if(*(int *)a == *(int *)b)
		return 0;
	else 
		return 1;
}

Node*
search_list(Node *node, void const *value,
	int (*compare)(void const *, void const *)){
	while(node != NULL){
		if(compare(&node->value, value) == 0)
			break;
		node = node->link;
	}
	return node;
}
