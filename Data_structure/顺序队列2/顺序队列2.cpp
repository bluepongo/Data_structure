#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

//入队操作
int enQueue(int * a, int top, int rear, int data) {
	//添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储
	//如果rear+1和top重合，则表示数组已满
	if ((rear + 1) % max == top) {
		printf("空间已满\n");
		return rear;
	}
	a[rear % max] = data;
	rear++;
	return rear;
}

//出队操作
int deQueue(int * a, int top, int rear) {
	//如果front==rear，表示队列为空
	if (top == rear % max) {
		printf("队列为空\n");
		return top;
	}
	printf("%d\n", a[top]);
	//top不再直接+1,而是+1后同max进行比较，如果=max，则直接跳转到a[0]
	top = (top + 1) % max;
	return top;
}

int main()
{
	int a[max];
	int top, rear;
	//设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
	top = rear = 0;
	//入队
	rear = enQueue(a, top, rear, 1);
	rear = enQueue(a, top, rear, 2);
	rear = enQueue(a, top, rear, 3);
	rear = enQueue(a, top, rear, 4);
	//出队
	top = deQueue(a, top, rear);
	//再入队
	rear = enQueue(a, top, rear, 5);
	//再出队
	top = deQueue(a, top, rear);
	//再入队
	rear = enQueue(a, top, rear, 6);
	//再出队
	top = deQueue(a, top, rear);
	top = deQueue(a, top, rear);
	top = deQueue(a, top, rear);
	top = deQueue(a, top, rear);;

	system("pause");
	return EXIT_SUCCESS;
}