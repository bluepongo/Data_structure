#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链表中的节点结构
typedef struct QNode {
	int data;
	struct QNode * next;
}QNode;

//创建链式队列的函数
QNode * initQueue() {
	//创建一个头结点
	QNode * queue = (QNode*)malloc(sizeof(QNode));
	//对头结点进行初始化
	queue->next = NULL;
	return queue;
}

//入队操作
QNode * enQueue(QNode * rear, int data) {
	//1、用节点包裹入队元素
	QNode * enElem = (QNode*)malloc(sizeof(QNode));
	enElem->data = data;
	enElem->next = NULL;
	//2、新节点与rear节点建立逻辑关系
	rear->next = enElem;
	//3、rear指向新节点
	rear = enElem;
	//返回新的rear，为后续新元素入队最准备
	return rear;
}

//出队操作
QNode * DeQueue(QNode * top, QNode * rear) {
	if (top->next == NULL) {
		printf("\n队列为空");
		return rear;
	}
	//1、
	QNode * p = top->next;
	printf("%d ", p->data);
	top->next = p->next;
	if (rear == p) {
		rear = top;
	}
	free(p);
	return rear;
}

int main()
{
	QNode * queue, *top, *rear;
	queue = top = rear = initQueue();//创建头结点
	//向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
	rear = enQueue(rear, 1);
	rear = enQueue(rear, 2);
	rear = enQueue(rear, 3);
	rear = enQueue(rear, 4);
	//入队完成，所有数据元素开始出队列
	rear = DeQueue(top, rear);
	rear = DeQueue(top, rear);
	rear = DeQueue(top, rear);
	rear = DeQueue(top, rear);
	rear = DeQueue(top, rear);

	system("pause");
	return EXIT_SUCCESS;
}