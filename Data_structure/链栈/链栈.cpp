﻿#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//链表中的节点结构
typedef struct lineStack {
	int data;
	struct lineStack * next;
}lineStack;

//stack为当前的链栈，a表示入栈元素
lineStack * push(lineStack * stack, int a) {
	//创建存储新元素的节点
	lineStack * line = (lineStack*)malloc(sizeof(lineStack));
	line->data = a;
	//新节点与头结点建立逻辑关系
	line->next = stack;
	//更新头指针的指向
	stack = line;
	return stack;
}

//栈顶元素出栈
lineStack * pop(lineStack * stack) {
	if (stack) {
		//声明一个新指针指向栈顶节点
		lineStack * p = stack;
		//更新头指针
		stack = stack->next;
		printf("出栈元素：%d\n", p->data);
		if (stack) {
			printf("新栈顶元素：%d\n", stack->data);
		}
		else {
			printf("栈空\n");
		}
		free(p);
	}
	else {
		printf("栈内没有元素\n");
		return stack;
	}
	return stack;
}

int main()
{
	lineStack * stack = NULL;
	stack = push(stack, 1);
	stack = push(stack, 2);
	stack = push(stack, 3);
	stack = push(stack, 4);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);

	system("pause");
	return EXIT_SUCCESS;
}