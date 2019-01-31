## 单链表的局限
1. 单链表的结点都只有一个指向下一个结点的指针
2. 单链表的数据元素无法直接访问其前驱元素

逆序访问单链表中的元素是及其耗时的操作：
```
len = LinkList_Length(list);

for(i=len-1; len>=0; i--)
{
	LinkListNode* p = LinkList_Get(list, i);

	// 访问数据元素p中的数据
	// ...
}
```

## 单链表的改进

### 双向链表的定义
在单链表的节点中增加一个指向前驱的pre指针

### 双向链表拥有单链表的所有操作
1. 创建链表
2. 销毁链表
3. 获取链表长度
4. 清空链表
5. 获取第pos个元素操作
6. 插入元素到位置pos
7. 删除位置pos处的元素

### 双向链表的新操作(使用游标)
1. 获取当前游标指向的数据元素
2. 将游标重置指向链表中的第一个数据元素
3. 将游标移动指向到链表中的下一个数据元素
4. 将游标移动指向到链表中的上一个数据元素
5. 直接指定删除链表中的某个数据元素

DLinkListNode* DLinkList_Current(DLinkList* list);

DLinkListNode* DLinkList_Reset(DLinkList* list);

DLinkListNode* DLinkList_Next(DLinkList* list);

DLinkListNode* DLinkList_Pre(DLinkList* list);

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);


### 小结
双向链表在单链表的基础上增加了指向前驱的指针
功能上双向链表可以完全取代单链表的使用
循环链表的Next, Pre和Current操作可以高效的遍历链表中的所有元素
