#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//入栈操作
//元素elem进栈，a为数组，top值为当前栈的栈顶位置
int push(int * a, int top, int elem) {
	a[++top] = elem;
	return top;
}

//出栈操作
int pop(int * a, int top) {
	if (top == -1) {
		printf("空栈\n");
		return -1;
	}
	printf("弹栈元素：%d\n", a[top]);
	top--;
	return top;
}

int main()
{
	int a[100];
	int top = -1;
	top = push(a, top, 1);
	top = push(a, top, 2);
	top = push(a, top, 3);
	top = push(a, top, 4);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);

	system("pause");
	return EXIT_SUCCESS;
}