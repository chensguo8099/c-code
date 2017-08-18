#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

struct Value
{
	LinkListNode header;
	int v;
};
/*
struct value
{
	struct _tag_LinkListNode header;
	int v;
}
*/
int main(int argc, char* argv[])
{
	int i = 0;
	LinkList* list = LinkList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	LinkList_Insert(list, (LinkListNode*)&v1, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v2, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v3, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v4, LinkList_Length(list));
	LinkList_Insert(list, (LinkListNode*)&v5, LinkList_Length(list));

	for(i=0; i < LinkList_Length(list); i++)
	{
		struct Value* num1 = (struct Value*)LinkList_Get(list, i);
		//struct Value* num1 = (struct Value*)LinkList_Get(list, LinkList_Length(list)-1);
		printf("%d\n", num1->v);
	}

	while(LinkList_Length(list) > 0)
	{
		struct Value* num2 = (struct Value*)LinkList_Delete(list, LinkList_Length(list)-1);
		//struct Value* num2 = (struct Value*)LinkList_Delete(list, 0);
		printf("%d\n", num2->v);
	}
	LinkList_Destroy(list);
	return 0;
}
