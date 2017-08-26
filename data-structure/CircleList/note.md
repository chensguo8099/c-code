## 循环链表

单链表的局限

1. 单链表可以用于表示任意的线性关系
2. 有些线性关系是循环的，即没有队尾元素

循环链表的定义

将单链表中最后一个数据元素的next指针指向第一个元素

循环链表拥有单链表的所有操作
1. 创建链表
2. 销毁链表
3. 获取链表长度
4. 清空链表
5. 获取第pos个元素操作
6. 插入元素到位置pos
7. 删除位置pos处的元素

游标的定义

1. 在循环链表中可以定义一个“当前”指针，这个指针通常称为游标，可以通过这个游标（slider）来遍历链表中的所有元素

循环链表的新操作
1. 获取当前游标指向的数据元素
2. 将游标重置指向链表中的第一个数据元素
3. 将游标移动指向到链表中的下一个数据元素
4. 直接指定删除链表中的某个数据元素
CircleListNode* CircleList_Current(CircleList* list);
CircleListNode* CircleList_Reset(CircleList* list);
CircleListNode* CircleList_Next(CircleList* list);
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

小结
1. 循环链表只是在单链表的基础上做了一个加强
2. 循环链表可以完全取代单链表的使用
3. 循环链表的Next和Current操作可以高效的遍历链表中的所有元素

实现代码：https://github.com/chensguo8099/c-code/tree/master/data-structure/CircleList
