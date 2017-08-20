#include <stdio.h>
#include <malloc.h>
#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

//创建头结点
LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));

	if(ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}
	return ret;//返回指向头结点的指针
}

void LinkList_Destroy(LinkList* list)
{
	free(list);
}

void LinkList_Clear(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;

	if(sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
	}
}

int LinkList_Length(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = -1;

	if(sList != NULL)
		ret = sList->length;

	return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if(ret)
	{
		LinkListNode* current = (LinkListNode*)list;
		for(i=0; (i<pos) && current->next != NULL; i++)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;

		sList->length++;
	}
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret = NULL;
	int i = 0;

	if((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		LinkListNode* current = (LinkListNode*)sList;

		for(i = 0; i<pos; i++)
			current = current->next;

		ret = current->next;
	}
	return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret = NULL;
	int i = 0;

	if((sList != NULL) && (pos >= 0) && (pos < sList->length))
	{
		LinkListNode* current = (LinkListNode*)list;

		for(i=0; i<pos; i++)
			current = current->next;

		//删除操作（经典）
		ret = current->next;
		current->next = ret->next;

		sList->length--;
	}
	return ret;
}
