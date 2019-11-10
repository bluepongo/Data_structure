#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//入队操作
int enQueue(int * a, int rear, int data) {
	a[rear] = data;
	rear++;
	return rear;
}

//出队操作
void deQueue(int * a, int top, int rear) {
	//如果front==rear，表示队列为空
	while (top != rear) {
		printf("出队元素为：%d\n", a[top]);
		top++;
	}
}

int main()
{
	int a[100];
	int top, rear;
	//设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
	top = rear = 0;
	//入队
	rear = enQueue(a, rear, 1);
	rear = enQueue(a, rear, 2);
	rear = enQueue(a, rear, 3);
	rear = enQueue(a, rear, 4);
	//出队
	deQueue(a, top, rear);

	system("pause");
	return EXIT_SUCCESS;
}